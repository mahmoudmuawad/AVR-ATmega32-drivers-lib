#include "i2c.h"

void I2C_master_init(){
	(READ_BIT(PRESCALER_PW,0))?SET_BIT(TWSR, 0):CLR_BIT(TWSR, 0);
	(READ_BIT(PRESCALER_PW,1))?SET_BIT(TWSR, 1):CLR_BIT(TWSR, 1);
	U32 cal = (F_CPU/F_SCK-16)/2*pow(4,PRESCALER_PW);
	TWBR=(U8)cal;
	SET_BIT(TWCR,TWEN);
}

void I2C_start(){
	TWCR |=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(READ_BIT(TWCR,TWINT)==0);  // wait till sending start pulse complete
}

void I2C_master_transmit(U8 ch){
	TWDR=ch;
	TWCR|=(1<<TWEN)|(1<<TWINT);
	while(READ_BIT(TWCR,TWINT)==0);
}

U8 I2C_read(U8 single_byte){         // valid for both master or slave 
	if(single_byte==0)      // in case of reading more than single byte 
		TWCR|=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	else				// in case of reading single byte 
		TWCR|=(1<<TWEN)|(1<<TWINT);
	while(READ_BIT(TWCR, TWINT)==0);
	return TWDR;
}

void I2C_stop(){
	TWCR |=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}


void I2C_slave_init(U8 slave_address){
	SET_BIT(TWCR,TWEN);
	TWAR=slave_address;
	TWCR|=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);     // listen to the adress 
}

void I2C_slave_transmit(U8 ch){
	TWDR=ch;
	TWCR|=(1<<TWEN)|(1<<TWINT);
	while(READ_BIT(TWCR,TWINT)==0);
}