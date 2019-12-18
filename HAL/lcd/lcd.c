#include "lcd.h"

void static enable_pulse(){
	SET_BIT(LCD_EN_PORT, LCD_EN_PIN);
	_delay_ms(2);
	CLR_BIT(LCD_EN_PORT, LCD_EN_PIN);
	_delay_ms(3);
}

void static write_4_mode(U8 val){
	if(READ_BIT(val, LCD_D4_PIN)) SET_BIT(LCD_D4_PORT, LCD_D4_PIN); else CLR_BIT(LCD_D4_PORT, LCD_D4_PIN);
	if(READ_BIT(val, LCD_D5_PIN)) SET_BIT(LCD_D5_PORT, LCD_D5_PIN); else CLR_BIT(LCD_D5_PORT, LCD_D5_PIN);
	if(READ_BIT(val, LCD_D6_PIN)) SET_BIT(LCD_D6_PORT, LCD_D6_PIN); else CLR_BIT(LCD_D6_PORT, LCD_D6_PIN);
	if(READ_BIT(val, LCD_D7_PIN)) SET_BIT(LCD_D7_PORT, LCD_D7_PIN); else CLR_BIT(LCD_D7_PORT, LCD_D7_PIN);
	enable_pulse();
	if(READ_BIT(val, 0)) SET_BIT(LCD_D4_PORT, LCD_D4_PIN); else CLR_BIT(LCD_D4_PORT, LCD_D4_PIN);
	if(READ_BIT(val, 1)) SET_BIT(LCD_D5_PORT, LCD_D5_PIN); else CLR_BIT(LCD_D5_PORT, LCD_D5_PIN);
	if(READ_BIT(val, 2)) SET_BIT(LCD_D6_PORT, LCD_D6_PIN); else CLR_BIT(LCD_D6_PORT, LCD_D6_PIN);
	if(READ_BIT(val, 3)) SET_BIT(LCD_D7_PORT, LCD_D7_PIN); else CLR_BIT(LCD_D7_PORT, LCD_D7_PIN);
	enable_pulse();
}

void LCD_Write_Command(U8 command){
	CLR_BIT(LCD_RS_PORT, LCD_RS_PIN);
	CLR_BIT(LCD_RW_PORT, LCD_RW_PIN);
	write_4_mode(command);
}

void LCD_Go_To_X_Y(U8 row, U8 position){
	if(row == LCD_ROW_1)
		LCD_Write_Command(0x80 + position);
	else if(row == LCD_ROW_2)
		LCD_Write_Command(0xC0 + position);
		
}

void LCD_Write_Character(char  character){
	SET_BIT(LCD_RS_PORT, LCD_RS_PIN);
	CLR_BIT(LCD_RW_PORT, LCD_RW_PIN);
	write_4_mode(character);
}

void LCD_Write_String(char  *pointer){
	while(*pointer)
		LCD_Write_Character(*pointer++);
}

void LCD_Initialization(void){
	_delay_ms(10);
	SET_BIT(LCD_RS_DDR, LCD_RS_PIN);
	SET_BIT(LCD_RW_DDR, LCD_RW_PIN);
	SET_BIT(LCD_EN_DDR, LCD_EN_PIN);
	SET_BIT(LCD_D4_DDR, LCD_D4_PIN);
	SET_BIT(LCD_D5_DDR, LCD_D5_PIN);
	SET_BIT(LCD_D6_DDR, LCD_D6_PIN);
	SET_BIT(LCD_D7_DDR, LCD_D7_PIN);
	
	LCD_Write_Command(0x33);  /* Initialization */
	LCD_Write_Command(0x32);	/* Initialization */
	LCD_Write_Command(0x28);	/* Function Set: 4-bit, 2 Line, 5x7 Dots */
	LCD_Write_Command(0x0c);	/* Display on ,cursor off */
	LCD_Write_Command(0x01);  /* Clear display , Cursor home */
}