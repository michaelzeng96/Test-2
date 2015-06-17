//I affirm that all code given below was written solely by me,
//Michael Zeng, and that any help I received adhered to the rules stated for this exam. 

#include "CRunners.h"

// We need this function to define how to sort
// the vector. We will pass this function into the
// third parameter and it will tell it to sort ascendingly.
// Runner object comparison based on Runner pace
bool ascend_runner_pace(Runner& firstRunnerObj, Runner& secondRunnerObj)
{

	if (firstRunnerObj.get_pace()<secondRunnerObj.get_pace())
		return true;
	else
		return false;
}


CRunners::CRunners()
{
	filename = "";
	nameofCompetition = "";
	marathondistance = 0;
	runLocation = "";
	orgnizer = "";
	totalRunners = 0;
}
CRunners::CRunners(string fName, string nameofcomp, double mile, string location, string org)
{
	filename = fName;
	nameofCompetition = fName;  
	marathondistance=mile ;
	runLocation=location;
	orgnizer = org;
	totalRunners=0;
}

CRunners::CRunners(CRunners &runnersObject)
{
	//copy constructor
	filename = runnersObject.filename;
	nameofCompetition = runnersObject.nameofCompetition;
	marathondistance = runnersObject.marathondistance;
	runLocation = runnersObject.runLocation;
	orgnizer = runnersObject.orgnizer;
	totalRunners = runnersObject.totalRunners;
}

CRunners::~CRunners()
{

}

void CRunners::constructRunnerlist()
{
	if (filename != "")
	{
		fstream file;
		file.open(filename, ios::in);

		if (!file.fail())
		{
			string str;
			//read the file line by line till end
			totalRunners = 0;

			while (getline(file, str) && !file.eof())
			{
				if (file.eof()) break;

				char firstname[100], lastname[100];
				unsigned pace;
				//get first name
				int i = 0;
				while ( str[i]!=' ')
				{
					i++;
				}
				strncpy(firstname, str.c_str(), i);
				firstname[i] = 0;
				//get last bname
				int j = i + 1;
				while (str[j] != ' ')
				{
					j++;
				}
				
				string last_name(&str[i + 1]);
				strncpy(lastname, last_name.c_str(), (j - i - 1));
				lastname[j - i - 1] = 0;
				//get the pace
				i = j + 1;
				string pace_str(&str[i]);
				pace = stoi(pace_str);

				Runner runner(string(firstname), string(lastname), pace);
				

				//save runner into the runners list
				if (pace<=360)
				{					
					whitePaceRunners.push_back(runner);
					totalRunners++;
				}
				else if (pace >= 361 && pace <= 420)
				{
					yellowPaceRunners.push_back(runner);
					totalRunners++;
				}
				else if (pace >= 421 && pace <= 480)
				{
					greenPaceRunners.push_back(runner);
					totalRunners++;
				}
				else if (pace >= 481 && pace <= 540)
				{
					orangePaceRunners.push_back(runner);
					totalRunners++;
				}
				else if (pace >= 541 && pace <= 600)
				{
					bluePaceRunners.push_back(runner);
					totalRunners++;
				}
				else if (pace >= 601 && pace <= 720)
				{
					lilacPaceRunners.push_back(runner);
					totalRunners++;
				}
				else if (pace >= 721 && pace <= 1200)
				{
					redPaceRunners.push_back(runner);
					totalRunners++;
				}
				else
				{
					cout << pace << "Pace is invalid" << endl;
				}

			}
		}

		file.close();
	}
}


void CRunners::Vectorsort()
{
	// Sorting the vectors
	
	sort(whitePaceRunners.begin(), whitePaceRunners.end(), ascend_runner_pace);
	sort(yellowPaceRunners.begin(), yellowPaceRunners.end(), ascend_runner_pace);
	sort(greenPaceRunners.begin(), greenPaceRunners.end(), ascend_runner_pace);
	sort(orangePaceRunners.begin(), orangePaceRunners.end(), ascend_runner_pace);
	sort(bluePaceRunners.begin(), bluePaceRunners.end(), ascend_runner_pace);
	sort(lilacPaceRunners.begin(), lilacPaceRunners.end(), ascend_runner_pace);
	sort(redPaceRunners.begin(), redPaceRunners.end(), ascend_runner_pace);
}



int CRunners::getTotalRuners()
{
	return totalRunners;
}

void CRunners::setRunnersFile(string fileName)
{
	filename = fileName;
}

void CRunners::readRunnersAndSort()
{
	constructRunnerlist();
	Vectorsort();
}

void CRunners::outPutRunnersFile()
{
	fstream createfile;
	
	createfile.open("white.txt", ios::out);
	for (unsigned int i = 0; i < whitePaceRunners.size(); i++)
	{
		createfile << whitePaceRunners[i].get_firstname() << " " << whitePaceRunners[i].get_lastname() << " " << whitePaceRunners[i].get_pace() << endl;
	}

	createfile.close();


	createfile.open("yellow.txt", ios::out);
	for (unsigned int i = 0; i < yellowPaceRunners.size(); i++)
	{
		createfile << yellowPaceRunners[i].get_firstname() << " " << yellowPaceRunners[i].get_lastname() << " " << yellowPaceRunners[i].get_pace() << endl;
	}

	createfile.close();

	createfile.open("green.txt", ios::out);
	for (unsigned int i = 0; i < greenPaceRunners.size(); i++)
	{
		createfile << greenPaceRunners[i].get_firstname() << " " << greenPaceRunners[i].get_lastname() << " " << greenPaceRunners[i].get_pace() << endl;
	}

	createfile.close();

	createfile.open("orange.txt", ios::out);
	for (unsigned int i = 0; i < orangePaceRunners.size(); i++)
	{
		createfile << orangePaceRunners[i].get_firstname() << " " << orangePaceRunners[i].get_lastname() << " " << orangePaceRunners[i].get_pace() << endl;
	}

	createfile.close();

	createfile.open("blue.txt", ios::out);
	for (unsigned int i = 0; i < bluePaceRunners.size(); i++)
	{
		createfile << bluePaceRunners[i].get_firstname() << " " << bluePaceRunners[i].get_lastname() << " " << bluePaceRunners[i].get_pace() << endl;
	}

	createfile.close();

	createfile.open("lilac.txt", ios::out);
	for (unsigned int i = 0; i < lilacPaceRunners.size(); i++)
	{
		createfile << lilacPaceRunners[i].get_firstname() << " " << lilacPaceRunners[i].get_lastname() << " " << lilacPaceRunners[i].get_pace() << endl;
	}

	createfile.close();

	createfile.open("red.txt", ios::out);
	for (unsigned int i = 0; i < redPaceRunners.size(); i++)
	{
		createfile << redPaceRunners[i].get_firstname() << " " << redPaceRunners[i].get_lastname() << " " << redPaceRunners[i].get_pace() << endl;
	}

	createfile.close();

	
}