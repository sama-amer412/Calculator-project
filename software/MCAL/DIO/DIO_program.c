#include"DIO_private.h"
#include"DIO_interface.h"
#include"../../Lib/Bit_math.h"
#include"../../Lib/STD_TYPES.h"


void DIO_SetPinDirection(u8 copy_of_portNumber,u8 copy_of_pinNumber,u8 direction){

    if (copy_of_portNumber>PORTD || copy_of_pinNumber>PIN7){
        //Do nothing
    }
    else{
        switch (direction)
        {
        case INPUT:
            switch (copy_of_portNumber)
            {
            case PORTA:CLEAR_BIT(DDRA_REG,copy_of_pinNumber); break;
            case PORTB:CLEAR_BIT(DDRB_REG,copy_of_pinNumber); break;
            case PORTC:CLEAR_BIT(DDRC_REG,copy_of_pinNumber); break;
            case PORTD:CLEAR_BIT(DDRD_REG,copy_of_pinNumber); break;

            }
            break;
         
        case OUTPUT:
            switch (copy_of_portNumber)
            {
            case PORTA:SET_BIT(DDRA_REG,copy_of_pinNumber); break;
            case PORTB:SET_BIT(DDRB_REG,copy_of_pinNumber); break;
            case PORTC:SET_BIT(DDRC_REG,copy_of_pinNumber); break;
            case PORTD:SET_BIT(DDRD_REG,copy_of_pinNumber); break;

            }
            break;
            
        default:
            break;
        }
    }

}
void DIO_SetPinValue(u8 copy_of_portNumber,u8 copy_of_pinNumber,u8 Value){
    if (copy_of_portNumber>PORTD || copy_of_pinNumber>PIN7){
      //Do nothing
    }
    else{
        switch (Value)
        {
        case LOW:
            switch (copy_of_portNumber)
            {
            case PORTA:CLEAR_BIT(PORTA_REG,copy_of_pinNumber); break;
            case PORTB:CLEAR_BIT(PORTB_REG,copy_of_pinNumber); break;
            case PORTC:CLEAR_BIT(PORTC_REG,copy_of_pinNumber); break;
            case PORTD:CLEAR_BIT(PORTD_REG,copy_of_pinNumber); break;

            }
            break;
         
        case HIGH:
            switch (copy_of_portNumber)
            {
            case PORTA:SET_BIT(PORTA_REG,copy_of_pinNumber); break;
            case PORTB:SET_BIT(PORTB_REG,copy_of_pinNumber); break;
            case PORTC:SET_BIT(PORTC_REG,copy_of_pinNumber); break;
            case PORTD:SET_BIT(PORTD_REG,copy_of_pinNumber); break;

            }
            break;
            
        default:
            break;
        }

    }
}

void DIO_SetPortDirection(u8 copy_of_portNumber,u8 direction){

    if ( copy_of_portNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
    
    switch(direction){
        case INPUT:
            switch(copy_of_portNumber){
                case PORTA:  DDRA_REG=0x00;    break;
                case PORTB:  DDRB_REG=0x00;    break;
                case PORTC:  DDRC_REG=0x00;    break;
                case PORTD:  DDRD_REG=0x00;    break;
                default   :                    break;

            }
            break;

        case OUTPUT:
            switch(copy_of_portNumber){
                case PORTA:  DDRA_REG=0xff;    break;
                case PORTB:  DDRB_REG=0xff;    break;
                case PORTC:  DDRC_REG=0xff;    break;
                case PORTD:  DDRD_REG=0xff;    break;
                default   :                    break;

            }
            break;
        default:
            break;    

        }
    }   
}

void DIO_SetPortValue(u8 copy_of_portNumber,u8 Value){
    if ( copy_of_portNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {   
   
    switch(copy_of_portNumber)
        {
            case PORTA: PORTA_REG = Value;
                        break;
    
            case PORTB: PORTB_REG = Value;
                        break;
    
            case PORTC: PORTC_REG = Value;
                        break;
    
            case PORTD: PORTD_REG = Value;
                        break;
            default:
                        break;
        }
    }
}

u8 DIO_GetPinValue (u8 Copy_PortNumber, u8 Copy_PinNumber )
{
    u8 Local_Variable;
    
    if ( Copy_PortNumber > PORTD || Copy_PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_PortNumber)
        {
            case PORTA :    Local_Variable = GIT_BIT( PINA_REG ,Copy_PinNumber );   break;   
            case PORTB :    Local_Variable = GIT_BIT( PINB_REG ,Copy_PinNumber );   break;
            case PORTC :    Local_Variable = GIT_BIT( PINC_REG ,Copy_PinNumber );   break;
            case PORTD :    Local_Variable = GIT_BIT( PIND_REG ,Copy_PinNumber );   break;
            default :                                                               break;
        }
    }
    return Local_Variable ;
}

void DIO_Pull_Up_Pin (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_u8PullUpStatus )
{
    
    if ( Copy_u8PortNumber > PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
       switch(Copy_u8PullUpStatus)
       {
            case ON  :   DIO_SetPinValue (Copy_u8PortNumber,Copy_u8PinNumber, HIGH );   break;
            case OFF :   DIO_SetPinValue (Copy_u8PortNumber,Copy_u8PinNumber, LOW  );   break; 
            default  :                                                                      break; 
       }
    }    
}