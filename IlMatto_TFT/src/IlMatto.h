/************************************************************************/
/*  @file IlMatto.h                                                        */
/*                                                                      */
/*  Created: 8/31/2013 9:20:56 PM                                                     */
/*  @Author seblovett                                                  */
/************************************************************************/



#ifndef IlMatto_H_
#define IlMatto_H_

//_____ I N C L U D E S ____________________________________________________

#include <avr/io.h>


//_____ D E F I N I T I O N S ______________________________________________
/**
 * \defgroup definitions Definitions
 * @{
 */

#define F_CPU 12000000 //This should be defined as a symbol, or use -D on the command line

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


/**@}*/

//_____ I N L I N E   F U N C T I O N S ____________________________________
/**
 * \defgroup infunctions Inline Functions
 * @{
 */

/** @brief A brief description.
 */
__inline__ void LED_init()
{
	DDRB |= 0x80; //set portb7 to an output.
}
__inline__ void LED_on()
{
	PORTB |= 0x80;
}
__inline__ void LED_off()
{
	PORTB &= 0x7F;
}
__inline__ void LED_toggle()
{
	PORTB ^= 0x80;
}
/**@}*/

#endif /* IlMatto_H_ */
