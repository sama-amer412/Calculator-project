#include"../../MCAL/DIO/DIO_interface.h"
#include"../../Lib/Bit_math.h"
#include"../../Lib/STD_TYPES.h"

u8 Button_GetPin(u8 Portnumber, u8 Pinnumber )
{
    u8 Local_Value=1  ;
    
    if ( Portnumber > PORTD || Pinnumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {   
        Local_Value = DIO_GetPinValue ( Portnumber,  Pinnumber ) ;
    }
    return Local_Value ;
}

void BUTTON_Init_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_u8PullUpStatus )
{
    
    if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {   
        DIO_SetPinDirection (Copy_u8PortNumber,Copy_u8PinNumber,INPUT);
        
        DIO_Pull_Up_Pin (Copy_u8PortNumber,Copy_u8PinNumber, Copy_u8PullUpStatus );
    }
}