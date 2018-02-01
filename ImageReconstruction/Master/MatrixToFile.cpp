#define _CRT_SECURE_NO_WARNINGS
#include "MatrixToFile.h"

#include <ctime>
#include <fstream>
#include <iterator>
#include <sstream>


MatrixToFile::MatrixToFile(){}

string MatrixToFile::Save(vector<vector<int> > matrix)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d%m%Y_%I%M%S", timeinfo);

	stringstream fileNameSS;
	fileNameSS << string(buffer) << ".txt";

	string fileName = fileNameSS.str();


	ofstream outFile(fileName);
	
	for (int y = 0; y < matrix.size(); y++)
	{
		for (int x = 0; x < matrix.size(); x++)	
			outFile << matrix[x][y] << ",";
		
		outFile << '\n';
	}


	outFile.close();

	return fileName;
}