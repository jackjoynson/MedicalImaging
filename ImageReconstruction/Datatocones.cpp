#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
int numbdetectors;
	cout << "Please enter the number of detectors" << endl;
	cin >> numbdetectors;
	cout << numbdetectors << endl;
	
int pos[numbdetectors][3];
double x=0;
double y=0;
double z=0;
	for(int i=1; i <= numbdetectors; i++){
		cout << "Enter x coordinate of detector " << i << endl;
		cin >> x;
		pos[i][0]=x;
		cout << "Enter y coordinate of detector " << i << endl;
		cin >> y;
		pos[i][1]=y;
		cout << "Enter z coordinate of detector " << i << endl;
		cin >> z;
		pos[i][2]=x;
}
//cout << pos[2][1] << endl ;
return 0;
}
