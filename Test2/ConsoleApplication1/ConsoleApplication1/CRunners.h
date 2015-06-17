//I affirm that all code given below was written solely by me, Michael Zeng, 
//and that any help I received adhered to the rules stated for this exam.

#ifndef CRUNNERS_H
#define CRUNNERS_H
#include "Runner.h"
#include <algorithm>

class CRunners
{

public:
	CRunners();
	CRunners(string fName, string Compname, double mile, string location, string org);
	CRunners(CRunners &runnersObject); //copy constructor
	~CRunners();
	int getTotalRuners();
	void setRunnersFile(string fileName);
	void readRunnersAndSort();
	void outPutRunnersFile();

private:
	vector<Runner> whitePaceRunners;
	vector<Runner> yellowPaceRunners;
	vector<Runner> greenPaceRunners;
	vector<Runner> orangePaceRunners;
	vector<Runner> bluePaceRunners;
	vector<Runner> lilacPaceRunners;
	vector<Runner> redPaceRunners;
	string filename;
	string nameofCompetition; //The Lilac Bloomsday
	double marathondistance;//7.46
	string runLocation;//Downtown Spokane
	string orgnizer; //Bloomsday
	int totalRunners;

	void constructRunnerlist();
	void Vectorsort();
};

#endif