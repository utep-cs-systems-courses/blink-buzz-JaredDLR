#include "<msp430.h>"
#include "buzzer.h"

static const Note notes = {
  { D5Sharp, 150 },
  { D5Sharp, 50 },
  { B4, 100 },
  { B4, 100 },
  { B3, 150 },
  { B3, 50 },
  { D3Sharp, 200 },
  { D3Sharp, 150 },
  { D3Sharp, 50 },
  { D3Sharp, 100 },
  { D3Sharp, 100 },
  { G3Sharp, 1000 }
};

void advanceMetalCrusher()
{
  static unsigned short char note = 0;
  static unsigned short int duration = 0;

  if (note < 12) {
    if (duration-- <= 0) {
      buzzer_set_period(notes[note].key);
      duration = notes[note].duration;
      note++;
    }
  } else {
    note = 0;
  }
}
