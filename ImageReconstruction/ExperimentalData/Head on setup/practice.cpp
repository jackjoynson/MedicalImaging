#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	ifstream myfile;
	myfile.open("data5_ch000.txt");

	std::ifstream infile("data5_ch000.txt");
	std::string line;
	while (std::getline(infile,line))
{
	std::istringstream iss(line);
	int t, e;
	if (!(iss >> t >> e)) {break; }
	cout << t;
}
	//ifstream input;
	//input.open("data5_ch000.txt");
	
	

return 0;
}
