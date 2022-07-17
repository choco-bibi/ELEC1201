#include <avr/io.h>
#include <avr/interrupt.h>
#include "debug.h"
#define VERF 3.3

ISR(ADC_vect) {
if(result > 650)
PORTB |= _BV(PB7);
else
PORTB &= ~ _BV(PB7);
}

volatile uint16_t read_adc(void)
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

volatile uint16_t result;


int main (void)
{
DDRB |= _BV(PB7);
PORTB &= ~_BV(PB7);
/* Set ADC prescaler to 64 - 187.5kHz ADC clock */
ADCSRA = _BV(ADPS2) | _BV(ADPS1);

/* AREF reference, channel 0, right shift result */
ADMUX = 0x00;

/* Free-running mode and enable ADC */
ADCSRA |= _BV(ADATE) | _BV(ADEN);
ADCSRB = 0x00;

/* Enable Interrupts */
sei();
ADCSRA |= _BV(ADIE);

/* Start Conversions */
ADCSRA |= _BV(ADSC);
result= read_adc();
while(1);
}
