/*
 * IlMatto_TFT.c
 *
 * Created: 28/08/2013 20:38:44
 *  Author: seblovett
 */ 

#define F_CPU 12000000UL

#include <avr/io.h>

#include <util/delay.h>
#include "ili9340.h"


int main(void)
{
	LCD_init();
	backlight_on();
    while(1)
    {
        //TODO:: Please write your application code 
		
		
    }
}