/************************************************************************/
/*  @file ili9340.h                                                        */
/*                                                                      */
/*  Created: 8/28/2013 11:00:28 PM                                                     */
/*  @Author seblovett                                                  */
/************************************************************************/



#ifndef ili9340_H_
#define ili9340_H_

//_____ I N C L U D E S ____________________________________________________

#include <avr/io.h>
#include <util/delay.h>


//_____ D E F I N I T I O N S ______________________________________________
/**
 * \defgroup definitions Definitions
 * @{
 */

///\todo better control on these definitions - if one is defined - we can infer the other. 

//Defaults
#ifndef CTRL_PORT
#define CTRL_PORT	PORTA
#define CTRL_DDR	DDRA
#define CTRL_PIN	PINA
#endif

#ifndef DATA_PORT
#define DATA_PORT	PORTC
#define DATA_DDR	DDRC
#define DATA_PIN	PINC
#endif

#define CS			0
#define BLC			1
#define RESET		2
#define WR			3
#define RS			4
#define RD			5 //This is actually Data or Command
#define VSYNC		6
#define FMARK		7


/** \defgroup lcdcmds LCD Commands
 * @{
 */
#define NO_OPERATION								0x00
#define SOFTWARE_RESET								0x01
#define READ_DISPLAY_IDENTIFICATION_INFORMATION		0x04
#define READ_DISPLAY_STATUS							0x09
#define READ_DISPLAY_POWER_MODE						0x0A
#define READ_DISPLAY_MADCTL							0x0B
#define READ_DISPLAY_PIXEL_FORMAT					0x0C
#define READ_DISPLAY_IMAGE_FORMAT					0x0D
#define READ_DISPLAY_SIGNAL_MODE					0x0E
#define READ_DISPLAY_SELF_DIAGNOSTIC_RESULT			0x0F
#define ENTER_SLEEP_MODE							0x10
#define SLEEP_OUT									0x11
#define PARTIAL_MODE_ON								0x12
#define NORMAL_DISPLAY_MODE_ON						0x13
#define DISPLAY_INVERSION_OFF						0x20
#define DISPLAY_INVERSION_ON						0x21
#define GAMMA_SET									0x26
#define DISPLAY_OFF									0x28
#define DISPLAY_ON									0x29
#define COLUMN_ADDRESS_SET							0x2A
#define PAGE_ADDRESS_SET							0x2B
#define MEMORY_WRITE								0x2C
#define COLOR_SET									0x2D
#define MEMORY_READ									0x2E
#define PARTIAL_AREA								0x30
#define VERTICAL_SCROLLING_DEFINITION				0x33
#define TEARING_EFFECT_LINE_OFF						0x34
#define TEARING_EFFECT_LINE_ON						0x35
#define MEMORY_ACCESS_CONTROL						0x36
#define VERTICAL_SCROLLING_START_ADDRESS			0x37
#define IDLE_MODE_OFF								0x38
#define IDLE_MODE_ON								0x39
#define PIXEL_FORMAT_SET							0x3A
#define WRITE_MEMORY_CONTINUE						0x3C
#define READ_MEMORY_CONTINUE						0x3E
#define SET_TEAR_SCANLINE							0x44
#define GET_SCANLINE								0x45
#define WRITE_DISPLAY_BRIGHTNESS					0x51
#define READ_DISPLAY_BRIGHTNESS						0x52
#define WRITE_CTRL_DISPLAY							0x53
#define READ_CTRL_DISPLAY							0x54
#define WRITE_CONTENT_ADAPTIVE_BRIGHTNESS_CONTROL	0x55
#define READ_CONTENT_ADAPTIVE_BRIGHTNESS_CONTROL	0x56
#define WRITE_CABC_MINIMUM_BRIGHTNESS				0x5E
#define READ_CABC_MINIMUM_BRIGHTNESS				0x5F
#define READ_ID1									0xDA
#define READ_ID2									0xDB
#define READ_ID3									0xDC

/* Extended Commands */
#define RGB_INTERFACE_SIGNAL_CONTROL				0xB0
#define FRAME_CONTROL_IN_NORMAL_MODE				0xB1
#define FRAME_CONTROL_IN_IDLE_MODE					0xB2
#define FRAME_CONTROL_IN_PARTIAL_MODE				0xB3
#define DISPLAY_INVERSION_CONTROL					0xB4
#define BLANKING_PORCH_CONTROL						0xB5
#define DISPLAY_FUNCTION_CONTROL					0xB6
#define ENTRY_MODE_SET								0xB7
#define BACKLIGHT_CONTROL_1							0xB8
#define BACKLIGHT_CONTROL_2							0xB9
#define BACKLIGHT_CONTROL_3							0xBA
#define BACKLIGHT_CONTROL_4							0xBB
#define BACKLIGHT_CONTROL_5							0xBC
#define BACKLIGHT_CONTROL_7							0xBE
#define BACKLIGHT_CONTROL_8							0xBF
#define POWER_CONTROL_1								0xC0
#define POWER_CONTROL_2								0xC1
#define POWER_CONTROL3_(FOR_NORMAL_MODE)			0xC2
#define POWER_CONTROL4_(FOR_IDLE_MODE)				0xC3
#define POWER_CONTROL5_(FOR_PARTIAL_MODE)			0xC4
#define VCOM_CONTROL_1								0xC5
#define VCOM_CONTROL_2								0xC7
#define NV_MEMORY_WRITE								0xD0
#define NV_MEMORY_PROTECTION_KEY					0xD1
#define NV_MEMORY_STATUS_READ						0xD2
#define READ_ID4									0xD3
#define POSITIVE_GAMMA_CORRECTION					0xE0
#define NEGATIVE_GAMMA_CORRECTION					0xE1
#define DIGITAL_GAMMA_CONTROL						0xE2
#define DIGITAL_GAMMA_CONTROL2						0xE3
#define INTERFACE_CONTROL							0xF6

/* Undocumented commands */
#define INTERNAL_IC_SETTING							0xCB
#define GAMMA_DISABLE								0xF2

/**@}
 */

// General Characteristics
#define WIDTH										240
#define HEIGHT										320

/** @defgroup colours Colours
 * @{
 */
#define RED			0xF800
#define BLUE		0x001F
#define GREEN		0x07E0
#define WHITE		0xFFFF
#define BLACK		0x0000
/**@}*/
/**@}*/

/**
 * \defgroup typedefs Type Defs
 * @{
 */
typedef struct ili9340_tag 
{
	uint16_t colour;
	} ili9340_t;

ili9340_t ili9340; //< Global settings struct 

/**@}*/

//_____ F U N C T I O N   P R O T O T Y P E S ______________________________
/**
 * \defgroup functions Functions
 * @{
 */

void LCD_init();
void delay();
void SolidFill(uint16_t count);
void SetGRAM();
void SetWrap(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void WritePixels(int count, const uint8_t* pixels);
/**@}*/

//_____ I N L I N E   F U N C T I O N S ____________________________________
/**
 * \defgroup infunctions Inline Functions
 * @{
 */

/** @brief Turns the Backlight on
 */
__inline__ void backlight_on()
{
	CTRL_PORT |= (1 << BLC);
}

/** @brief Turns the Backlight off
 */
__inline__ void backlight_off()
{
	CTRL_PORT &= ~(1 << BLC);
}
/** @brief Resets the LCD Display
 */
__inline__ void reset()
{
	CTRL_PORT &= ~(1 << RESET);
	delay();
	CTRL_PORT |=  (1 << RESET);
}

/** @brief Sets the data port to output
 */
__inline__ void DataOut()
{
	DATA_DDR = 0xFF;
}

/** @brief Sets the data port to input
 */
__inline__ void DataIn()
{
	DATA_DDR = 0x00;
}

__inline__ void CS_Low()
{
	CTRL_PORT &= ~(1 << CS);
}
__inline__ void CS_High()
{
	CTRL_PORT |= (1 << CS);
}
__inline__ void WR_Low()
{
	CTRL_PORT &= ~(1 << WR);
}
__inline__ void WR_High()
{
	CTRL_PORT |= (1 << WR);
}
__inline__ void RS_Low()
{
	CTRL_PORT &= ~(1 << RS);
}
__inline__ void RS_High()
{
	CTRL_PORT |= (1 << RS);
}

__inline__ void RD_Low()
{
	CTRL_PORT &= ~(1 << RD);
}
__inline__ void RD_High()
{
	CTRL_PORT |= (1 << RD);
}
__inline__ void VSYNC_Low()
{
	CTRL_PORT &= ~(1 << VSYNC);
}
__inline__ void VSYNC_High()
{
	CTRL_PORT |= (1 << VSYNC);
}
__inline__ void Write(uint8_t data)
{
	DATA_PORT = data;
}

__inline__ void write_cmd(uint8_t cmd)
{
	RS_Low();
	Write(cmd);
	WR_Low();
	WR_High();
	RS_High();
}

__inline__ void write_data(uint8_t data)
{
	Write(data);
	WR_Low();
	WR_High();
}

__inline__ void write_data16(uint16_t data)
{
	write_data(data >> 8);
	write_data(data & 0xFF);
}

__inline__ void write_cmd_data(uint8_t cmd, uint8_t ndata, char* data)
{
	uint8_t i;
	write_cmd(cmd);
	for(i=0; i<ndata; i++)
	{
		write_data(*data++);
	}
}
/** @brief Sets the frame area of the device to the full screen  
 *
 */
__inline__ void OpenWrap()
{
	SetWrap(0,0,WIDTH,HEIGHT);
}

/** @brief Sets the colour of the data being written
 *  @param colour the colour to use
 *  @todo write some general definitions for some common colours.
 */ 
__inline__ void SetColor(uint16_t colour)
{
	ili9340.colour = colour;
}

/**@}*/


#endif /* ili9340_H_ */
