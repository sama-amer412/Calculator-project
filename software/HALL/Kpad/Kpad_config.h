#ifndef KPAD_CONFIG_H
#define KPAD_CONFIG_H
#include"../../Lib/Bit_math.h"
#include"../../Lib/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_interface.h"

#define Kpad_port      PORTD


#define Kpad_C0         PIN4
#define Kpad_C1         PIN5 
#define Kpad_C2         PIN6 
#define Kpad_C3         PIN7 

#define Kpad_R0         PIN0
#define Kpad_R1         PIN1 
#define Kpad_R2         PIN2 
#define Kpad_R3         PIN3 

#define Kpad_col_num  4
#define Kpad_row_num  4
 
#define KPAD_KEYS {{'7','8','9','/'}, {'4','5','6','*'}, {'1','2','3','-'}, {'c','0','=','+'}}

#endif 

