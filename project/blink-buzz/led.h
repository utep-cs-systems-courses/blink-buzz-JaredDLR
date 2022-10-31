#ifndef led_included
#define  led_included

#define LED_GREEN BIT0     // P1.0
#define LED_RED BIT6       // P1.6
#define LEDS (BIT0 | BIT6)

void led_init();
void toggle_green(unsigned char flag);
void toggle_red(unsigned char flag);

#endif
