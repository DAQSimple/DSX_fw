/*
 * i2c.c
 *
 *  Created on: Jun 24, 2021
 *      Author: jpaca
 */
#include "i2c.h"

// Init I2C
void I2C_Init(void)
{
	HAL_I2C_Init(&hi2c1);
}

// driver function for i2c write
// Note: slave_address can be 0 - 9 (0x00 - 0x9)
void I2C_Write(uint16_t slave_address, uint8_t i2c_data)
{
	HAL_I2C_Master_Transmit(&hi2c1, (slave_address << 1), &i2c_data, 1, 100);
}

// driver function for i2c read
// Note: slave_address can be 0 - 9 (0x00 - 0x9)
uint8_t I2C_Read(uint16_t slave_address)
{
	uint8_t i2c_rx_data;
	HAL_I2C_Master_Receive(&hi2c1, (slave_address << 1), &i2c_rx_data, 1, 100);
	return i2c_rx_data;
}

