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
	vector<std::string> files = GUI.getFilePaths();
	vector<DetectorType> detectors = GUI.getDetectors();
	double sourceEnergy = GUI.GetEnergy();
	double imageHeight = GUI.GetImageHeight();

	FileToData FTD;
	vector<EventEntry> scatteringEvents = FTD.GetData(files, detectors, true);
	vector<EventEntry> absorbEvents = FTD.GetData(files, detectors, false);


	GenerateCones coneGenerator;
	vector<Cone> cones = coneGenerator.GetCones(scatteringEvents, absorbEvents, detectors, sourceEnergy, imageHeight);


	Vector3D pointOnPlane(0, 0, imageHeight);

	ConesToEllipse ellipseGenerator(pointOnPlane, cones);
	vector<Ellipse> ellipses = ellipseGenerator.getEllipses();
	

	GenerateMatrix matrixGenerator;
	vector<vector<int> > matrix = matrixGenerator.GetValues(ellipses);


	MatrixToFile matrixSaver;
	string fileName = matrixSaver.Save(matrix);
	cout << "Results saved to " << fileName << endl;


	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
