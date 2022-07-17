#include <avr/io.h>
#include <util/interrupt.h>

volatile uint_t count = 0;

void init_timer(void){
    // We want clear timer on compare match (comparing to a specific time)
    TCCR0A |= _BV(WGM1);
    // Enables CTC, TOP = OCR1A
    TCCR0B |= _BV(CS02) | _BV(CS00);
    // Sets prescalar to 1024 desu
    TIMSK0 |= _BV(OCIE0A);
    // Enables compare match A interrupt
}

void delay(uint8_t ms){ // 8 bit because it has to fit in the 8 bit register
    OCR0A = (uint8_t)((ms/1000)*F_CPU*(1/(2*1024)))-1;
}

ISR(TIMER0_COMPA){
    count++;
    if(count >= 10){
      count =0;
    }
}

int main(){
    DDRA = 0xFF;
    const uint8_t segments[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFF, 0xF6};
    delay(1000);
    init_timer();
    while(1){
      PORTA = segments[count];
    }
    return 0;
}
//need to change to counter 1
