#include "adc.h"

void static ADC_init(){
	ADCSRA = 0x87;   // make ADC enabled and select ck/128
	ADMUX = 0x04;    // select AREF and left-justified and single ended input 
}

U16 ADC_read_poll(U8 single_pin){
	ADC_init();
	ADMUX |= single_pin;   // check MAZIDI page 472 table 13-5
	SET_BIT(ADCSRA, 6);    // start ADC conversion 
	while(READ_BIT(ADCSRA, 4) == 0);    // wait until conversion completed and ADIF set to 1
	return (ADCL+ (ADCH << 8));
}

