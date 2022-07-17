#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"


const uint8_t segments[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
int main(void){
  init_debug_uart0(); //calls debug function
 int8_t i=0;
 DDRA = 0xFF;
 // ask demo int x;
 // int x = NULL;
 PORTA = segments[i];


 for (;;){
   for(i=0; i<10;i++){
   PORTA = segments [i];
   printf("d\n",i);
   _delay_ms(500);
 }
 // second part of 3.1 fprintf(stderr,"Count overflow\n\r");
 // third part of 3.1 scanf("%d",&x);
 //or these scanf("%*[^\n]");
 //scanf("%*c");

 /*
 while (x==NULL){
   scanf("d\n", &x );
 }
 */
   _delay_ms(500);
 }
}
