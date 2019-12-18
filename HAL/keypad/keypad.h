#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../MCAL/GPIO/gpio.h"

// keypad configuration
#define KEYPAD_DDR	DDRB 
#define KEYPAD_PORT PORTB
#define KEYPAD_PIN  PINB
 
#define RAW_A 0
#define RAW_B 1
#define RAW_C 2
#define RAW_D 3

#define COL_1 4
#define COL_2 5
#define COL_3 6
#define COL_4 7

void KP_init();
U8 KP_press();

#endif