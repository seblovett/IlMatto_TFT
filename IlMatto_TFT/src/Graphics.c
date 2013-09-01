/************************************************************************/
/*  @file Graphics.h                                                        */
/*                                                                      */
/*  Created: 9/1/2013 3:33:18 PM                                                     */
/*  @Author seblovett                                                  */
/************************************************************************/



//_____ I N C L U D E S ____________________________________________________

#include "Graphics.h"
#include "ili9340.h"
#include <avr/pgmspace.h>

extern const uint8_t Verdana_font_11[] PROGMEM;
const uint8_t Verdana_font_11[] = { //< Description of the Verdana font
	0,   // format
	11,   // fontHeight
	9,   // ascent
	33,   // from
	95,   // count
	59,   // totalWidth/8
	0x00,0x01,0x00,0x04,0x00,0x0B,0x00,0x10,0x00,0x1A,0x00,0x21,0x00,0x22,0x00,0x25,0x00,0x28,0x00,0x2D,0x00,0x34,0x00,0x36,0x00,0x39,0x00,0x3A,0x00,0x3F,0x00,0x44,0x00,0x49,0x00,0x4E,0x00,0x53,0x00,0x59,0x00,0x5E,0x00,0x63,0x00,0x68,0x00,0x6D,0x00,0x72,0x00,0x73,0x00,0x75,0x00,0x7B,0x00,0x82,0x00,0x88,0x00,0x8C,0x00,0x94,0x00,0x9A,0x00,0xA0,0x00,0xA7,0x00,0xAE,0x00,0xB3,0x00,0xB8,0x00,0xBF,0x00,0xC5,0x00,0xC8,0x00,0xCC,0x00,0xD2,0x00,0xD7,0x00,0xDE,0x00,0xE4,0x00,0xEB,0x00,0xF0,0x00,0xF7,0x00,0xFD,0x01,0x03,0x01,0x0A,0x01,0x10,0x01,0x16,0x01,0x1F,0x01,0x25,0x01,0x2C,0x01,0x32,0x01,0x35,0x01,0x3A,0x01,0x3D,0x01,0x44,0x01,0x4B,0x01,0x4D,0x01,0x52,0x01,0x57,0x01,0x5C,0x01,0x61,0x01,0x66,0x01,0x6A,0x01,0x6F,0x01,0x74,0x01,0x75,0x01,0x78,0x01,0x7D,0x01,0x7E,0x01,0x87,0x01,0x8C,0x01,0x91,0x01,0x96,0x01,0x9B,0x01,0x9F,0x01,0xA3,0x01,0xA7,0x01,0xAC,0x01,0xB1,0x01,0xB8,0x01,0xBD,0x01,0xC2,0x01,0xC6,0x01,0xCB,0x01,0xCC,0x01,0xD1,0x01,0xD8,0x01,0xD8,    // Col ends
	0x50,0x04,0x00,0x00,0x4C,0x20,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x38,0x00,0x10,0x20,0x00,0x80,0xC1,0x09,0x84,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,    // Line 0
	0xD1,0x44,0x62,0x18,0x52,0xA8,0x00,0x02,0xE2,0x39,0xC1,0x7C,0xDF,0x73,0x80,0x00,0x00,0xE3,0xE3,0x3C,0x3D,0xF3,0xFF,0x3D,0x0F,0x78,0x61,0x8F,0x13,0x9E,0x39,0xE3,0xDF,0xE1,0x86,0x23,0x0C,0x1F,0xE4,0x08,0x80,0x08,0x20,0x00,0x81,0x01,0x00,0x84,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x92,0x00,    // Line 1
	0xD1,0x4F,0x92,0x24,0x52,0x70,0x80,0x05,0x1E,0x46,0x23,0x41,0x01,0x8C,0x40,0x00,0x00,0x14,0x13,0x22,0x43,0x0A,0x10,0x43,0x0A,0x18,0xA1,0x8F,0x14,0x51,0x45,0x14,0x22,0x21,0x86,0x23,0x0A,0x20,0x62,0x09,0x40,0x00,0x20,0x00,0x81,0x01,0x00,0x84,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x92,0x00,    // Line 2
	0x87,0xF4,0x94,0x24,0x21,0xA8,0x80,0x05,0x12,0x04,0x25,0x42,0x02,0x8C,0x68,0x60,0x30,0x19,0xD4,0xA2,0x81,0x06,0x10,0x81,0x0A,0x19,0x21,0x56,0x98,0x31,0x83,0x14,0x02,0x21,0x85,0x54,0x91,0x40,0xA2,0x0A,0x20,0x03,0xBC,0xE7,0xBB,0xDF,0xEB,0x8F,0xDD,0xE7,0x79,0xF6,0xFF,0x18,0xC9,0x8C,0x7C,0x92,0x00,    // Line 3
	0x82,0x94,0x64,0x19,0x21,0x20,0x80,0x09,0x12,0x08,0xC9,0x7B,0xC2,0x74,0x69,0x9F,0xCC,0x2A,0x54,0xBE,0x81,0x07,0xFE,0x81,0xFA,0x1A,0x21,0x56,0x98,0x31,0x83,0x13,0x02,0x21,0x49,0x54,0x60,0x81,0x21,0x0C,0x10,0x00,0x63,0x18,0xC5,0x23,0x19,0x96,0x23,0x18,0xC6,0x39,0x09,0x18,0xC9,0x52,0x84,0x92,0x31,    // Line 4
	0x82,0x8E,0x09,0xA5,0x21,0x07,0xF3,0x89,0x12,0x10,0x31,0x06,0x24,0x8B,0xC6,0x00,0x03,0x4A,0x54,0xA1,0x81,0x06,0x10,0x8F,0x0A,0x1E,0x21,0x26,0x58,0x3E,0x83,0xE0,0xC2,0x21,0x49,0x54,0x60,0x82,0x21,0x08,0x00,0x03,0xE3,0x08,0xFD,0x23,0x19,0xA6,0x23,0x18,0xC6,0x31,0x89,0x15,0x55,0x22,0x8B,0x11,0xC9,    // Line 5
	0x8F,0xC5,0x0A,0x62,0x21,0x00,0x80,0x11,0x12,0x20,0x3F,0x86,0x24,0x88,0x41,0x9F,0xCC,0x4A,0x5F,0xE1,0x81,0x06,0x10,0x83,0x0A,0x19,0x21,0x26,0x58,0x30,0x83,0x20,0x22,0x21,0x49,0x54,0x90,0x84,0x20,0x88,0x00,0x04,0x63,0x08,0xC1,0x23,0x19,0xE6,0x23,0x18,0xC6,0x30,0x69,0x15,0x55,0x22,0x90,0x92,0x46,    // Line 6
	0x05,0x05,0x12,0x63,0x21,0x00,0x84,0x51,0x12,0x42,0x21,0x46,0x28,0x88,0xA8,0x60,0x30,0x09,0xA8,0x61,0x43,0x0A,0x10,0x43,0x0A,0x18,0xA1,0x06,0x34,0x50,0x45,0x14,0x22,0x21,0x30,0x89,0x08,0x88,0x20,0x88,0x00,0x04,0x63,0x18,0xC5,0x23,0x19,0x96,0x23,0x18,0xC6,0x30,0x29,0x12,0x22,0x51,0x20,0x92,0x00,    // Line 7
	0x85,0x1E,0x11,0x9C,0x92,0x00,0x84,0x60,0xEF,0xFD,0xC1,0x39,0xC8,0x73,0x28,0x00,0x00,0x44,0x08,0x7E,0x3D,0xF3,0xF0,0x3D,0x0F,0xE8,0x7F,0x06,0x33,0x90,0x39,0x0B,0xC2,0x1E,0x30,0x89,0x08,0x8F,0xE0,0x48,0x00,0x03,0xFC,0xE7,0xB9,0x1F,0x19,0x8E,0x23,0x17,0x79,0xF1,0xC6,0xF2,0x22,0x89,0x3C,0x92,0x00,    // Line 8
	0x00,0x04,0x00,0x00,0x12,0x00,0x04,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x48,0x00,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x40,0x20,0x00,0x00,0x00,0x01,0x00,0x92,0x00,    // Line 9
	0x00,0x04,0x00,0x00,0x0C,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x38,0x0F,0xE0,0x00,0x00,0x00,0x1C,0x06,0x00,0x00,0x00,0x40,0x20,0x00,0x00,0x00,0x02,0x00,0x7C,0x00,    // Line 10
};

int _ph = 0;
int _pv = 0;

#ifdef pgm_read_byte
#define FNT(_x) pgm_read_byte(Verdana_font_11 + (_x))
#else
#define FNT(_x) Verdana_font_11[_x]
#endif

//_____ F U N C T I O N S __________________________________________________

/**
 * \defgroup functions Functions
 * @{
 */


/**@}*/

/** @brief Draws a rectangle of solid colour
*   @param x x start location 
*   @param y y start location
*   @param width The width of the rectangle (x direction)
*   @param height The height on the rectangle (y direction)
*   @param colour The colour of the rectangle
*/
void Rectangle(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint16_t colour)
{	
	SetWrap(x,y,width,height);
	SetGRAM();
	SetColor(colour);
	
	// Keep 16 bit int range
	while (height > 128)
	{
		SolidFill(width*128);
		height -= 128;
	}
	SolidFill(width*height);
}

/** @brief Draws a char on the screen
 *  @param xx Horizontal location to draw the char at
 *  @param yy Vertical location to draw the char at
 *  @param c char to draw
 *  @todo clean this function up. It's messy and doesn't make sense (but it works..)
 */
int DrawChar(int xx, int yy, int c)
{
	//uint8_t* f = Verdana_font_11;
	if (c == 32)// a space
		return FNT(1)>>2;  // Space is 1/4 font height (yuk);

	int i = c - FNT(3);
	if (i < 0 || i >= FNT(4)) 
	{
		return 0;
	}

	int ci = 6 + i * 2;
	int width = (FNT(ci) << 8) | FNT(ci + 1);   // simplify
	int height = FNT(1);
	int src = 0;
	if (i > 0)
	{
		src = (FNT(ci - 2) << 8) | FNT(ci - 1);
		width -= src;
	}
	
	//  clip?
	src += (6 + 2 * FNT(4)) * 8;    // start of pixels (roll into cols)
	uint8_t mask = 0x80 >> (src & 7);  // Mask at start of line
	int end = (src+width) >> 3;     // number of bytes read
	src >>= 3;
	int makeup = FNT(5) - (end + 1 - src);
	for (uint8_t y = 0; y < (uint8_t)height; y++)
	{
		uint8_t p = FNT(src++);
		uint8_t m = mask;
		for (uint8_t x = 0; x < (uint8_t)width; x++)
		{
			if (p & m)
			{
				SetWrap(x + xx, y + yy, 1, 1);
				SetGRAM();
				_ph = x;
				_pv = y;
				SolidFill(2);
			}	
			
			m >>= 1;
			
			if (m == 0)
			{
				p = FNT(src++);
				if (p == 0 && (width-x) <= 8)   // early out
				break;
				m = 0x80;
			}
		}
		src += makeup;
	}
	return width;
}


/** @brief Draws a string to the screen
 *  @param s the string to draw
 *  @param len Length of the string
 *  @param x Horizontal start location of the string
 *  @param y Vertical location of the string
 */
void DrawString(const char* s, int len, int x, int y)
{
	OpenWrap();
	SetGRAM();
	_ph = _pv = 0xFFFF;
	for (int i = 0; i < len; i++)
		x += DrawChar(x,y,s[i]) + 1;
}