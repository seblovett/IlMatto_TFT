/************************************************************************/
/*  @file ili9340.h                                                        */
/*                                                                      */
/*  Created: 8/28/2013 10:58:08 PM                                                     */
/*  @Author seblovett                                                  */
/************************************************************************/



//_____ I N C L U D E S ____________________________________________________

#include "ili9340.h"




//_____ F U N C T I O N S __________________________________________________

/**
 * \defgroup functions Functions
 * @{
 */

/** @brief Initialise the LCD Screen
 */

void LCD_init()
{
	uint16_t x, y = 0;
	CTRL_DDR = 0x7F;
	CTRL_PORT = (1 << RS) | (1 << WR) | (1 << VSYNC) | (1 << RD);
	DataOut();
	reset();
	delay();
	write_cmd(DISPLAY_OFF);
	write_cmd(SLEEP_OUT);
	_delay_ms(60);
	write_cmd_data(INTERNAL_IC_SETTING,			 1, "\x01");
	write_cmd_data(POWER_CONTROL_1,				 2, "\x26\x08");
	write_cmd_data(POWER_CONTROL_2,				 1, "\x10");
	write_cmd_data(VCOM_CONTROL_1,				 2, "\x35\x3E");
	//    write_cmd_data(MEMORY_ACCESS_CONTROL,		 1, "\x48");
	write_cmd_data(MEMORY_ACCESS_CONTROL,		 1, "\x48");
	write_cmd_data(RGB_INTERFACE_SIGNAL_CONTROL, 1, "\x4A");  // Set the DE/Hsync/Vsync/Dotclk polarity
	write_cmd_data(FRAME_CONTROL_IN_NORMAL_MODE, 2, "\x00\x1B"); // 70Hz
	write_cmd_data(DISPLAY_FUNCTION_CONTROL,	 4, "\x0A\x82\x27\x00");
	write_cmd_data(VCOM_CONTROL_2,			     1, "\xB5");
	write_cmd_data(INTERFACE_CONTROL,			 3, "\x01\x00\x00"); // System interface
	write_cmd_data(GAMMA_DISABLE,				 1, "\x00");
	write_cmd_data(GAMMA_SET,					 1, "\x01"); // Select Gamma curve 1
	write_cmd_data(PIXEL_FORMAT_SET,			 1, "\x55"); // 0x66 - 18bit /pixel,  0x55 - 16bit/pixel
	write_cmd_data(POSITIVE_GAMMA_CORRECTION,	15, "\x1F\x1A\x18\x0A\x0F\x06\x45\x87\x32\x0A\x07\x02\x07\x05\x00");
	write_cmd_data(NEGATIVE_GAMMA_CORRECTION,	15, "\x00\x25\x27\x05\x10\x09\x3A\x78\x4D\x05\x18\x0D\x38\x3A\x1F");
	write_cmd_data(COLUMN_ADDRESS_SET,			 4, "\x00\x00\x00\xEF");
	write_cmd_data(PAGE_ADDRESS_SET,			 4, "\x00\x00\x01\x3F");
	write_cmd(TEARING_EFFECT_LINE_OFF);
	write_cmd_data(DISPLAY_INVERSION_CONTROL,	 1, "\x00");
	write_cmd_data(ENTRY_MODE_SET,				 1, "\x07");
	write_cmd(MEMORY_WRITE);
	for(x=0; x<240; x++)
	{
		for(y=0; y<320; y++)
		{
			write_data16(0x0000);
		}
	}
	
	
	write_cmd(DISPLAY_ON);
	_delay_ms(50);
	backlight_on();
}

/** @brief Basic Delay method
 */
void delay()
{
	_delay_ms(100);
}
/**@}*/



/** @brief Fills the set memory area to a solid colour. Colour is set in the config struct.
 */
/** @brief Sets the frame area of the device. 
 * Used for writing only to a specific area on the screen
 * @param x the column to start from
 * @param y the row to start from
 * @param width the number of columns to write across
 * @param height the number of rows to write to.
 */
void SetWrap(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(x);
	write_data16(x + width-1);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(y);
	write_data16(y + height-1);
}

/** @brief Starts a memory write to the selected area @sa SetWrap
 *
 */
void SetGRAM()
{
	write_cmd(MEMORY_WRITE);
}

/** @brief Fills the area with the same colour
 *  @param count number of pixels to set
 */
void SolidFill(uint16_t count)
{
	DataOut();
	uint8_t a, b;
	a = ili9340.colour >> 8;
	b = ili9340.colour & 0xFF;
	
	uint8_t slow = count & 0x07;
	if (slow)
	{
		do {
			DATA_PORT = a;
			WR_Low();
			WR_High();
			DATA_PORT = b;
			WR_Low();
			WR_High();
		} while (--slow);
	}
	
	// x8 unrolled
	count >>= 3;
	if (count)
	{
		do {
			DATA_PORT = a;
			WR_Low();
			WR_High();
			DATA_PORT = b;
			WR_Low();
			WR_High();
			DATA_PORT = a;
			WR_Low();
			WR_High();
			DATA_PORT = b;
			WR_Low();
			WR_High();
			DATA_PORT = a;
			WR_Low();
			WR_High();
			DATA_PORT = b;
			WR_Low();
			WR_High();
			DATA_PORT = a;
			WR_Low();
			WR_High();
			DATA_PORT = b;
			WR_Low();
			WR_High();
			DATA_PORT = a;
			WR_Low();
			WR_High();;
			DATA_PORT = b;
			WR_Low();
			WR_High();
			DATA_PORT = a;
			WR_Low();
			WR_High();
			DATA_PORT = b;
			WR_Low();
			WR_High();
			DATA_PORT = a;
			WR_Low();
			WR_High();
			DATA_PORT = b;
			WR_Low();
			WR_High();
			DATA_PORT = a;
			WR_Low();
			WR_High();
			DATA_PORT = b;
			WR_Low();
			WR_High();
		} while (--count);
	}
}