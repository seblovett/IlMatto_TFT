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


void Rectangle(int x, int y, int width, int height, int color)
{
	int right = x + width;
	int bottom = y + height;
	//right = min(right,(int)WIDTH);
	//bottom = min(bottom,(int)HEIGHT);
	//x = max(x,0);
	//y = max(y,0);
	width = right - x;
	height = bottom - y;
	if (width <= 0 || height <= 0)
		return;
	
	SetWrap(x,y,width,height);
	SetGRAM(x,y);
	SetColor(color);
	
	// Keep 16 bit int range
	while (height > 128)
	{
		SolidFill(width*128);
		height -= 128;
	}
	SolidFill(width*height);
}

int main(void)
{
	
	LED_init();
	LCD_init();
	OpenWrap();
	//Rectangle(0,0,50,50,0xFF00);
    while(1)
    {
        //TODO:: Please write your application code 
		Rectangle(0,0,WIDTH,HEIGHT, ~ili9340.colour);
		LED_toggle();
		_delay_ms(500);
		
    }
}