/* 4.c */
/* Colours  */

////// 4 Optional Additional Work  //////

#include <stdio.h>
#include <math.h>
#include <windows.h>

#define SUCCESS 0
#define PI 3.1416
#define FREQ 5
#define WIDTH 80

void plotval(float value, int width, int x);
void reset ();
void colour (int x);


int main()
	{
    unsigned long int x = 0;
    float y;
    while(1){
      reset();
      printf("x = %12lu,", x);
      y=(sin(x*PI/180)*0.5 + 0.5);
      printf("y = %4.2f | ",y);
      colour (x);
      plotval(y,WIDTH,x);
      reset();
      printf("\n");
      x+=FREQ;
    }

		return SUCCESS;
	}


void colour (int x)
  {
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      int t;
      t=((x/FREQ)%6);

      if(t==1){
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
      } else if(t==2){
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED);
      } else if(t==3){
        SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
      } else if(t==4){
        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_RED);
      } else if(t==5){
        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
      } else {
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
      }
  }

void reset ()
  {
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
  }

void plotval(float value, int width, int ten)
  {
    int place, i;
  	place = value * width;

    if((ten/FREQ)%10){
      printf("   ");
    }else{
      printf("---");
    }

  	for ( i=0; i < place; i++)
    {
  		printf(" ");
  	}
  	printf("*");
    ten+=1;
  }
