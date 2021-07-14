/*
 * i2c.h
 *
 *  Created on: Jun 24, 2021
 *      Author: jpaca
 */

#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

#define I2C_SLAVE_ADDRESS_0		0
#define I2C_SLAVE_ADDRESS_1		1U
#define I2C_SLAVE_ADDRESS_2		2U
#define I2C_SLAVE_ADDRESS_3		3U
#define I2C_SLAVE_ADDRESS_4		4U
#define I2C_SLAVE_ADDRESS_5		5U
#define I2C_SLAVE_ADDRESS_6		6U
#define I2C_SLAVE_ADDRESS_7		7U
#define I2C_SLAVE_ADDRESS_8		8U
#define I2C_SLAVE_ADDRESS_9		9U

// Init I2C
void I2C_Init(void);

// driver function for i2c write
void I2C_Write(uint16_t slave_address, uint8_t i2c_data);

// driver function for i2c read
uint8_t I2C_Read(uint16_t slave_address);

#endif /* I2C_H */
