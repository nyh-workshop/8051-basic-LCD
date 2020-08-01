#include <at89x52.h>
#include "delay8051.h"

// source: http://www.mbeddedc.com/2016/01/8051-timers-tutorial-with-at89s52-timer.html
void configTimer0()
{
	TMOD = 0x1; // Opearating timer 0 in 16bit mode
	TH0 = 0xfd;
	TL0 = 0x64;
	TR0 = 1;//Turn on timer 0
}

void delayMs(unsigned int inputDelay) {
	unsigned int i = 0;
	for(i = 0; i < inputDelay; i++) {
		configTimer0();
		while(TF0 == 0); //wait for timer 0 to overflow
		TR0 = 0; //Turn off timer 0
		TF0 = 0;//Clear timer 0 overflow flag   
	}
}
