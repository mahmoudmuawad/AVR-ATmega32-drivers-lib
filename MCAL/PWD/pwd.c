#include "pwd.h"

void static PWD_init(){
	TCCR0 |=(1<<6)|(1<<3)|(1<<5); // fast pwd , non-inverted
	SET_BIT(PORTB, OC0_PIN);
} 

void PWD_get_duty(U8 dt){
	PWD_init();
	OCR0 = (dt*256/100)-1;     // mazidi page 563
}