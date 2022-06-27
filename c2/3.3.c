/* 3.3.c*/
/* function  */

////// 3.3  //////

#include <stdio.h>
#include <math.h>

#define SUCCESS 0
#define PI 3.1416
#define FREQ 1
#define WIDTH 100

void plotval(float value, int width, int x);

int main()
	{
    unsigned long int x = 0;
    float y;
    while(1){
      printf("x = %12lu,", x);
      y=(sin(x*PI/180)*0.5 + 0.5);
      printf("y = %4.2f | ",y);
      plotval(y,WIDTH,x);
      x+=FREQ;
    }

		return SUCCESS;
	}

void plotval(float value, int width, int ten)
  {
    int place, i;
  	place = value * width;

    if(ten%10){
      printf("   ");
    }else{
      printf("---");
    }

  	for ( i=0; i < place; i++)
    {
  		printf(" ");
  	}
  	printf("*\n");
    ten+=1;
  }
