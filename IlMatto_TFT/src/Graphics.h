/************************************************************************/
/*  @file Graphics.h                                                        */
/*                                                                      */
/*  Created: 9/1/2013 3:33:56 PM                                                     */
/*  @Author seblovett                                                  */
/************************************************************************/



#ifndef Graphics_H_
#define Graphics_H_

//_____ I N C L U D E S ____________________________________________________

#include "avr/io.h"


//_____ D E F I N I T I O N S ______________________________________________
/**
 * \defgroup definitions Definitions
 * @{
 */



/**@}*/

/**
 * \defgroup typedefs Type Defs
 * @{
 */

/**@}*/

//_____ F U N C T I O N   P R O T O T Y P E S ______________________________
/**
 * \defgroup functions Functions
 * @{
 */
void Rectangle(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint16_t colour);
void PutPixel(uint16_t x, uint16_t y);
int DrawChar(int xx, int yy, int c);
void DrawString(const char* s, int len, int x, int y);
void DrawString_P(const char* s, int len, int x, int y);
/**@}*/


//_____ I N L I N E   F U N C T I O N S ____________________________________
/**
 * \defgroup infunctions Inline Functions
 * @{
 */


/**@}*/

#endif /* Graphics_H_ */
