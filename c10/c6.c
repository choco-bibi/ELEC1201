#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 12000000

volatile uint8_t i = 0;
const uint8_t segments [10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};

ISR(TIMER1_COMPA_vect)
{
 PORTA = segments[i];
 i++;
 if(i>=9){
	 i=0;
 }
 // i = (i==9 ? 0: i+1);

}

/* init_debug_uart0()*/

void timer_init(){
  TCCR1A = 0; // we want normal port operation for OCnA/OCnB don't output anything on compare match
  TCCR1B |= _BV(WGM12); // waveform generation mode
  TCCR1B |= _BV(CS12)| _BV(CS10); //setting a prescalar of 1024 page 136-137
  TIMSK1 |= _BV(OCIE1A); //enable output compare match interrupt
//  TIFR1  |= _BV(OCF1A); //enables output compare match flag
}

void delay(uint16_t ms){ // 8 bit because it has to fit in the 8 bit register
    OCR1A = (uint16_t)((ms/1000)*F_CPU*(1/(2*1024)))-1;
}

int main(void){

  DDRA = 0xFF; // configure port A as output
  DDRD = 0xFF; // configure port D as output

  OCR1A = 11719;
  //delay(1000); //delay function telling us how often interrupt should occur 5858 is value of OCR1A
  timer_init();
  sei(); //enable global interrupt
  while(1){

  }
}


//CTC clear timer on compare match part 14.7.2 for timer 0
//different betweeen ctc and pulse pwm.
/* ctc is a counter it will tell cpu it has counted to a value then tell counter to reset again
fast pwm is for pwm, not just counting.

*/

//I really enjoyed this lab to be completely honest. I took a long time on it and was very pleased when I finally understood :)
