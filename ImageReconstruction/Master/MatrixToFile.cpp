#include "MatrixToFile.h"

#include <ctime>
#include <fstream>
#include <iterator>


MatrixToFile::MatrixToFile(){}

string MatrixToFile::Save(vector<vector<int> > matrix)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S", timeinfo);
	string fileName(buffer);


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