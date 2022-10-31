#include <msp430.h>
#include "stateMachine.h"
#include "alternatingStateMachine.h"
#include "metalCrusherStateMachine.h"

static State current_state;

void set_state(State state)
{
  switch (state) {
  case ALTERNATING:
    current_state = ALTERNATING;
    break;

  case METAL_CRUSHER:
    current_state = METAL_CRUSHER;
    break;

  default:
    current_state = IDLE;
    break;
  }
}

void advance_state()
{
  switch (current_state) {
  case ALTERNATING:
    advance_alternation();
    break;

  case METAL_CRUSHER:
    advance_metal_crusher();
    break;
  }
}
