#ifndef buzzer_included
#define buzzer_included

#define D5Sharp 622
#define B4 493
#define B3 246
#define D3Sharp 155
#define G3Sharp 207
#define E5 659
#define C5Sharp 554
#define A4Sharp 466
#define G4Sharp 415

typedef struct {
  unsigned short key;
  unsigned short duration;
} Note;

void buzzer_init();
void buzzer_set_period(short cycles);

#endif // included
