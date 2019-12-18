#include "spi.h"

void SPI_master_init(){
	SET_BIT(DDR(MOSI_PORT_BASE),MOSI_PIN);
	SET_BIT(DDR(SCK_PORT_BASE),SCK_PIN);
	SPCR |=(1<<MSTR)|(1<<SPE);   // spi enable , master mode , shift clock F_CPU/4
}

void SPI_slave_init(){
	SET_BIT(DDR(MISO_PORT_BASE),MISO_PIN);
	SET_BIT(SPCR,SPE);
}

void SPI_transmit(U8 ch){
	SPDR = ch;
	while(READ_BIT(SPSR,SPIF)==0);   // wait till transmitting finished 
}

U8 SPI_receive(){
	while(READ_BIT(SPSR,SPIF)==0);   // wait till transmitting finished
	return SPDR;
}