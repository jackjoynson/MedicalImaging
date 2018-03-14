#ifndef MatrixToFile_h
#define MatrixToFile_h

#include <vector>
#include <string>

using namespace std;

class MatrixToFile
{
public:
	MatrixToFile();
	string Save(vector<vector<int> > matrix);
};

#endif