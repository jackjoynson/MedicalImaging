#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"
#include "GenerateMatrix.h"
#include "MatrixToFile.h"
#include "ConesToEllipse.h"

#include <string>
#include <vector>

int main()
{
    GetUserInputs GUI;
	vector<std::string> files = GUI.GetFilePaths();
	vector<DetectorType> detectors = GUI.GetDetectors();
	double imageDistanceHeight = GUI.GetImageHeight();
	double imageSizeWidth = GUI.GetImageSizeWidth();

	FileToData FTD(GUI.IsSimulation());
	vector<EventEntry> scatteringEvents = FTD.GetData(files, detectors, true);
	vector<EventEntry> absorbEvents = FTD.GetData(files, detectors, false);


	GenerateCones coneGenerator;
	vector<Cone> cones = coneGenerator.GetCones(scatteringEvents, absorbEvents, detectors, GUI.GetEnergy(), imageDistanceHeight, GUI.GetTolerance());
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
