#ifndef BUTTON_INTERFACE-H
#define BUTTON_INTERFACE-H

#include"../../MCAL/DIO/DIO_interface.h"
#include"../../Lib/Bit_math.h"
#include"../../Lib/STD_TYPES.h"

u8 Button_GetPin(u8 Portnumber, u8 Pinnumber );
void BUTTON_Init_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_u8PullUpStatus );


#endif