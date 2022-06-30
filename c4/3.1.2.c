/* 3.1.2.c */
/* Prints alphabetic characters in uppercase  */

////  3.1 Reading from Files    ////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (){
	FILE *fPtr;
	char buffer;
	fPtr = fopen ("txt.txt", "r");
	while ((buffer = fgetc(fPtr)) != EOF){
		if(isalpha(buffer) != 0){
			printf("%c", toupper(buffer));
		}
	}
	fclose (fPtr);
	return EXIT_SUCCESS;
}
