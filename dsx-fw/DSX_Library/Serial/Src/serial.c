/*
 * serial.c
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#include "serial.h"

static uint8_t buffer[12];

void Serial_Receive_DMA(void)
{
	HAL_UART_Receive_DMA(&hlpuart1, buffer, sizeof(buffer));
}
