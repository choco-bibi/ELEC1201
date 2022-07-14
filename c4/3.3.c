/* 3.3.c */
/* combine all work? eh? */

////  3.3 Code Breaking   ////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void calculatehistogram(char *text, int *array){
  for (int j=0; j<26; j++){
    array[j]=0;
  }
  char buffer;
  for (int i=0; text[i];i++){
		buffer = toupper (text[i]);
	//	printf("%c", toupper(buffer));
		if ((buffer>= 'A') && (buffer<='Z')){
			array[buffer-65] = array[buffer-65] +1;
		}
	}

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

void valueperc(float *array){
	int i;
	for (i=0; i<26; i++){
		if (array[i] >=0){
      char c=i+65;
	//		printf("%c has occured: %4f percent\n", c, array[i]);
		}
	}
}

int sum (int *element){
  int best=0;
  int x=0;
  for(int i=0; i<26; i++){
    x= element[i];
    best=best+x;
  }
  return best;
}

// hehehe word spacing and punctuation give additional clues about plain text so they are removed!!!
void encipher( char *p, const unsigned int offset){
	int i, j=0;
	for (i=0; p[i];i++){
		if(isalpha (p[i])){
			p[j++] = ((toupper (p[i])) - 65 +offset) %26 +65;
		}
	}
  p[j] = '\0';
}

void decipher( char *c, const unsigned int offset){
	int i, j=0;
	for (i=0; c[i];i++){
		if(isalpha (c[i])){
			c[j++] = ((toupper (c[i])) - 65 -offset +26) %26 +65;
		}
	}
  c[j] = '\0';
}

//what am I doing? ╥﹏╥
void readfile(char *filename, char *text){
	FILE *fPtr;
	char buffer;
	int i=0;
	fPtr = fopen (filename, "r");

	while ((buffer = fgetc(fPtr)) != EOF){
		buffer = toupper (buffer);
		text[i]=buffer;
		i++;
	}
	fclose (fPtr);
}

void perc (int *array, float *arrayperc){
	for (int i=0; i<26; i++){
		 arrayperc [i] = (((float)(array[i]))/((float)sum(array)));
	}
}

int main (){
	float arraysample [26] ={0.0834, 0.0154, 0.0273, 0.04141, 0.1260, 0.0203, 0.0192, 0.0611, 0.0671, 0.0023, 0.0087, 0.0424, 0.0253, 0.0680, 0.0770, 0.0166, 0.0009, 0.0568, 0.0611, 0.0937, 0.0285, 0.0106, 0.0234, 0.0020, 0.0204, 0.0006};
	//decided that instead of making the program run through a very large sample of text to find letter frequencies, I'll just insert the letter frequencies in an array (bc i'm kinda lazy)
	int array [26] = {0}; // this array will be used for what you are trying to decipher, to help find the key (offset)
  float arrayperc [26] = {0};

	char text[500000] = {0};
	char filename[30] ={0};
	char option =0;
	int offset =0;
  printf("WELCOME TO THE CAESER CIPHER PROGRAM!\n");
	printf("Please provide the name of the text file (including file extenion): \n"); // let's spice it up!
	scanf("%s", filename);

	printf("Here is the contents of the file you have chosen: \n");
	readfile(filename, text);
	printf("%s\n", text);

	printf("What would you like to do with this file?\n");
	printf("If you would like to ENCIPHER it please enter 'E', \nIf you would like to DECIPHER it with a KNOWN KEY please enter 'D'\n");
	printf("If you would like to DECIPHER the text file but do not know the key please press 'U'\n");

	scanf(" %c", &option);
	option=toupper(option);

	while ((option != 'E')&&(option != 'D')&&(option !='U')){
	printf("Please insert a valid option");
	scanf(" %c", &option);
	option=toupper(option);
	}

  if (option == 'E'){
    printf("Please insert the key you would like to use:");
    scanf("%i", &offset);
    readfile(filename,text);
    encipher(text, offset);
    printf("%s\n", text);
  } else if (option == 'D'){
    printf("Please insert the key you would like to use:");
    scanf("%i", &offset);
    readfile(filename,text);
    decipher(text, offset);
    printf("%s\n", text);
  } else if (option == 'U'){
    printf("This function is not guaranteed to always work as it produces better results with larger pieces of text. \n \n");
    int finaloffset=0;
    float best =100000;
    for (int i=0; i<26; i++){
      offset = i;
      double p=0;
      readfile(filename,text);
      decipher(text, offset);

    //  printf("\n \n this is run number %d: \n", i);
      calculatehistogram(text, array);
    //  value(array);
    //  printf("\n \n");
      perc(array, arrayperc);
      valueperc(arrayperc);

      for (int l=0;l<26;l++){
       double j= (arraysample[l]-arrayperc[l]);
       j= fabs(j);
       p=p+j;
     }
    // printf("%f\n",p );

     if (p<best){
       best=p;
       finaloffset =i;
      // printf(" %f,  %i", best, finaloffset);
     }

    }
    readfile(filename,text);
    decipher(text, finaloffset);
    printf("%s\n", text);
    printf("key used is: %i\n", finaloffset);

    }
    return 0;
}

// -Wall -Wall -Wall !!!

// hell to the no for the optional work  (ㆆ ᴗㆆ)
// wow love how i can collapse the functions in atom. so much better than notepad ++
//should i download visual studio too?
