/* mark.c*/
/* __LINE__ constant  */

////// 4 Optional Additional Work //////

#include <stdio.h>

#define SUCCESS 0
#define DEBUG
#ifdef DEBUG
	#define MARK printf("%d\n", __LINE__);
#else
	#define MARK
#endif

int main()
	{
    MARK;
    


		MARK;
		return SUCCESS;
	}

// __LINE__ is a number representing the line number your code is currently on
