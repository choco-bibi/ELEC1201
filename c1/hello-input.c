/* hello-input.c*/
/* Ask for input.  */

////// 3.3 Part 3 //////

#include <stdio.h>

#define SUCCESS 0
#define NAME_BUFFSIZE 2


int main()
	{
    char name [NAME_BUFFSIZE];

    printf ("What is your name?  ");
    scanf ("%s", name);
		printf ("Hello %s!\n", name) ;
		return SUCCESS;
	}

//when input is larger than the reserved space nothing happens... the 
//entirety of the input still gets outputted 
