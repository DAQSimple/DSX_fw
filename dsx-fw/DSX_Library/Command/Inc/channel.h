/*
 * channel.h
 *
 *  Created on: May 30, 2021
 *      Author: jpaca
 */

#ifndef CHANNEL_H
#define CHANNEL_H

#include "main.h"
#include <stdint.h>

typedef struct channel_t
{
	GPIO_TypeDef * port;
	uint16_t pin;
}channel_t;

// Function to convert loc to channel_t
// check loc and compare against pin defines in board_defines.h
// Assign appropriate port and pin
// Only need to do this for digital input and output pins
channel_t convert_loc_to_channel(uint32_t loc);


#endif /* CHANNEL_H */
