/* 3.1.5.c */
/* Print ***** proportional to element */

////  3.1 Reading from Files    ////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WIDTH 60

void calculatehistogram(char *filename, int *array);
void value(int *array);
void content (int *array, int width);
int largest (int *element);

int main (){
	FILE *fPtr;
	char buffer;
	int array [26] = {0};
	fPtr = fopen ("txt.txt", "r");
	//while ((buffer = fgetc(fPtr)) != EOF){
	//	if(isalpha(buffer)!=0){
	//		printf("%c", toupper(buffer));
	//	}
	//}     I want the text to look good when it is printed lol
	fclose (fPtr);
	calculatehistogram("txt.txt", array);
	value (array);
  printf("\n");
	content(array, WIDTH);
	return EXIT_SUCCESS;
}



void calculatehistogram(char *filename, int *array){
	FILE *fPtr;
	char buffer;

	fPtr = fopen (filename, "r");

	while ((buffer = fgetc(fPtr)) != EOF){
		buffer = toupper (buffer);
		printf("%c", toupper(buffer));
		if ((buffer>= 'A') && (buffer<='Z')){
			array[buffer-65] = array[buffer-65] +1;
		}
	}
	fclose (fPtr);
}

void value(int *array){
	int i;
	for (i=0; i<26; i++){
		if (array[i] >=0){
      char c=i+65;
			printf("%c has occured: %4d times\n", c, array[i]);
		}
	}
}

int largest (int *element){
  int best=0;
  int x=0;
  for(int i=0; i<26; i++){
    x= element[i];
    if (x>best){
      best=x;
    }
  }
  return best;
}

void content (int *array, int width){
	for (int i=0; i<26; i++){
		float p = ((array[i]*width)/largest(array));
    char c=i+65;
    printf("%c |", c);
    for (int z=0; z<p; z++){
      printf("*");
    }
      printf("\n");
	}
}

// ngl prog is quite fun
