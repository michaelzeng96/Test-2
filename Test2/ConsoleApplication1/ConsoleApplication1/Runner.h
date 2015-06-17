#ifndef RUNNER_H
#define RUNNER_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Runner
{
private:
	string firstname;
	string lastname;
	int pace;
public:
	Runner();
	Runner(string fname, string lname, int pa);

	~Runner();

	string get_firstname();
	string get_lastname();
	int get_pace();
};



#endif