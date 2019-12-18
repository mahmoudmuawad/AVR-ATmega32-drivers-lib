#ifndef SEG_SEG_H_
#define SEG_SEG_H_

#include "../../MCAL/GPIO/gpio.h"
#include <util/delay.h>

// configuration of 7-seg decoder
#define PORT_BASE_7 C
#define	EN0			2
#define EN1			3
#define A_7			4
#define B_7			5
#define C_7			6
#define D_7			7

#define IS_NUM(x) ((x) >=0 && (x) <= 99)

void get_num(U8 num);

#endif