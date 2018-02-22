#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"
#include "GetCoinc.h"

#include <string>
using namespace std;




int main()
{

	cout << "Energy histogram generator" << endl;

	GetUserInputs GUI;
	vector<std::string> files = GUI.getFilePaths();


	cout << "Enter the energy bin size:" << endl;
	double energyBinSize;
	cin >> energyBinSize;

	cout << "Enter the number of bins:" << endl;
	int numBins;
	cin >> numBins;

	cout << "Enter 1 if the data file has headers: " << endl;
	int tempHeaders;
	cin >> tempHeaders;
	bool lookForHeader = (tempHeaders == 1) ? true : false;

	cout << "Enter 1 if the data file is Tab/space delimited: " << endl;
	int tempIsTab;
	cin >> tempIsTab;
	bool isTab = (tempIsTab == 1) ? true : false;

	cout << "Enter a valid file name to output to:" << endl;
	string fileName;
	cin >> fileName;

	FileToData FTD;

	vector<long> bins;
	bins.resize(numBins);

	vector<EventEntry> events = FTD.GetData(files, 0, lookForHeader, isTab);
	cout << "File has " << events.size() << " events. Binning..." << endl;

	for (int i = 0; i < events.size(); i++)
	{
		int binNum = floor((double)events[i].GetEnergy() / energyBinSize);
		if (binNum >= 0 && binNum < numBins)		
			bins[binNum]++;
		else cout << "Invalid bin value '" << binNum << "' from event " << i << " which had energy: " << events[i].GetEnergy() << endl;
	}



	ofstream output(fileName);
	output << "Bin number,Count," << '\n';
	for (int i = 0; i < numBins; i++)
		output << i << ',' << bins[i] << ',' << '\n';
	
	output.close();






	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
