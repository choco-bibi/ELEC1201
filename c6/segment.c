 #include <avr/io.h>
 #include <util/delay.h>

const unit8_t segments[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
int main(void){
	unit8_t i=0;
	DDRA = 0xFF;
	DDRC = 0x00;
	PORTC = 0xFF;
	PORTA = segments[i];

	for (;;){
		while((PINC & _BV(PC7)0 !=0);
		i = (i==9 ? 0: i+1);
		PORTA = segments [i];  
		while ((PINC & _BV(PC7)) == 0);
	}
 }
