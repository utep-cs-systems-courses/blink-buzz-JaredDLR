#include <msp430.h>
#include "buzzer.h"

static char play_sound;
static int note;
static int delay;

static const Note notes[] = {
  { E5Flat, 96, 4 },	/* Measure 1 */
  { E5Flat, 32, 4 },
  { E4Flat, 64, 4 },
  { E4Flat, 64, 4 },
  { B3, 96, 4 },
  { B3, 32, 4 },
  { E3Flat, 129, 4 },
  { E2Flat, 96, 4 },	/* Measure 2 */
  { E2Flat, 32, 4 },
  { E2Flat, 64, 4 },
  { E2Flat, 64, 4 },
  { A2Flat, 258, 4 },
  { E5Flat, 4, 2 },	/* Measure 3 */
  { G5, 2, 2 },
  { B5Flat, 2, 2 },
  { E6, 64, 4 },
  { E6Flat, 32, 4 },
  { D6Flat, 32, 4 },
  { E6Flat, 64, 4 },
  { D6Flat, 32, 4 },
  { B5, 32, 4 },
  { B5Flat, 64, 4 },
  { A5Flat, 32, 4 },
  { G5Flat, 32, 4 },
  { A5Flat, 64, 4 },
  { E5Flat, 32, 4 },
  { E5, 32, 4 },
  { E5Flat, 32, 4 },	/* Meaure 4 */
  { E5, 32, 4 },
  { E5Flat, 32, 4 },
  { D5, 32, 4 },
  { E5Flat, 32, 4 },
  { G5, 32, 4 },
  { B5, 32, 4 },
  { B5Flat, 32, 4 },
  { A5Flat, 64, 4 },
  { A5Flat, 32, 4 },
  { B5Flat, 32, 4 },
  { B5, 64, 4 },
  { B5Flat, 32, 4 },
  { B5, 32, 4 },
  { C6, 4, 2 },		/* Measure 5 */
  { D6Flat, 64, 4 },
  { B5, 32, 4 },
  { B5Flat, 32, 4 },
  { G5, 64, 4 },
  { G5Flat, 32, 4 },
  { B5Flat, 32, 4 },
  { B5, 64, 4 },
  { B5Flat, 32, 4 },
  { A5Flat, 32, 4 },
  { E5Flat, 64, 4 },
  { E5Flat, 32, 4 },
  { E5, 32, 4 },
  { E5Flat, 32, 4 },	/* Measure 6*/
  { D5, 32, 4 },
  { E5Flat, 32, 4 },
  { E5, 32, 4 },
  { E5Flat, 32, 4 },
  { B4Flat, 32, 4 },
  { B5, 32, 4 },
  { B5Flat, 32, 4 },
  { A5Flat, 64, 4 },
  { A5Flat, 32, 4 },
  { G5, 32, 4 },
  { A5Flat, 64, 4 },
  { A6Flat, 64, 4 },
  { E5Flat, 4, 2 },	/* Measure 7 */
  { G5, 2, 2 },
  { B5Flat, 2, 2 },
  { E6, 64, 4 },
  { E6Flat, 32, 4 },
  { D6Flat, 32, 4 },
  { E6Flat, 64, 4 },
  { D6Flat, 32, 4 },
  { B5, 32, 4 },
  { B5Flat, 64, 4 },
  { A5Flat, 32, 4 },
  { G5Flat, 32, 4 },
  { A5Flat, 64, 4 },
  { E5Flat, 32, 4 },
  { E5, 32, 4 },
  { E5Flat, 32, 4 },	/* Measure 8 */
  { E5, 32, 4 },
  { E5Flat, 32, 4 },
  { D5, 32, 4 },
  { E5Flat, 32, 4 },
  { G5, 32, 4 },
  { B5, 32, 4 },
  { B5Flat, 32, 4 },
  { A5Flat, 64, 4 },
  { A5Flat, 32, 4 },
  { B5Flat, 32, 4 },
  { B5, 64, 4 },
  { B5Flat, 32, 4 },
  { B5, 32, 4 },
  { C6, 4, 2 },		/* Measure 9 */
  { D6Flat, 64, 4 },
  { B5, 32, 4 },
  { B5Flat, 32, 4 },
  { G5Flat, 64, 4 },
  { G5Flat, 32, 4 },
  { B5Flat, 32, 4 },
  { B5, 64, 4 },
  { B5Flat, 32, 4 },
  { A5Flat, 32, 4 },
  { E5Flat, 64, 4 },
  { E5Flat, 32, 4 },
  { E5, 32, 4 },
  { B4Flat, 32, 4 },	/* Measure 10 */
  { D5, 32, 4 },
  { E5Flat, 32, 4 },
  { E5, 32, 4 },
  { B4Flat, 32, 4 },
  { B4Flat, 32, 4 },
  { B5, 32, 4 },
  { B5Flat, 32, 4 },
  { A5Flat, 64, 4 },
  { A5Flat, 32, 4 },
  { G5, 32, 4 },
  { A5Flat, 32, 4 },
  { B5, 32, 4 },
  { D6Flat, 32, 4 },
  { E6Flat, 32, 4 },
  { E6, 193, 4 },	/* Measure 11 */
  { B5, 64, 4 },
  { A5Flat, 193, 4 },
  { E5, 64, 4 },
  { G5, 129, 4 },	/* Measure 12 */
  { E5Flat, 129, 4 },
  { E6Flat, 129, 4 },
  { D6, 129, 4 },
  { C6Sharp, 193, 4 },	/* Measure 13 */
  { A5, 64, 4 },
  { G5, 193, 4 },
  { E5Flat, 64, 4 },
  { A5Flat, 32, 4 },	/* Measure 14 */
  { G5, 32, 4 },
  { A5Flat, 64, 4 },
  { B5Flat, 32, 4 },
  { A5Flat, 32, 4 },
  { B5Flat, 64, 4 },
  { B5, 129, 4 },
  { B5, 32, 4 },
  { D6Flat, 32, 4 },
  { E6Flat, 32, 4 },
  { G6Flat, 32, 4 },
  { A6Flat, 193, 4 },	/* Measure 15*/
  { G6Flat, 64, 4 },
  { E6, 193, 4 },
  { E6Flat, 64, 4 },
  { D6, 129, 4 },	/* Measure 16 */
  { G6, 129, 4 },
  { B5Flat, 129, 4 },
  { E5Flat, 129, 4 },
  { D6Flat, 258, 4 },	/* Measure 17 */
  { D6Flat, 129, 4 },
  { E6, 129, 4 },
  { E6Flat, 226, 4 },	/* Measure 18 */
  { E6Flat, 16, 4 },
  { E6Flat, 16, 4 },
  { E6Flat, 32, 4 },
  { E6, 32, 4 },
  { E6Flat, 32, 4 },
  { D6, 32, 4 },
  { E6Flat, 32, 4 },
  { D6Flat, 32, 4 },
  { E6Flat, 32, 4 },
  { E6Flat, 32, 500}
};

void advance_metal_crusher()
{
  if (note < 168) {
    if (delay <= 0) {
      if (play_sound) {
	play_sound = 0;
	buzzer_set_period(0);
	delay = notes[note].delay;
	note++;
      } else {
	play_sound = 1;
	buzzer_set_period(notes[note].key);
	delay = notes[note].duration;
      }
    }

    delay--;
  } else {
    note = 0;
    delay = 0;
    buzzer_set_period(0);
  }
}

void reset_metal_crusher()
{
  play_sound = 0;
  note = 0;
  delay = 0;
  
  buzzer_set_period(0);
}
