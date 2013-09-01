/*
 * IlMatto_TFT.c
 *
 * Created: 28/08/2013 20:38:44
 *  Author: seblovett
 */ 


#include "IlMatto.h"
#include <avr/io.h>

#include <util/delay.h>
#include "ili9340.h"
#include "Graphics.h"


int main(void)
{
	uint16_t i, j =0;
	LED_init();
	LCD_init();
	
	//A test screen
	//Blue gradient square
	SetWrap(0,0,80,80);
	SetGRAM();
	for(i = 0; i < 64; i ++)
	{
		for (j = 0; j < 80; j ++)
		{
			write_data16((i >> 1) & BLUE);
		}
	}
	for ( ; i < 80; i++)
	{
		for (j = 0; j < 80; j ++)
			write_data16(BLUE);
	}
	//Green gradient square
	SetWrap(80,0,80,80);
	SetGRAM();
	for(i = 0; i < 64; i ++)
	{
		for (j = 0; j < 80; j ++)
		{
			write_data16((i << 5) & GREEN);
		}
	}
	for ( ; i < 80; i++)
	{
		for (j = 0; j < 80; j ++)
			write_data16(GREEN);
	}
	//Red gradient square
	SetWrap(160,0,80,80);
	SetGRAM();
	for(i = 0; i < 64; i ++)
	{
		for (j = 0; j < 80; j ++)
		{
			write_data16((i << 10) & RED);
		}
	}
	for ( ; i < 80; i++)
	{
		for (j = 0; j < 80; j ++)
			write_data16(RED);
	}
	
	Rectangle(20,100,20,20,WHITE);
	SetColor(WHITE);
	DrawString("a quick brown fox jumps over the lazy dog.", 42, 10, 150);
	DrawString("A QUICK BROWN FOX JUMPS OVER THE", 32, 10, 170);
	DrawString("LAZY DOG", 32, 10, 181);
    while(1)
    {
        //TODO:: Please write your application code 
		
		LED_toggle();
		_delay_ms(500);
		
    }
}