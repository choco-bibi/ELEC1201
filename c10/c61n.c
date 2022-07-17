#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect)
{
  PORTA=segments [i]; // PORTA = segments [0,1,2,3,4,5,6,7,8,9,}
 i = (i==9 ? 0 :i+1); //i will have the value of 0 if i is equal to 9 , otherwise add one to i
}
volatile const uint8_t segments [10]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
volatile uint8_t i=0;
 int main()
 {
  DDRA =0xFF;  /*DDR is to configure a port as an output.This time
  PORT A is the output*/

  //Timer 1 CTC MODE 4
  //CTC will clear timer on compare
  //when the two valuesmatch , it will jump to the interrupts
  //and clear that timer for us
  TCCR1A = 0;//dont need to change anything
  TCCR1B = _BV(WGM12);//wave form generation mode page 137

  //PRESCALER 1024
  TCCR1B |= _BV(CS12) | _BV(CS10);//page 136-137 setting a prescalar of 1024

  //set timeout at 1000ms;
  OCR1A = 11719;

  //enable interrupt
  TIMSK1 |=_BV(OCIE1A);//enable interrupts page 139
  //when my comparision value mathces the timer value it will set up an interrupt
  sei();//enable global interrupt

  while(1);

  //creating an endless loop doing nothing waiting for it to be triggered
}
