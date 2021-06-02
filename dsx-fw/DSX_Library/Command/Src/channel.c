/*
 * channel.c
 *
 *  Created on: May 30, 2021
 *      Author: jpaca
 */

#include "channel.h"

// Function to convert loc to channel_t
// check loc and compare against pin defines in board_defines.h
// Assign appropriate port and pin
// Only need to do this for digital input and output pins
channel_t convert_loc_to_channel(uint32_t loc)
{
	channel_t channel;
	switch (loc)
	{
		// Digital output pins (2)
		case 9:
			channel.port=DO1_GPIO_Port;
			channel.pin=DO1_Pin;
			break;
		case 10:
			channel.port=DO2_GPIO_Port;
			channel.pin=DO2_Pin;
			break;
		// Digital input pins (8)
		case 2:
			channel.port=DI1_GPIO_Port;
			channel.pin=DI1_Pin;
			break;
		case 1:
			channel.port=DI2_GPIO_Port;
			channel.pin=DI2_Pin;
			break;
	}

	return channel;
}
