#include <avr/io.h>
#include <util/delay.h>
 
#define POLL_DELAY_MS 500
 
int main(void)
{
  DDRB &= ~(1 << 4);    /* Set port B pin 4 as input */
  DDRB |= (1 << 5);     /* Set port B pin 5 as output */
  
  while (1) {
    if (PINB & (1 << 4)) {  /* If port B pin 4 is high */
      PORTB |= (1 << 5);    /* Set port B pin 5 high */
    }
    else {
      PORTB &= ~(1 << 5);   /* Set port B pin 5 low */
    }

    _delay_ms(POLL_DELAY_MS);
  }

  return 0;
}
