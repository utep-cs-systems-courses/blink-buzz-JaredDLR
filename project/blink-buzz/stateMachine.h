#ifndef stateMachine_included
#define stateMachine_included

typedef enum {
  IDLE,
  ALTERNATING,
  METAL_CRUSHER,
  SIREN,
  BLINKING
} State;

void set_state(State state);
void advance_state();

#endif
