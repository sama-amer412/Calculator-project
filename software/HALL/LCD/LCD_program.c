#include <util/delay.h>
#include"../../Lib/Bit_math.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"LCD_cofig.h"
#include"../../Lib/STD_TYPES.h"
#include"LCD_interface.h"
#include"LCD_private.h"
#include"../Button/Button_interface.h"



void LCD_init(void){
   DIO_SetPinDirection(CONTROL_PORT,E_PIN,OUTPUT);
   DIO_SetPinDirection(CONTROL_PORT,RS_PIN,OUTPUT);
   DIO_SetPinDirection(CONTROL_PORT,RW_PIN ,OUTPUT);
   DIO_SetPortDirection(DATA_PORT ,OUTPUT);
   
   _delay_ms(35);

   LCD_SendCommand(FUNCTION_SET);

   _delay_ms(1);
   LCD_SendCommand(DISPLAY_CONTROL);

   _delay_ms(1);
   LCD_SendCommand(DISPLAY_CLEAR);

   _delay_ms(2);
   LCD_SendCommand(ENTRY_MODE_SET);
   
}

void LCD_SendCommand(u8 command){

    DIO_SetPinValue(CONTROL_PORT,RS_PIN,LOW);
    DIO_SetPinValue(CONTROL_PORT,RW_PIN ,LOW);

    DIO_SetPortValue(DATA_PORT ,command);
    
    DIO_SetPinValue(CONTROL_PORT,E_PIN,HIGH);
    _delay_ms(1);
    DIO_SetPinValue(CONTROL_PORT,E_PIN,LOW);
    _delay_ms(1);
}




void LCD_SendCharData(u8 data){
    DIO_SetPinValue(CONTROL_PORT,RS_PIN,HIGH);
    DIO_SetPinValue(CONTROL_PORT,RW_PIN ,LOW);

    DIO_SetPortValue(PORTC,data);
    DIO_SetPinValue(CONTROL_PORT,E_PIN,HIGH);
    _delay_ms(1);
    DIO_SetPinValue(CONTROL_PORT,E_PIN,LOW);
    _delay_ms(1);  
}


void LCD_PrintAtPosition(u8 data ,u8 line ,u8 position ){
    switch (line)
    {
    case line1:
        LCD_SendCommand(0x80 +position);
        break;

    case line2:
        LCD_SendCommand(0xC0 +position);

        break;
    
    default:
        break;
    }
    LCD_SendCharData(data);
}

void LCD_curserPosition(u8 line ,u8 position ){
    switch (line)
    {
    case line1:
        LCD_SendCommand(0x80 +position);
        break;

    case line2:
        LCD_SendCommand(0xC0 +position);

        break;
}
}



void LCD_Draw_pattarn(u8 *pattarn,u8 pattern_number )
{
LCD_SendCommand(0x40 + (8 * pattern_number));
for(int i=0;i<8;i++){
    LCD_SendCharData(pattarn[i]);
}

}
void LCD_CursorOff(void) {
    LCD_SendCommand(0x0C);
}

void LCD_print_pattarn(u8* pattarn , u8 line ,u8 position,u8 pattern_number){
    LCD_CursorOff();
    LCD_Draw_pattarn( pattarn , pattern_number);
    LCD_curserPosition(line ,position);
    LCD_SendCharData(pattern_number);
    
}
void LCD_print_string(u8 *arr){
   int i=0;
    while(arr[i]!='\0'){
        LCD_SendCharData(arr[i]);
        i++;
    }
}

void LCD_ClearDisplay(void){
    LCD_SendCommand(DISPLAY_CLEAR);
     _delay_ms(2);

}


void LCD_dinasor_jump(u8* pattern) {
   
        // 1. Print the dinosaur at line 2 (starting position)
        LCD_print_pattarn(pattern, line2, 0, 3);
        

        // 2. Clear the dinosaur from line 2 (before jumping)
        LCD_curserPosition(line2, 0);
        LCD_SendCharData(' ');

        // 3. Print the dinosaur on line 1 (jumping up)
        LCD_curserPosition(line1, 0);
        LCD_print_pattarn(pattern, line1, 0, 3);

        // 4. Wait a short time to simulate jump duration
        _delay_ms(300);

        // 5. Clear the dinosaur from line 1 (falling back down)
        LCD_curserPosition(line1, 0);
        LCD_SendCharData(' ');

        // 6. Print the dinosaur again at line 2 (landing)
        LCD_print_pattarn(pattern, line2, 0, 3);
    
}



void LCD_annimation(u8 *pattern){
  
    LCD_Draw_pattarn(pattern, 4);  // تحميل الباترن في CGRAM رقم 4
   int i;
    int x=15;
    for(i = 15; i >= 0; --i){
        if (i < 15) {
            // امسح العقبة من مكانها القديم (i+1)
            LCD_curserPosition(line2, i + 1);
            LCD_SendCharData(' ');
            LCD_curserPosition(line2, i + 11);
            LCD_SendCharData(' ');


        }
        

        // اطبع العقبة في المكان الجديد i
        LCD_curserPosition(line2, i);
        LCD_SendCharData(4);
        LCD_curserPosition(line2, i+10);
        LCD_SendCharData(4);
        

          // رقم الباترن

        _delay_ms(50);
        
        x--;
    }
   

    // امسح العقبة من position 0 بعد انتهاء الحركة
    LCD_curserPosition(line2, 0);
    LCD_SendCharData(' ');
    
    LCD_curserPosition(line2, 10);
    LCD_SendCharData(' ');
    

}
void LCD_print_number ( u32 Number)
{
    u8 Arr[20] ; 
    u8 i=0 ;    
    while ( Number > 0 )        
    {                                   
        Arr[i] = Number % 10 ;  
        Number /= 10 ;          
        i++;                            
    }
   
    i--;
   
    for( s16 j=i ; j>=0 ; j--)
    {   
        LCD_SendCharData ( Arr[j] + '0' );
    }
}



