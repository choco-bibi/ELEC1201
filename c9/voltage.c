// sorry Steve, I don't really want to edit out your code, but this is yours
/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *           View this license at http://creativecommons.org/about/licenses/
 *   Notes: F_CPU must be defined to match the clock frequency
 */
#include <avr/io.h>
#include <util/delay.h>


#include "debug.h"

void init_adc(void)
{
	/* TODO: Initialisation code */

  ADCSRA |= _BV(ADPS2)|_BV(ADPS1); /*F_ADC=F_CPU/64*/
  ADCSRA |= _BV(ADEN); /* Enable ADC */
}

uint16_t read_adc(void)
{
	/* TODO: Acquisition code */
  ADMUX = 0b0000000; //select channel
  //ADMUX |= _BV(REFS0); /*AVCC reference*/
  //ADMUX |= _BV(ADLAR); //ADCH contains 8MSBs

  ADCSRA |= _BV(ADSC); /* Start Conversions */
  //ADCSRA |= _BV(ADIE); /* Enable interrupt */
  while(ADCSRA&01000000); //wait for conversion to end
  ADC=ADCH;
  ADC=ADC<<8;
  ADC+=ADCL;
	return ADC;
}

int main(void)
{
	uint16_t result;
	double voltage;

	init_debug_uart0();
	init_adc();

	for (;;)
	{
		/* TODO: Measurement code */
    result=read_adc();
    voltage=(result*3.3)/1024;
		printf("%4d : %6.5fV\n", result, voltage);
		_delay_ms(1000);
	}
}
