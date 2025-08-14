#ifndef BIT_MATH_H
#define BIT_MATH_H


#define GIT_BIT(register,pin)   register&(1<<pin)
#define SET_BIT(register,pin)   register|=(1<<pin)
#define CLEAR_BIT(register,pin)   register &=~(1<<pin)
#define TOGGLE_BIT(register,pin)  register^=(1<<pin)

#endif