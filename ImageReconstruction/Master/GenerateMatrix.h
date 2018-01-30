#ifndef GenerateMatrix_h
#define GenerateMatrix_h

#include "Ellipse.h"


#include <vector>

class GenerateMatrix
{
public:
	GenerateMatrix();
	vector<vector<int> > GetValues(vector<Ellipse> ellipses);
};

#endif