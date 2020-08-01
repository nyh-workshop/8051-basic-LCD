#ifndef _DELAY8051_H
#define _DELAY8051_H

// source: http://www.mbeddedc.com/2016/01/8051-timers-tutorial-with-at89s52-timer.html
void configTimer0();
void delayMs(unsigned int inputDelay);

#endif