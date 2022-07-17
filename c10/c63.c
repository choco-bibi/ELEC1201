///////////////////////////////////////////////////////////////
//    if falling edge is detected in PD3 (INT1), value++     //
//    if falling edge on PD2 (INT0), value--                 //
//    will not increment past 255 or decrement past 0        //
//    when value changes write value to port                 //
///////////////////////////////////////////////////////////////

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t value = 0;

ISR(INT0_vect)
{
	value = (value==0 ? 0: value-1);
  PORTC=value;
  PINB |= _BV(PB7);
}

ISR(INT1_vect)
{
  /*there are 256 possible outputs because there are 8 pins */
	value = (value==255 ? 255: value+1);
  PORTC = value;
  PINB |= _BV(PB7);
}

int main(void){
      /* portD in input and enable pull-ups */
      DDRD = 0x00;
      PORTD = 0xFF;

      /*portC is output */
      DDRC = 0xFF;

      /* External interrupt enable */
      EIMSK |=_BV(INT1);
      EIMSK |=_BV(INT0);

      /* External interrupt flag */
     //	EIFR |=_BV(INTF1);
     //	EIFR |=_BV(INTF0);

     	/* External interrupt control; which edges to trigger on */
      EICRA |=_BV(ISC11);
      EICRA |=_BV(ISC01);
	  
	  MCUCR |= _BV(JTD);
MCUCR |= _BV(JTD);

     	/*enable global interrupt*/
      sei();

DDRB |= _BV(PB7);

      /* wait for interrupts */
      while(1);
}
