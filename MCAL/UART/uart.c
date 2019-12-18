#include "uart.h"

void UART_init(U16 buad_rate){
	UBRRL=(F_CPU/(16*buad_rate))-1;   
	UCSRB |= (1<<TXEN)|(1<<RXEN);   // enable transmitter and reciever 
	UCSRC |=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);  // 8bit char 
}

void UART_write(U8 ch){
	while(READ_BIT(UCSRA,UDRE)==0); // wait as log as UDRE is 0 , when this bit bit is set it will move to the next statement 
	UDR = ch; 
}

void UART_write_string(U8 *str){
	while(*str)
		UART_write(*str++);
}

U8 UART_read(){
	while(READ_BIT(UCSRA, RXC)==0);
	return UDR;
}