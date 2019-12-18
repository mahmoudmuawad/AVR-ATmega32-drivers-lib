#ifndef TIMER0_H_
#define TIMER0_H_

#ifndef F_CPU
	#define F_CPU 8000000UL
#endif

#include "../GPIO/gpio.h"
#include <avr/interrupt.h>

volatile U16 n_overflows;  // define numbers of overflows

void TMR0_delay_normal_ms(U16 t); // change it to U16
//void TMR0_delay_CTC_ms(U16 t);
void TMR0_delay_INT_ms(U16 t);

#endif