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

// Init I2C
void I2C_Init(void);

// driver function for i2c write
void I2C_Write(uint16_t slave_address, uint8_t i2c_data);

#endif /* I2C_H */
