#ifndef DIO_interface_H
#define DIO_interface_H
#include"../../Lib/STD_TYPES.h"


void DIO_SetPinDirection(u8 copy_of_portNumber,u8 copy_of_pinNumber,u8 direction);
void DIO_SetPinValue(u8 copy_of_portNumber,u8 copy_of_pinNumber,u8 Value);
void DIO_SetPortDirection(u8 copy_of_portNumber,u8 direction);
void DIO_SetPortValue(u8 copy_of_portNumber,u8 Value);
u8 DIO_GetPinValue (u8 Copy_PortNumber, u8 Copy_PinNumber );
void DIO_Pull_Up_Pin (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_u8PullUpStatus );



#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3



#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define INPUT  0
#define OUTPUT 1

#define LOW    0
#define HIGH   1

#define OFF                      0
#define ON                       1


#endif