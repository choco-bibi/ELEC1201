//do not really want to add much as there was barely any coding in this lab...



void init_tone(void)
{
   DDRD |= _BV(PD5)	;
   TCCR1A = _BV(COM1A0) | _BV(WGM10);
   TCCR1B = _BV(WGM13) | _BV(CS11);

}


void tone(uint16_t frequency)
{
   OCR1A = (uint16_t) (F_CPU/(2*2*TONE_PRESCALER)/frequency);
}
