#include "CRunners.h"

int main()
{

		CRunners runners(string("registrants.txt"), string("Lilac BloomsDay"), 7.46, string("Downtown Spokane"), string("Bloomsday"));
		runners.readRunnersAndSort();
		runners.outPutRunnersFile();

	return 0;
}
