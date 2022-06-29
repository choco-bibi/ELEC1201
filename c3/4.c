/* 4.c */
/* Fashion and Attention  */

////  4 Optional Additional Work    ////

////////////////////////////////////////////
// evol.c                                 //
// ELEC1201 Lab C3: Operators and Arrays  //
// Evolutionary Computing                 //
// KPZ 2018, MIT License                  //
//                                        //
// Compile with math library:             //
//    gcc evol.c -lm -o evol              //
////////////////////////////////////////////

// oh my days I'm terrible at coding :(  //

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>

#define TARGET   1.0
#define EPSILON    0.02

#define POP_SIZE     51
#define MAX_GEN    100

#define MUTATION_STRENGTH  0.1
#define RND_INIT           2
#define FANSP              3
#define COMPARE_NO         3


void printheader(void);
float rnd(); // Random values 0.0 to 1.0
int rndel();
float average(float *pop, float size);
void initpop(float *pop, int size);
void fanss(float attractivebeing, float mutst, float *pop, int fansize, int index);
void copyarray (float *copyfrom, float *copyto, int size);
float genbest (int size, float *pop);



int main(){
    float population[POP_SIZE];
    float fans[POP_SIZE];
    float most_attractive; //that's me!!!!!
    int i, j, k; //k will be an index for the element thingy for the fans array
    int gen = 0;
    float faceoff[COMPARE_NO];
    float genmost =0;
    float avg = 0; // i want the program to stop when the average of the
                    // 'generation of fans' facing off is grater than 0.9999

      srand(RND_INIT);
      initpop(population, POP_SIZE);

      while ((avg<(TARGET-EPSILON))&(gen<MAX_GEN)){
        k=0;
          for(i=0; i<(POP_SIZE/COMPARE_NO); i++){
            for (j=0; j< COMPARE_NO; j++){
              faceoff[j]=population[rndel()];
            }
            if (((faceoff[0])>(faceoff[1]))&((faceoff[0])>(faceoff[2]))){
              most_attractive=faceoff[0];
              fanss(most_attractive,MUTATION_STRENGTH, fans, FANSP, k);
            } else if (((faceoff[1])>(faceoff[0]))&((faceoff[1])>(faceoff[2]))){
              most_attractive=faceoff[1];
              fanss(most_attractive,MUTATION_STRENGTH, fans, FANSP, k);
            } else {
              most_attractive=faceoff[2];
              fanss(most_attractive,MUTATION_STRENGTH, fans, FANSP, k);
            }
            k=k+3;
          }

          genmost=genbest(POP_SIZE, population);
          avg = average(population, POP_SIZE);

        //  memcpy(population, fans, POP_SIZE); /// BAHHHH THIS DIDN'T WORK
          copyarray(fans, population, POP_SIZE); // had to create a function to do the copying instead bruh

          printf("Generation %4d, generation average: %3f, most attractive: %4f\n", gen++, avg, genmost);
      }

	return 0;
}


// Returns a random value between 0.0 and 1.0
float rnd(){
    return rand()/(float) RAND_MAX;
}

// Returns a random integer between 0 and POP_SIZE
int rndel(){
    return (rand()%(POP_SIZE));
}

// Returns mean value of the 3 people facing off
float average(float *pop, float size){
  float v = 0;
  for(int i=0; i<size; i++){
     v = pop[i] + v;
  }
  v=v/size;
  return (v);
}

void initpop(float *pop, int size){
	for (int k = 0; k <size; k++){
		pop[k] = rnd();
	}
}

float genbest (int size, float *pop){
  float best=0;
  float x=0;
  for(int i=0; i<size; i++){
    x= pop[i];
    if (x>best){
      best=x;
    }
  }
  return best;
}

void copyarray (float *copyfrom, float *copyto, int size){
  for(int i=0; i< size; i++){
    copyto[i]=copyfrom[i];
  }
}

void fanss(float attractivebeing, float mutst, float *pop, int fansize, int index){
	for (int i=0; i<fansize; i++){
		pop[index] = attractivebeing; + (rnd()-0.5)*mutst;
    index++;
	}
}
// the values returned from the fans function must still remain within 0 and 1

// (⋟﹏⋞)   (ಥ﹏ಥ)   why was this so painful to make?
//It's only week 3 and it's already so hard wth I've never coded b4
