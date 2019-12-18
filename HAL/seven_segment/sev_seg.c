#include "sev_seg.h"

void static sev_seg_init(){
	GPIO_PortRangeDir(PORT_BASE_7, EN0, D_7, OUTPUT);
	GPIO_PortRangeWrite(PORT_BASE_7, A_7, D_7, LOW);
}

void get_num(U8 num){
	if(IS_NUM(num)){
		U8 pin_arr[4] = {A_7, B_7, C_7, D_7}, i;
		sev_seg_init();
		
		GPIO_PinWrite(PORT_BASE_7, EN0, HIGH);
		GPIO_PinWrite(PORT_BASE_7, EN1, LOW);
		for(i = 0; i < 4; i++){
			if(READ_BIT((num % 10), pin_arr[i]))
				GPIO_PinWrite(PORT_BASE_7, pin_arr[i], HIGH);	
			else 
				GPIO_PinWrite(PORT_BASE_7, pin_arr[i], LOW);
		}
		
		_delay_ms(1);
		
		GPIO_PinWrite(PORT_BASE_7, EN0, LOW);
		GPIO_PinWrite(PORT_BASE_7, EN1, HIGH);
		for(i = 0; i < 4; i++){
			if(READ_BIT((num / 10), pin_arr[i]))
				GPIO_PinWrite(PORT_BASE_7, pin_arr[i], HIGH);
			else
				GPIO_PinWrite(PORT_BASE_7, pin_arr[i], LOW);
		}		
	}
}