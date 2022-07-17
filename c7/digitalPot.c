#include "spi.h"

void init_pot(void)
{
    /* TODO: Code to initiliase interface */
    DDRB = _BV(PB6); SPCR = _BV(SPE);
    // setting port b6 to be an output
    // SPCR controls settings (stores one), SPE tells it to enable SPI when 1
}

void decXpot(void)
{
    /* TODO: Code to decrement first pot by 1 */
    SPDR = 0x10;
    while(!(SPSR & _BV(SPIF)));

    //0000 1000

}

void incXpot(void)
{
    /* TODO: Code to increment first pot by 1 */
    SPDR = 0X08;
    while(!(SPSR & _BV(SPIF)));

    //0000 0100
}

void decYpot(void)
{
    /* TODO: Code to decrement second pot by 1 */
    SPDR = 0x18;
    while(!(SPSR & _BV(SPIF)));

    //0001 1000

}

void incYpot(void)
{
    /* TODO: Code to increment second pot by 1 */
    SPDR = 0x14;
    while(!(SPSR & _BV(SPIF)));
    //0001 0100
}


void setXpot(uint8_t x)
{
    /* TODO: Code to set first pot to a value between 0 and 255 */
    SPDR = x; //value of x assigned to SPI data register
    while(!(SPSR & _BV(SPIF))); //SPIF is a bit in the SPSR register (save program status register)
    // continue running until
}

void setYpot(uint8_t y)
{
    /* TODO: Code to set second pot to a value between 0 and 255 */
    SPDR = y;
    while(!(SPSR & _BV(SPIF)));
}
