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
		// Digital input pins (8)
		case DI1:
			channel.port=DI1_GPIO_Port;
			channel.pin=DI1_Pin;
			break;
		case DI2:
			channel.port=DI2_GPIO_Port;
			channel.pin=DI2_Pin;
			break;
		case DI3:
			channel.port=DI3_GPIO_Port;
			channel.pin=DI3_Pin;
			break;
		case DI4:
			channel.port=DI4_GPIO_Port;
			channel.pin=DI4_Pin;
			break;
		case DI5:
			channel.port=DI5_GPIO_Port;
			channel.pin=DI5_Pin;
			break;
		case DI6:
			channel.port=DI6_GPIO_Port;
			channel.pin=DI6_Pin;
			break;
		case DI7:
			channel.port=DI7_GPIO_Port;
			channel.pin=DI7_Pin;
			break;
		case DI8:
			channel.port=DI8_GPIO_Port;
			channel.pin=DI8_Pin;
			break;

		// Digital output pins (2)
		case DO1:
			channel.port=DO1_GPIO_Port;
			channel.pin=DO1_Pin;
			break;
		case DO2:
			channel.port=DO2_GPIO_Port;
			channel.pin=DO2_Pin;
			break;
	}

	return channel;
}
