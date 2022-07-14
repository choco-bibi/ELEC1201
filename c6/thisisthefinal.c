#include <avr/io.h>
#include <util/delay.h>


const uint8_t segments[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
//uint8_t ARRAY[16] = {NO, ERROR, CCW, CW};
int main(void){
   uint8_t i=0;
   DDRA = 0xFF;
   DDRC = 0x00;
   PORTC = 0xFF;
   PORTA = segments[i];
/*
   for(;;) {
     for(i= 0;i< 10 ; i++) {
       PORTA = segments [i];
         _delay_ms(500);
     }


 for (;;){
   while((PINC & _BV(PC7)) !=0);
   i++;
   PORTA = segments [i];
   while ((PINC & _BV(PC7)) == 0);
   if (i>9){
     i=0;
     PORTA == segments [i];
   }
   _delay_ms(500);
 }


     for(i= 10;i> 0 ; i--) {
       PORTA = segments [i];
         _delay_ms(500);
     }
     */
   uint8_t ai = (PINC & _BV(PC1));
   uint8_t bi = (PINC & _BV(PC0));

while(1)
{
   _delay_ms(10);
 uint8_t af = (PINC & _BV(PC1));
   uint8_t bf = (PINC & _BV(PC0));


  if((ai == 0 && bi == 0 && af == 0 && bf == 1)||(ai == 0 && bi == 1 && af == 1 && bf == 1)||(ai == 1 && bi == 0 && af == 0 && bf == 0)||(ai == 1 && bi == 1 && af == 1 && bf == 0) ){
   //i--;
   i= (i==0 ? 9 : i-1);
    // i= (i==9 ? 0 : i+1);
  }
  if((ai == 0 && bi == 0 && af == 1 && bf == 0)||(ai == 0 && bi == 1 && af == 0 && bf == 0)||(ai == 1 && bi == 0 && af == 1 && bf == 1)||(ai == 1 && bi == 1 && af == 0 && bf == 1)) {
   //i++;
   // i= (i==0 ? 9 : i-1);
   i= (i==9 ? 0 : i+1);
  }
/*
 if (i>9){
     i=0;
   }
 if (i<0){
     i=9;
   }
*/
   PORTA = segments [i];

   ai = af;
   bi = bf;
}
}
