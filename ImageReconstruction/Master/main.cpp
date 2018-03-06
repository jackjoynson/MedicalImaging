#include "GetUserInputs.h"
#include "FileToData.h"
#include "FilterEvents.h"
#include "GenerateMatrix.h"
#include "MatrixToFile.h"
#include "ConesToEllipse.h"
#include "ReadCCData.h"

#include <string>
#include <vector>

int main()
{
	cout << "Enter 1 to use Coinc Checker calibrated output. Enter 0 to use raw files:" << endl;
	int tempUseCC;
	cin >> tempUseCC;
	bool useCCData = (tempUseCC == 1) ? true : false;

    GetUserInputs GUI(useCCData);
	vector<std::string> files = GUI.GetFilePaths();
	vector<DetectorType> detectors = GUI.GetDetectors();
	double imageDistanceHeight = GUI.GetImageHeight();
	double imageSizeWidth = GUI.GetImageSizeWidth();


	vector<Cone> cones;
	if (useCCData)
	{
		//Use Coinc checker data

		string file;
		cout << "Please enter the Coinc Checker output file - i.e the input file (Keep short!)" << endl;
		cin >> file;

		cout << "Running..." << endl;

		ReadCoincData RCD;
		cones = RCD.GetCones(file, detectors, GUI.GetEnergy(), imageDistanceHeight, GUI.HasHeaders());
	}
	else 
	{
		//Or use original method
		FileToData FTD(GUI.HasHeaders());
		vector<EventEntry> scatteringEvents = FTD.GetData(files, detectors, true);
		cout << "Found " << scatteringEvents.size() << " scatter events within limits.." << endl;
		vector<EventEntry> absorbEvents = FTD.GetData(files, detectors, false);
		cout << "Found " << absorbEvents.size() << " absorb events within limits.." << endl;


		FilterEvents EventFilterer;
		cones = EventFilterer.GetCones(scatteringEvents, absorbEvents, detectors, GUI.GetEnergy(), imageDistanceHeight, GUI.GetTolerance());
	}

	cout << "Generated " << cones.size() << " cones." << endl;

	Vector3D pointOnPlane(0, 0, imageDistanceHeight);

	ConesToEllipse ellipseGenerator(pointOnPlane, cones);
	vector<Ellipse> ellipses = ellipseGenerator.getEllipses();
	cout << "Generated " << ellipses.size() << " ellipses." << endl;

	GenerateMatrix matrixGenerator;
	vector<vector<int> > matrix = matrixGenerator.GetValues(ellipses, imageSizeWidth, imageSizeWidth, GUI.GetPixels());
	cout << "Matrix generated. Saving..." << endl;

	MatrixToFile matrixSaver;
	string fileName = matrixSaver.Save(matrix);
	cout << "Results saved to " << fileName << endl;


	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
