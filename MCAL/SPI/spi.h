#ifndef SPI_H
#define SPI_H

#include "../GPIO/gpio.h"

#ifndef F_CPU
#define F_CPU 8000000ul
#endif

#define MOSI_PIN 5
#define MOSI_PORT_BASE B

#define SCK_PIN  7 
#define SCK_PORT_BASE B

#define MISO_PIN 6
#define MISO_PORT_BASE B

#define REC_ON_PORT_BASE A  // recieved data will be displayed on port A

void SPI_master_init();
void SPI_slave_init();

void SPI_transmit(U8);
U8 SPI_receive();

#endif