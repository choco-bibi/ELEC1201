/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *           View this license at http://creativecommons.org/about/licenses/
 *   Notes: F_CPU must be defined to match the clock frequency
 */
#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"
#define VREF 3.3

void init_adc(void)
{
	/* TODO: Initialisation code */

	// We want to set multiplexer to 00000 so that we have ADC0
	// Hence all bits of ADMUX are 0 and don't have to be changed
	ADCSRA |= _BV(ADPS2) |_BV(ADPS1); // |_BV(ADEN);
	ADCSRA |=_BV(ADEN);
	//We are enabling ADEN, setting prescaler to 64,
}

uint16_t read_adc(void)
{
	/* TODO: Acquisition code */
//	uint16_t ADC;
	ADCSRA |= _BV(ADSC);
	//while(ADCSRA&01000000);
	while(ADCSRA&_BV(ADSC)){};
	//ADC |= ADCH;
	//ADC = ADC << 8;
	//ADC |= ADCL;
	return ADC;
}

void channel_adc(uint8_t n){
	ADMUX=n;
}	

int main(void)
{
	uint16_t result;
	double voltage;
	uint16_t counter;
	uint16_t timer;

	init_debug_uart0();
	init_adc();
	channel_adc(2);
	DDRB = 0xFF;
	for (;;)
	{
		/* TODO: Measurement code */
		result = read_adc();
		voltage = (result*3.3)/1024;
		if(voltage<0.9){
			//turn led on pb7
			PORTB|=_BV(PB7);
			counter++;
			
		}else{
			//turn led off
			PORTB&=~_BV(PB7);
		}
		timer++;
		
		_delay_ms(100);
		if(timer==0){
			counter=counter*60;
			printf("%4d BPM\n", counter);	
			counter=0;
			timer=0;
		}	
	}
}
