/* 3.1.4.c */
/* Calculate histogram and print values */

////  3.1 Reading from Files    ////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void calculatehistogram(char *filename, int array [26]);

int main (){
	FILE *fPtr;
	char buffer;
	int array [26] = {0};
	fPtr = fopen ("txt.txt", "r");
	while ((buffer = fgetc(fPtr)) != EOF){
		if(isalpha(buffer)!=0){
			printf("%c", toupper(buffer));
		}
	}
	fclose (fPtr);
	calculatehistogram("txt.txt", array);
	return EXIT_SUCCESS;
}

void calculatehistogram(char *filename, int *array){
	FILE *fPtr;
	char buffer;
	int i;


	fPtr = fopen (filename, "r");

	while ((buffer = fgetc(fPtr)) != EOF){
		buffer = toupper (buffer);
		if ((buffer>= 'A') && (buffer<='Z')){
			array[buffer-65] = array[buffer-65] +1;
		}
	}

	for (i=0; i<26; i++){
		if (array[i] >=0){
			printf("%i has occured: %d times\n", i+65, array[i]);
		}
	}
	fclose (fPtr);
}
