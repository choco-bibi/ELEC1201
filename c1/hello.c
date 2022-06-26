/* hello .c*/
/* A famous test for the C build process . */

////// 3.1 Part 1 //////

#include <stdio.h>

#define SUCCESS 0

int main()
	{
		/* A new-line control character (\n)  */
		/* is used here, in case the terminal */
		/* collects complete lines before     */
		/* showing them.                      */
		printf (" Hello world !\n") ;
		return SUCCESS;
	}


//// to run use 'gcc hello.c -o hello' in command terminal, then 'hello' /////
//// to make copy use 'cp' command. 'cp hello.c hello1.c'                ////
