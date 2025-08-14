#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include"../../Lib/STD_TYPES.h"

#define line1                    0
#define line2                    1



void LCD_init(void);
void LCD_SendCommand(u8 command);
void LCD_SendCharData(u8 data);
void LCD_PrintAtPosition(u8 data , u8 line ,u8 position );
void LCD_curserPosition(u8 line ,u8 position );
void LCD_Draw_pattarn(u8 *pattarn,u8 pattern_number );
void LCD_print_pattarn(u8* pattarn , u8 line ,u8 position,u8 pattern_number);
void LCD_CursorOff(void);
void LCD_print_string(u8 *arr);
void LCD_ClearDisplay(void);
void LCD_dinasor_jump(u8* pattarn);
void LCD_annimation(u8 *pattern);
void LCD_print_number ( u32 Number);








#endif
