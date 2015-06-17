//I affirm that all code given below was written solely by me, Michael Zeng, 
//and that any help I received adhered to the rules stated for this exam.

#include "CRunners.h"

int main()
{

		CRunners runners(string("registrants.txt"), string("Lilac BloomsDay"), 7.46, string("Downtown Spokane"), string("Bloomsday"));
		runners.readRunnersAndSort();
		runners.outPutRunnersFile();

	return 0;
}
