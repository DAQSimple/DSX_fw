/*
 * serial.c
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#include "serial.h"

#define BUFFER_SIZE		11U

static uint8_t rx_buffer[BUFFER_SIZE] = {0};
static uint8_t tx_buffer[BUFFER_SIZE] = {0};

// Function to receive serial data via DMA
void Serial_Receive_DMA(void)
{
	HAL_UART_Receive_DMA(&hlpuart1, rx_buffer, sizeof(rx_buffer));
}

// Function to transmit serial data via DMA
void Serial_Transmit_DMA(volatile DSX_data_t *data)
{
	tx_buffer[0] = data->ID / 10;
	tx_buffer[1] = data->ID % 10;
	tx_buffer[2] = data->loc / 10;
	tx_buffer[3] = data->loc % 10;
	tx_buffer[4] = data->sign;
	tx_buffer[5] = data->val / 1000;
	tx_buffer[6] = (data->val / 100) % 10;
	tx_buffer[7] = (data->val / 10) % 10;
	tx_buffer[8] = data->val % 10;
	tx_buffer[9] = data->val / 10000;
	tx_buffer[10] = '\n';

	HAL_UART_Transmit_DMA(&hlpuart1, tx_buffer, sizeof(tx_buffer));
}

// Function to parse buffer and store into dsx data
void parse_buffer_to_dsx_data(volatile DSX_data_t *data)
{
	if(rx_buffer[10] == '\n')
	{
		data->ID 	= rx_buffer[0]*10 + rx_buffer[1];
		data->loc 	= rx_buffer[2]*10 + rx_buffer[3];
		data->sign 	= rx_buffer[4];
		data->val 	= rx_buffer[5]*1000 + rx_buffer[6]*100 + rx_buffer[7]*10 + rx_buffer[8];
		data->ret 	= rx_buffer[9];
	}
}

// Callback for LPUART1
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	// convert ascii elements in buffer to integer
	for (int i=0 ; i<BUFFER_SIZE-1 ; i++)
	{
		//if buffer element is a digit (0-9) (See ASCII Table)
		if(rx_buffer[i] >= 48 && rx_buffer[i] <= 57)
		{
			rx_buffer[i] = rx_buffer[i] - '0';
		}
	}
}
