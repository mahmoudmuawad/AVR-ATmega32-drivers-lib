#ifndef MACROS_H_
#define MACROS_H_

#define CLR_BIT(reg, pin)   (reg &=~(1 << pin))
#define SET_BIT(reg, pin)   (reg |= (1 << pin))
#define READ_BIT(reg, pin)  ((reg &(1 << pin)) >> pin)
#define TOG_BIT(reg, pin)   (reg ^= (1 << pin))


#endif