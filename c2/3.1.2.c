/* 3.1.2.c*/
/* function  */

////// 3.1 Part 2  of 2 //////

#include <stdio.h>
#include <math.h>

#define SUCCESS 0
#define PI 3.1416
#define FREQ 1

int main()
	{
    unsigned long int x = 0;
    float y;
    while(1){
      printf("x = %lu,", x);
      y=(sin(x*PI/180)*0.5 + 0.5);
      printf("y = %.3f\n",y);
      x+=FREQ;
    }

		return SUCCESS;
	}

// Enters an endless loop
// Ctrl + C to stop the program
// Let the compiler know that it should link with the math library,
// by using the option -lm before the output option

// normal sine wave is between -1 and 1 so it has a peak-to-peak of 2
// for 0-1 peak-to-peak must be 1 and requires a shift of 0.5 in the positive y direction
