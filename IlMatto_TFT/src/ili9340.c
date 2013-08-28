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
 * \defgroup Functions
 * @{
 */

/** @brief Initialise the LCD Screen
 */
void LCD_init()
{
	CTRL_DDR = 0x7F;
	CTRL_PORT = (1 << RS) | (1 << WR) | (1 << VSYNC) | (1 << RD);
}

/** @brief Basic Delay method
 */
void delay()
{
	_delay_ms(100);
}
/**@}*/

