
#include "gpio.h"

/* **************  Port Direction  ************** */

U8 GPIO_PortDir(U8 portBase, U8 dir){
	U8 pins_changed = 0;
	if(IS_PORT(portBase) && IS_DIR(dir)){
		DDR(portBase) =  (dir == OUTPUT)? 0xFF : 0x00;
		pins_changed = 8;
	}
	return pins_changed;	
}

U8 GPIO_PinDir(U8 portBase, U8 pin, U8 dir){
	U8 pins_changed = 0;
	if(IS_PORT(portBase) &&	IS_PIN(portBase) && IS_DIR(dir)){
		if(dir == OUTPUT)
			SET_BIT(DDR(portBase), pin);
		else
			CLR_BIT(DDR(portBase), pin);
		pins_changed = 1;
	}
	return pins_changed;
}

U8 GPIO_PortRangeDir(U8 portBase, U8 startPin, U8 endPin, U8 dir){
	U8 pins_changed = 0, i;
	if(IS_PORT(portBase) && IS_PIN(startPin) && IS_PIN(endPin) && IS_DIR(dir)){
		for(i = startPin; i <= endPin; i++)
			GPIO_PinDir(portBase, i, dir);
		pins_changed = endPin - startPin + 1;
	}
	return pins_changed;
}

U8 GPIO_PortMaskDir(U8 portBase, U8 mask, U8 dir){
	U8 pins_changed = 0, i;
	if(IS_PORT(portBase) && IS_MASK(mask) && IS_DIR(dir)){
		for(i = 0; i < 8; i++){
			if(READ_BIT(mask, i)){
				GPIO_PinDir(portBase, i, dir);
				pins_changed++;	
			}
		}
	}
	return pins_changed;
}

/* **************  Writing to Port  ************** */

U8 GPIO_PortWrite(U8 portBase, U8 val ){
	U8 pins_changed = 0;
	if(IS_PORT(portBase) && IS_DIR(val)){
		PORT(portBase) =  (val == HIGH)? 0xFF : 0x00;
		pins_changed = 8;
	}
	return pins_changed;
}

U8 GPIO_PinWrite(U8 portBase, U8 pin, U8 val){
	U8 pins_changed = 0;
	if(IS_PORT(portBase) &&	IS_PIN(portBase) && IS_DIR(val)){
		if(val == HIGH)
			SET_BIT(PORT(portBase), pin);
		else
			CLR_BIT(PORT(portBase), pin);
		pins_changed = 1;
	}
	return pins_changed;	
}

U8 GPIO_PortRangeWrite(U8 portBase, U8 startPin, U8 endPin, U8 val){
	U8 pins_changed = 0, i;
	if(IS_PORT(portBase) && IS_PIN(startPin) && IS_PIN(endPin) && IS_DIR(val)){
		for(i = startPin; i <= endPin; i++)
			GPIO_PinWrite(portBase, i, val);
		pins_changed = endPin - startPin + 1;
	}
	return pins_changed;	
}

U8 GPIO_PortMaskWrite(U8 portBase, U8 mask, U8 val){
	U8 pins_changed = 0, i;
	if(IS_PORT(portBase) && IS_MASK(mask) && IS_DIR(val)){
		for(i = 0; i < 8; i++){
			if(READ_BIT(mask, i)){
				GPIO_PinWrite(portBase, i, val);
				pins_changed++;
			}
		}
	}
	return pins_changed;
}

/* **************  Reading Port value  ************** */

U8 GPIO_PortRead(U8 portBase, U8 *portVal ){
	U8 pins_read = 0;
	if(IS_PORT(portBase)){
		*portVal = PIN(portBase) & 0xFF;
		pins_read = 8;
	}
	return pins_read;	
}
U8 GPIO_PinRead(U8 portBase, U8 pin, U8 *pinVal){
	U8 pins_read = 0;
	if(IS_PORT(portBase) && IS_PIN(pin)){
		*pinVal = READ_BIT(PIN(portBase), pin);
		pins_read = 1;
	}
	return pins_read;
}

U8 GPIO_PortRangeRead(U8 portBase, U8 startPin, U8 endPin, U8 *rangeReadVal){
	U8 pins_read = 0, i;
	if(IS_PORT(portBase) && IS_PIN(startPin) && IS_PIN(endPin)){
		*rangeReadVal = 0x00;
		for(i = startPin; i <= endPin; i++){
			if(READ_BIT(PIN(portBase), i))
				SET_BIT(*rangeReadVal, i);
			else
				CLR_BIT(*rangeReadVal, i);
		}
		pins_read = endPin - startPin + 1;
	}
	return pins_read;
}

U8 GPIO_PortMaskRead(U8 portBase, U8 mask, U8 *binaryIndividuals_readVal){
	U8 pins_read = 0, i;
	if(IS_PORT(portBase) && IS_MASK(mask)){
		*binaryIndividuals_readVal = 0x00;
		for (i = 0; i < 8; i++){
			if(READ_BIT(PIN(portBase), i)){
				if(READ_BIT(PIN(portBase), i))
					SET_BIT(*binaryIndividuals_readVal, HIGH);
				else
					CLR_BIT(*binaryIndividuals_readVal, LOW);
				pins_read++;
			}
		}
	}
	return pins_read;
}

/* **************  Toggle Port Value  ************** */

U8 GPIO_PortToggle(U8 portBase){
	U8 pins_changed = 0;
	if(PORT(portBase)){
		PORT(portBase) ^= 0xFF;
		pins_changed = 8;
	}
	return pins_changed;
}

U8 GPIO_PinToggle(U8 portBase, U8 pin){
	U8 pins_changed = 0;
	if(IS_PORT(portBase) && IS_PIN(pin)){
		TOG_BIT(PORT(portBase), pin);
		pins_changed = 1;
	}
	return pins_changed;
}

U8 GPIO_PortRangeToggle(U8 portBase, U8 startPin, U8 endPin){
	U8 pins_changed = 0, i;
	if(IS_PORT(portBase) && IS_PIN(startPin) && IS_PIN(endPin)){
		for(i = startPin; i <= endPin; i++)
			TOG_BIT(PORT(portBase), i);
		pins_changed = endPin - startPin + 1;
	}
	return pins_changed;
}

U8 GPIO_PortMaskToggle(U8 portBase, U8 mask){
	U8 pins_changed = 0, i;
	if(IS_PORT(portBase) && IS_MASK(mask)){
		for(i = 0; i < 8; i++){
			if(READ_BIT(mask, i)){
				TOG_BIT(PORT(portBase), i);
				pins_changed++;
			}
		}
	}
	return pins_changed;
}