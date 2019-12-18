#ifndef GPIO_H_
#define GHIO_H_

#include "../avratmega32.h"
#include "../../UTILS/macros.h"
#include "../../UTILS/datatypes.h"

/* **************  Port Direction  ************** */
U8 GPIO_PortDir(U8 portBase, U8 dir);

U8 GPIO_PinDir(U8 portBase, U8 pin, U8 dir);

U8 GPIO_PortRangeDir(U8 portBase, U8 startPin, U8 endPin, U8 dir);

U8 GPIO_PortMaskDir(U8 portBase, U8 mask, U8 dir);

/* **************  Writing to Port  ************** */

U8 GPIO_PortWrite(U8 portBase, U8 val );

U8 GPIO_PinWrite(U8 portBase, U8 pin, U8 val);

U8 GPIO_PortRangeWrite(U8 portBase, U8 startPin, U8 endPin, U8 val);

U8 GPIO_PortMaskWrite(U8 portBase, U8 mask, U8 val);

/* **************  Reading Port value  ************** */
U8 GPIO_PortRead(U8 portBase, U8 *portVal );

U8 GPIO_PinRead(U8 portBase, U8 pin, U8 *pinVal);

U8 GPIO_PortRangeRead(U8 portBase, U8 startPin, U8 endPin, U8 *rangeReadVal);

U8 GPIO_PortMaskRead(U8 portBase, U8 mask, U8 *binaryIndividuals_readVal);

/* **************  Toggle Port Value  ************** */

U8 GPIO_PortToggle(U8 portBase);

U8 GPIO_PinToggle(U8 portBase, U8 pin);

U8 GPIO_PortRangeToggle(U8 portBase, U8 startPin, U8 endPin);

U8 GPIO_PortMaskToggle(U8 portBase, U8 mask);


#endif