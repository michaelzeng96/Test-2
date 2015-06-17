//I affirm that all code given below was written solely by me, Michael Zeng, 
//and that any help I received adhered to the rules stated for this exam.

#include "Runner.h"

Runner::Runner() : firstname(0), lastname(0), pace(0)
{
};

Runner::Runner(string fname, string lname, int pa) : firstname(fname), lastname(lname), pace(pa){};



Runner::~Runner()
{

}

string Runner::get_firstname()
{
	return firstname;
}

string Runner::get_lastname()
{
	return lastname;
}

int Runner::get_pace()
{
	return pace;
}


