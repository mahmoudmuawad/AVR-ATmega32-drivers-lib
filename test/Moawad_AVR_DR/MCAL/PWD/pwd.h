#ifndef PWD_H
#define PWD_H
#include "../GPIO/gpio.h"

#ifndef F_CPU
#define F_CPU 8000000ul
#endif

#define OC0_PIN 3

void PWD_get_duty(U8 dt);

#endif