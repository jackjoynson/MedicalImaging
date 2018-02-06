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
	double sourceEnergy = GUI.GetEnergy();
	double imageDistanceHeight = GUI.GetImageHeight();
	double imageSizeWidth = GUI.GetImageSizeWidth();
	double imageSizePixels = GUI.GetPixels();

	FileToData FTD;
	vector<EventEntry> scatteringEvents = FTD.GetData(files, detectors, true);
	vector<EventEntry> absorbEvents = FTD.GetData(files, detectors, false);


	GenerateCones coneGenerator;
	vector<Cone> cones = coneGenerator.GetCones(scatteringEvents, absorbEvents, detectors, sourceEnergy, imageDistanceHeight);


	Vector3D pointOnPlane(0, 0, imageDistanceHeight);

	ConesToEllipse ellipseGenerator(pointOnPlane, cones);
	vector<Ellipse> ellipses = ellipseGenerator.getEllipses();
	

	GenerateMatrix matrixGenerator;
	vector<vector<int> > matrix = matrixGenerator.GetValues(ellipses,imageSizeWidth, imageSizeWidth, imageSizePixels);


	MatrixToFile matrixSaver;
	string fileName = matrixSaver.Save(matrix);
	cout << "Results saved to " << fileName << endl;


	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
