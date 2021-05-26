/*
 * serial.h
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#ifndef SERIAL_H
#define SERIAL_H

#include "main.h"
#include "stdint.h"
#include "dsx_data_structure.h"


// HLPUART handle
extern UART_HandleTypeDef hlpuart1;

// Function to receive serial data via DMA
void Serial_Receive_DMA(void);

// Function to transmit serial data via DMA
void Serial_Transmit_DMA(volatile DSX_data_t *data);

// Function to parse buffer and store into dsx data
void parse_buffer_to_dsx_data(volatile DSX_data_t *data);


#endif /* SERIAL_H */
