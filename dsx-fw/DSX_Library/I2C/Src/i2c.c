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
// Note: slave_address can be 0 - 127 (0x00 - 0x7F)
void I2C_Write(uint16_t slave_address, uint8_t i2c_data)
{
	HAL_I2C_Master_Transmit(&hi2c1, (slave_address << 1), &i2c_data, 1, 100);
}

