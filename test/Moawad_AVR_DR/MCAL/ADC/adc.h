#ifndef ADC_H_
#define ADC_H_

#include "../GPIO/gpio.h"
#include <avr/interrupt.h>


U16 ADC_read_poll(U8);
//U16 ADC_read_inter(U8);

#endif