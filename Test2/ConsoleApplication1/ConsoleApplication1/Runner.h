//I affirm that all code given below was written solely by me, Michael Zeng, 
//and that any help I received adhered to the rules stated for this exam. 

#ifndef RUNNER_H
#define RUNNER_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Runner
{

public:
	Runner();
	Runner(string fname, string lname, int pa);

	~Runner();

	string get_firstname();
	string get_lastname();
	int get_pace();

private:
	string firstname;
	string lastname;
	int pace;
};



#endif