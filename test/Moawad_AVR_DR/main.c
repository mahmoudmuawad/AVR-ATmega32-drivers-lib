#include "MCAL/GPIO/gpio.h"
#define F_CPU 8000000UL

int main(void)
{
	// uncomment to test GPIO driver on Amit kit 
	//GPIO_PortDir(D, OUTPUT);
    while (1) 
    {
		//GPIO_PortWrite(D, HIGH);
		/* uncomment to test GPIO driver functions 
		GPIO_PortDir(A, INPUT);
		GPIO_PinDir(A, 2, OUTPUT);
		GPIO_PortRangeDir(B, 0,  4, INPUT);
		GPIO_PortMaskDir(C, 0x00011000, OUTPUT);
		
		GPIO_PortWrite(B, HIGH);
		GPIO_PinWrite(B, 4, LOW);
		GPIO_PortRangeWrite(B, 2, 4, HIGH);
		GPIO_PortMaskWrite(B, 0x01010110, LOW);	
		
		U8 portVal, pinVal, rangeReadVal, binaryIndividuals_readVal;
		GPIO_PortRead(A, &portVal );
		GPIO_PinRead(A, 1, &pinVal);
		GPIO_PortRangeRead(A, 1, 3,&rangeReadVal);
		GPIO_PortMaskRead(A, 0x00110101, &binaryIndividuals_readVal);
		
		GPIO_PortToggle(C);
		GPIO_PinToggle(D, 1);
		GPIO_PortRangeToggle(C, 0, 5);
		GPIO_PortMaskToggle(D, 0x00010011);
		*/
		
    }
	return 0;
}

