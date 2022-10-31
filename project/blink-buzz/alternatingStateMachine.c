#include <msp430.h>
#include "led.h"

static unsigned char blinkLimit;

void advance_alternation()
{
  update_blink();
  update_second();
}

static void update_blink()
{
  static unsigned char blinkCount = 0;

  if (++blinkCount >= blinkLimit) {
    blinkCount = 0;
    toggle_green(1);
  } else {
    toggle_green(0);
  }
}

static void update_second()
{
  static unsigned char secoundCount = 0;

  if (++secondCount >= 250) {
    secondCount = 0;
    once_per_second();
  }
}

static void once_per_second()
{
  if (++blinkLimit >= 8) {
    blinkLimit = 0;
  }
}
