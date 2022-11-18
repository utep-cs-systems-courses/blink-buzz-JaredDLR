#include <msp430.h>
#include "stateMachine.h"
#include "alternatingStateMachine.h"
#include "metalCrusherStateMachine.h"
#include "sirenStateMachine.h"
#include "blinkingStateMachine.h"

static State current_state;

void set_state(State state)
{
  switch (state) {
  case ALTERNATING:
    if (current_state != ALTERNATING) {
      reset_metal_crusher();
      reset_siren();
      reset_blinking();
    }
    break;
  case METAL_CRUSHER:
    if (current_state != METAL_CRUSHER) {
      reset_alternation();
      reset_siren();
      reset_blinking();
    }
    break;
  case SIREN:
    if (current_state != SIREN) {
      reset_alternation();
      reset_metal_crusher();
      reset_blinking();
    }
    break;
  case BLINKING:
    if (current_state != BLINKING) {
      reset_alternation();
      reset_metal_crusher();
      reset_siren();
    }
  }

  current_state = state;
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
  case SIREN:
    advance_siren();
    break;
  case BLINKING:
    advance_blinking();
  }
}
