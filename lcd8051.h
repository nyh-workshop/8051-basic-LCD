#ifndef _LCD8051_H
#define _LCD8051_H

#include <at89x52.h>

#define _RS P2_4
#define _RW P2_5
#define _EN P2_6
#define _D4 P2_0
#define _D5 P2_1
#define _D6 P2_2
#define _D7 P2_3

inline void LCD_write_nibble(unsigned char inputNibble);
void LCD_write_data(unsigned char inputData);
void LCD_write_cmd(unsigned char inputCmd);
void LCD_init();
void LCD_write_str(const unsigned char* str, unsigned char row, unsigned char col);




#endif