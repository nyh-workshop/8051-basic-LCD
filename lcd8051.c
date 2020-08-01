#include "lcd8051.h"
#include "delay8051.h"

inline void LCD_write_nibble(unsigned char inputNibble) {
    _D4 = (inputNibble & 0x01) >> 0;
	_D5 = (inputNibble & 0x02) >> 1;
	_D6 = (inputNibble & 0x04) >> 2;
	_D7 = (inputNibble & 0x08) >> 3;
}

// https://technobyte.org/lcd-interfacing-8051-8-bit-4-bit-8255/
void LCD_write_data(unsigned char inputData) {
	unsigned char ldata = 0x00;
	
	ldata = (inputData & 0xF0) >> 4; // To send the upper nibble
	LCD_write_nibble(ldata);
	_RS = 1;
    _RW = 0;
    _EN = 1;
    delayMs(1);
    _EN = 0;

    ldata = (inputData & 0x0F); // To send the lower nibble
    LCD_write_nibble(ldata);
	_RS = 1;
    _RW = 0;
    _EN = 1;
    delayMs(1);
    _EN = 0;
}



void LCD_write_cmd(unsigned char inputCmd) {
	unsigned char ldata = 0x00;
	
	ldata = (inputCmd & 0xF0) >> 4; // To send the upper nibble
    LCD_write_nibble(ldata);
	_RS = 0;
    _RW = 0;
    _EN = 1;
    delayMs(1);
    _EN = 0;

    ldata = (inputCmd & 0x0F); // To send the lower nibble
    LCD_write_nibble(ldata);
	_RS = 0;
    _RW = 0;
    _EN = 1;
    delayMs(1);
    _EN = 0;
}

void LCD_init() {
	// Initialize 4-bit mode!
	_RS = 0;
    _RW = 0;
	_EN = 0;
    
	LCD_write_nibble(0x03);
	_EN = 1;
    delayMs(1);
    _EN = 0;
	
	delayMs(50);
	
	LCD_write_nibble(0x03);
	_EN = 1;
    delayMs(1);
    _EN = 0;
	
	delayMs(50);
	
	LCD_write_nibble(0x03);
	_EN = 1;
    delayMs(1);
    _EN = 0;
	
	delayMs(50);
		
	LCD_write_nibble(0x02);
	_EN = 1;
    delayMs(1);
    _EN = 0;
	

	LCD_write_cmd(0x2C);
	delayMs(1);
	LCD_write_cmd(0x0F);
	delayMs(1);
	LCD_write_cmd(0x06);
	delayMs(1);
	
	LCD_write_cmd(0x01);
	delayMs(1);
	LCD_write_cmd(0x02);
	delayMs(1);
	
		
}

void LCD_write_str(const unsigned char* str, unsigned char row, unsigned char col) {
	unsigned char address_d = 0; // address of the data in the screen.
    switch (row)
    {
    case 0:
        address_d = 0x80 + col; // at zeroth row
        break;
    case 1:
        address_d = 0xC0 + col; // at first row
        break;
    case 2:
        address_d = 0x94 + col; // at second row
        break;
    case 3:
        address_d = 0xD4 + col; // at third row
        break;
    default:
        address_d = 0x80 + col; // returns to first row if invalid row number is detected
        break;
    }

    LCD_write_cmd(address_d);

    while (*str) // Place a string, letter by letter.
        LCD_write_data(*str++);
}


