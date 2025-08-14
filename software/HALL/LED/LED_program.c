#include"../../Lib/STD_TYPES.h"
#include"../../Lib/Bit_math.h"
#include"../../MCAL/DIO/DIO_interface.h"

void LED_voidTurnOn(u8 copy_of_portNumber,u8 copy_of_pinNumber){
if (copy_of_portNumber>PORTD || copy_of_pinNumber>PIN7){
        //Do nothing
    }
else{

    DIO_SetPinDirection(copy_of_portNumber,copy_of_pinNumber,OUTPUT);
    DIO_SetPinValue(copy_of_portNumber,copy_of_pinNumber,HIGH);
}    

}



void LED_voidTurnOff(u8 copy_of_portNumber,u8 copy_of_pinNumber){
    if (copy_of_portNumber>PORTD || copy_of_pinNumber>PIN7){
        //Do nothing
    }
else{

    DIO_SetPinDirection(copy_of_portNumber,copy_of_pinNumber,OUTPUT);
    DIO_SetPinValue(copy_of_portNumber,copy_of_pinNumber,LOW);
}    
}


