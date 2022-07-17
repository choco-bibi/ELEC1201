#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "debug.h"

ISR(ADC_vect)
{
	PINB |= _BV(PB7);
	_delay_ms(200);
}

void init_adc(void)
{
	ADCSRA |= _BV(ADPS2) |_BV(ADPS1);
	ADCSRA |=_BV(ADEN);

}

void channel_adc(uint8_t n){
	ADMUX=n;
}

int main(void)
{
	init_debug_uart0();
	init_adc();
  channel_adc(1);

	ADCSRA |= _BV(ADSC);

  /*interrupt flags in ADCSRA*/
	ADCSRA |=_BV(ADIE);
  ADCSRA |=_BV(ADIF);

  /*set to free running mode*/
  ADCSRB = 0x00;

	/*enable ADC*/
	ADCSRA |= _BV(ADATE) | _BV(ADEN);

	DDRB |= _BV(PB7);

  /*enable interrupt*/
  	sei();

/*while loop*/
	while(1){
    }
}
