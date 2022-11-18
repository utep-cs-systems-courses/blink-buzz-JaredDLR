#ifndef buzzer_included
#define buzzer_included

#define E5Flat 3215
#define E4Flat 6430
#define B3 8130
#define E3Flat 12903
#define E2Flat 25974
#define A2Flat 19417
#define G5Flat 2706
#define B5Flat 2145
#define E6 1517
#define E6Flat 1607
#define D6Flat 1805
#define B5 2026
#define B5Flat 2145
#define A5Flat 2409
#define E5 3034
#define D5Flat 3610
#define B4Flat 4219
#define A6Flat 1204
#define G5 2554
#define D5 3407
#define C6 1912
#define D6 1703
#define C6Sharp 1805
#define A5 2272
#define G6Flat 1351
#define G6 1275

typedef struct {
  short key;
  unsigned short duration;
  unsigned short delay;
} Note;

void buzzer_init();
void buzzer_set_period(short cycles);

#endif // included
