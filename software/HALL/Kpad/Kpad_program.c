#include <util/delay.h>
#include"../../Lib/Bit_math.h"
#include"../../Lib/STD_TYPES.h"

#include"../../MCAL/DIO/DIO_interface.h"

#include"../LCD/LCD_cofig.h"
#include"../LCD/LCD_interface.h"

#include"../Button/Button_interface.h"

#include"Kpad_interface.h"
#include"Kpad_config.h"
#include"Kpad_private.h"

u8 columnsPins[Kpad_col_num]={Kpad_C0,Kpad_C1,Kpad_C2,Kpad_C3};
u8 rowsPins[Kpad_row_num]={Kpad_R0,Kpad_R1,Kpad_R2,Kpad_R3};
u8 key_data[Kpad_row_num][Kpad_col_num]=KPAD_KEYS;
void Kpad_init(void){
     DIO_SetPinDirection(Kpad_port,Kpad_C0,OUTPUT);
     DIO_SetPinDirection(Kpad_port,Kpad_C1,OUTPUT);
     DIO_SetPinDirection(Kpad_port,Kpad_C2,OUTPUT);
     DIO_SetPinDirection(Kpad_port,Kpad_C3,OUTPUT);

     DIO_SetPinDirection(Kpad_port,Kpad_R0,INPUT);
     DIO_SetPinDirection(Kpad_port,Kpad_R1,INPUT);
     DIO_SetPinDirection(Kpad_port,Kpad_R2,INPUT);
     DIO_SetPinDirection(Kpad_port,Kpad_R3,INPUT);

     DIO_Pull_Up_Pin(Kpad_port,Kpad_R0,ON);
     DIO_Pull_Up_Pin(Kpad_port,Kpad_R1,ON);
     DIO_Pull_Up_Pin(Kpad_port,Kpad_R2,ON);
     DIO_Pull_Up_Pin(Kpad_port,Kpad_R3,ON);

     //deactivate columns
     DIO_SetPinValue(Kpad_port,Kpad_C0,HIGH);
     DIO_SetPinValue(Kpad_port,Kpad_C1,HIGH);
     DIO_SetPinValue(Kpad_port,Kpad_C2,HIGH);
     DIO_SetPinValue(Kpad_port,Kpad_C3,HIGH);


}

u8 Kpad_return_pressed_key(void){
     u8 pressed_key=0xff;
     for(u8 col=0 ;col<Kpad_col_num ;col++){
          //activate columns
          
          DIO_SetPinValue(Kpad_port,columnsPins[col],LOW);

          for(u8 row=0; row<Kpad_row_num;row++){
          u8 pinvalue=   DIO_GetPinValue(Kpad_port,rowsPins[row]);
          if (pinvalue==0)
          {
             while(pinvalue==0) {
                    pinvalue=   DIO_GetPinValue(Kpad_port,rowsPins[row]);
             } 
             pressed_key=key_data[row][col];
             break;
          }
          }

          //Deactivate columns
          DIO_SetPinValue(Kpad_port,columnsPins[col],HIGH);
     }
     return pressed_key;
}

