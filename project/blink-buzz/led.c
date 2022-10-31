#include <msp430.h>
#include "led.h"

void led_init()
{
  P1DIR |= LEDS;	/* bits attached to leds are output */
  P1OUT &= ~LEDS;	/* leds initially off */
}

/*
 * Turns off the green LED if the flag passed in is 0; otherwise, it will be
 * turned on.
 */
void toggle_green(unsigned char flag)
{
  if (flag) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
}

/*
 * Turns off the red LED if the flag passed in is 0; otherwise it will be
 * turned on.
 */
void toggle_red(unsigned char flag)
{
  if (flag) {
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
}
