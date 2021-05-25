/*
 * serial.c
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#include "serial.h"

#define BUFFER_SIZE		11U

static uint8_t buffer[BUFFER_SIZE];

// Function to receive serial data via DMA
void Serial_Receive_DMA(void)
{
	HAL_UART_Receive_DMA(&hlpuart1, buffer, sizeof(buffer));
}

// Function to parse buffer and store into dsx data
void parse_buffer_to_dsx_data(DSX_data_t *data)
{
	data->ID = buffer[0]*10 + buffer[1];
	data->loc = buffer[2]*10 + buffer[3];
	data->sign = buffer[4];
	data->val = buffer[5]*1000 + buffer[6]*100 + buffer[7]*10 + buffer[8];
	data->ret = buffer[9];
}
