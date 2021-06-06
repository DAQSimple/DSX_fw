/*
 * board_defines.h
 *
 *  Created on: Jun 3, 2021
 *      Author: Tim Saxon
 */

#ifndef BOARD_DEFINES_H
#define BOARD_DEFINES_H

#include "main.h"

/* DIGITAL OUTPUTS */
#define DO1 9U		// on PB6
#define DO2 10U		// on PA9
#define PWM1 11U	// on PA6
#define PWM2 12U	// on PA7

/* DIGITAL INPUTS */
#define DI1 1U		// PC5
#define DI2 2U		// PC4
#define DI3 3U		// PA10
#define DI4 4U		// oPB3
#define DI5 5U		// PB5
#define DI6 6U		// PB4
#define DI7 7U		// PB10
#define DI8 8U		// PA8

/* ANALOG INPUTS */
#define AI1 13U		// PC0
#define AI2 14U		// PC1
#define AI3 15U		// PA0
#define AI4 16U		// PA1

/* ANALOG OUTPUTS */
#define AO1 17U		// PA4
#define AO2 18U		// PA5

/* INDICATORS */
// lookup table values yet to be determined
#define USER_LD1 1U // PB13
#define USER_LD2 1U // PB14
#define USER_LD3 1U // PB14

#define ERROR_LD1 1U// PC2
#define ERROR_LD1 1U// PC2

/* I2C */
#define I2C_SCL_PIN 'PB8'
#define I2C_SDA_PIN 'PB9'

/* SPI */
#define SPI_SCK_PIN  'PC10'
#define SPI_MISO_PIN 'PC11'
#define SPI_MOSI_PIN 'PC12'

#endif /* BOARD_DEFINES_H */
