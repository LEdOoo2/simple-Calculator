/*
 * lcd.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Walid Omar
 */

#ifndef ECU_LCD_LCD_H_
#define ECU_LCD_LCD_H_

#include "../../MCAL/gpio/gpio.h"

/* Macros Section */

// Commands Value

#define _LCD_CLEAR                          0x01
#define _LCD_RETURN_HOME                    0x02

#define ROW1								1
#define ROW2								2
#define ROW3								3
#define ROW4								4

#define _LCD_ENTRY_MODE_SET_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_SET_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_SET_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_SET_INC_SHIFT_ON    0x07

#define _LCD_CURSOR_MOVE_SHIFT_LEFT         0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT        0x14
#define _LCD_DISPLAY_SHIFT_LEFT             0x18
#define _LCD_DISPLAY_SHIFT_RIGHT            0x1C

#define _LCD_DISPLAY_ON_CURSOR_OFF          0x0C
#define _LCD_UNDERLINE_CURSOR_ON            0x0E
#define _LCD_BLOCK_CURSOR_ON                0x0D
#define _LCD_DISPLAY_OFF                    0x08

#define _LCD_4BIT_MODE_2_LINES              0x28
#define _LCD_8BIT_MODE_2_LINES              0x38

#define _LCD_CGRAM_START                    0x40
#define _LCD_DDRAM_START                    0x80

/* Data Type Declaration */
typedef struct
{
	pinConfig_t RS;
	pinConfig_t EN;
	pinConfig_t lcd_data[4];
}lcd_4bit_t;


/* Functions Declaration */

Std_ReturnType lcd_4bit_init(const lcd_4bit_t *lcd);
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd ,uint8 command);
Std_ReturnType lcd_4bit_send_char(const lcd_4bit_t *lcd ,uint8 data);
Std_ReturnType lcd_4bit_send_char_at_pos(const lcd_4bit_t *lcd ,uint8 data,uint8 row,uint8 column);
Std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd ,uint8 *str);
Std_ReturnType lcd_4bit_send_string_at_pos(const lcd_4bit_t *lcd ,uint8 *str,uint8 row,uint8 column);
Std_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t *lcd, uint8 row, uint8 column,const uint8 chr[], uint8 mem_pos);
Std_ReturnType lcd_4bit_send_number(const lcd_4bit_t *lcd,sint32 num);


/*Std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str);
Std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str);
Std_ReturnType convert_uint32_to_string(int value, char *str);*/



#endif /* ECU_LCD_LCD_H_ */
