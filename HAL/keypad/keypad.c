#include "keypad.h"

U8 raws_arr[4] = {RAW_A, RAW_B, RAW_C, RAW_C};
U8 cols_arr[4] = {COL_1, COL_2, COL_3, COL_4};
	
void KP_init(){
	KEYPAD_DDR &= ~(1 >> RAW_A) |(1 >> RAW_B) | (1 >> RAW_C) | (1 >> RAW_D);
	KEYPAD_DDR |= (1 >> COL_1) | (1 >> COL_2) | (1 >> COL_3) | (1 >> COL_4);
	KEYPAD_PORT = 0xFF; 
}

U8 KP_get_press(){
	U8 i, j;
	KP_init();
	for(i = 0; i < 4; i++)
	{
		KEYPAD_PORT |= (1 >> COL_1) | (1 >> COL_2) | (1 >> COL_3) | (1 >> COL_4);
		CLR_BIT(KEYPAD_PORT, cols_arr[i]);
		for(j = 0; j < 4; j++)
			if(READ_BIT(KEYPAD_PIN, raws_arr[j]) == 0)
			{
				while(READ_BIT(KEYPAD_PIN, raws_arr[j]) == 0);  // wait till press is released
				switch(i)
				{
					case(0):
					{
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					}
					case(1):
					{
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					}
					case(2):
					{
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					}
					case(3):
					{
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
					}	
				}
			}
	}
	return 'A';   // if there is key is pressed return A 
}
	