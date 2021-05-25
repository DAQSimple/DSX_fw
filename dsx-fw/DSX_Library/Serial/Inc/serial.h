/*
 * serial.h
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#ifndef SERIAL_INC_SERIAL_H_
#define SERIAL_INC_SERIAL_H_

#include "main.h"


// HLPUART handle
extern UART_HandleTypeDef hlpuart1;

// Function to receive serial data via DMA
void Serial_Receive_DMA(void);


#endif /* SERIAL_INC_SERIAL_H_ */
