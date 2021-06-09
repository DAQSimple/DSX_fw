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
#define DO2 10U		// on PC7
#define PWM1 11U	// on PA6
#define PWM2 12U	// on PA7

/* DIGITAL INPUTS */
#define DI1 1U		// PC5
#define DI2 2U		// PC4
#define DI3 3U		// PA10
#define DI4 4U		// PB3
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

#endif /* BOARD_DEFINES_H */
