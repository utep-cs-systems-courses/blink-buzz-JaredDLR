#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

/* setup switch */
void switch_init()
{  
  P2REN |= SWITCHES;	/* enables resistors for switches */
  P2IE |= SWITCHES;	/* enable interrupts from switches */
  P2OUT |= SWITCHES;	/* pull-ups for switches */
  P2DIR &= ~SWITCHES;	/* set switches' bits for input */
  
  switch_update_interrupt_sense();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  if ((p2val & SW1) ? 0 : 1) {
    set_state(ALTERNATING);
  } else if ((p2val & SW2) ? 0 : 1) {
    set_state(METAL_CRUSHER);
  } else if ((p2val & SW3) ? 0 : 1) {
    set_state(SIREN);
  } else if ((p2val & SW4) ? 0 : 1) {
    set_state(BLINKING);
  }
}
