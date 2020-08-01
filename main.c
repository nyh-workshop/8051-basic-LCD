#include <at89x52.h>
#include "delay8051.h"
#include "lcd8051.h"

void main()
{
	P0 = 0x00;
	P2 = 0x00;
	LCD_init();
	LCD_write_str("Hello123", 0, 0);
	LCD_write_str("Hello456", 1, 0);
    while(1)
    {
		P0_0 = 0;
		delayMs(500);
		P0_0 = 1;
		delayMs(500);
    }
}