/*
 * serial.c
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#include "serial.h"

#define BUFFER_SIZE		11U

static uint8_t buffer[BUFFER_SIZE] = {0};

// Function to receive serial data via DMA
void Serial_Receive_DMA(void)
{
	HAL_UART_Receive_DMA(&hlpuart1, buffer, sizeof(buffer));
}

// Function to convert ascii elements in buffer to integer
void buffer_ascii_2_int(void)
{
	for (int i=0 ; i<BUFFER_SIZE-1 ; i++){

		//if buffer element is a digit (See ASCII Table)
		if(buffer[i] >= 49 && buffer[i] <= 54)
		{
			buffer[i] = buffer[i] - '0';
		}
		//reset buffer element to 0 since its probably a character or special character
		//which we can't process
		else
		{
			buffer[i] = 0;
		}
	}
}

// Function to parse buffer and store into dsx data
void parse_buffer_to_dsx_data(volatile DSX_data_t *data)
{
	buffer_ascii_2_int();

	if(buffer[10] == '\n')
	{
		data->ID = buffer[0]*10 + buffer[1];
		data->loc = buffer[2]*10 + buffer[3];
		data->sign = buffer[4];
		data->val = buffer[5]*1000 + buffer[6]*100 + buffer[7]*10 + buffer[8];
		data->ret = buffer[9];
	}
}

// Callback for LPUART1
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	// Do we need to do anything when the UART callback is called?
}
