/*
 * serial.h
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#ifndef SERIAL_INC_SERIAL_H_
#define SERIAL_INC_SERIAL_H_

#include "main.h"
#include "stdint.h"


// HLPUART handle
extern UART_HandleTypeDef hlpuart1;

// Function to receive serial data via DMA
void Serial_Receive_DMA(void);

// Function to parse buffer and store into dsx data
//void parse_buffer_to_dsx_data(DSX_data_t *data);


#endif /* SERIAL_INC_SERIAL_H_ */
