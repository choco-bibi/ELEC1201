////////////////////////////////////////////////////////////////
//    if falling edge is detected in PD3 (INT1), value++      //
//    if falling edge on PD2 (INT0), value--                  //
//                                                            //
//    ADC sampling rate adjusted by pressing 2 "buttons"      //
//    on INT0 and INT1                                        //
//    ADC auto trigger source use Timer/Counter0 Compare   V  //
//    Match to trigger the ADC                             V  //
//    write the 8-bit value from the external interrupt    V  //
//    code to the register OCR0A                           V  //
//    timer 0 in CTC mode                                  V  //
//    manipulate the sampling rate of the ADC with the        //
//    external inputs to the AVR                              //
////////////////////////////////////////////////////////////////

#include <avr/io.h>
#include <avr/interrupt.h>
#include "debug.h"

volatile uint8_t value = 0;

ISR(ADC_vect)
{
	PINB |= _BV(PB7);
}

ISR(INT0_vect)
{
	value = (value==0 ? 0: value-1);
  OCR0A = value;
}

ISR(INT1_vect)
{
  /*there are 256 possible outputs because there are 8 pins */
	value = (value==255 ? 255: value+1);
  OCR0A = value;
}

void INTs (void){
  ///*   code to enable external interrupts in port D *///

  /* portD in input and enable pull-ups */
  DDRD = 0x00;
  PORTD = 0xFF;

  /* External interrupt enable */
  EIMSK |=_BV(INT1);
  EIMSK |=_BV(INT0);

  /* External interrupt flag */
  EIFR |=_BV(INTF1);
  EIFR |=_BV(INTF0);

  /* External interrupt control; which edges to trigger on */
  EICRA |=_BV(ISC11);
  EICRA |=_BV(ISC01);

}

void adcstart (void){
  ///* enable adc and its respective interrupts *///
  ADCSRA |= _BV(ADPS2) |_BV(ADPS1);
	ADCSRA |=_BV(ADEN);

  ADCSRA |= _BV(ADSC);

  /*interrupt flags in ADCSRA*/
	ADCSRA |=_BV(ADIE);
  ADCSRA |=_BV(ADIF);

  /*set trigger source to Timer/Counter0 Compare Match*/
  ADCSRB |=_BV(ADTS1) | _BV(ADTS0);

	/*enable ADC*/
	ADCSRA |= _BV(ADATE) | _BV(ADEN);

  /* Timer 0 on CTC mode */
  TCCR0B |= _BV(WGM01); //enable CTC
  TIMSK0 |= _BV(OCIE0A); //enable output compare match interrupt
  TCCR0A |= _BV(COM0A1);
  TIFR0 |= _BV(OCF0A); //enable timer/counter0 interrupt flag register

}

void channel_adc(uint8_t n){
	ADMUX=n;
}

int main(void){

      INTs();
      adcstart();
      DDRB |= _BV(PB7);
      channel_adc(1);

     	/*enable global interrupt*/
      sei();

      /* wait for interupts */
      while(1);
}

//as you can see from the box on the top I was really getting into it
