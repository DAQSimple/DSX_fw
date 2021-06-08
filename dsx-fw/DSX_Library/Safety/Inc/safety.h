/*
* safety.h
*
*  Created on: Jun 3, 2021
*      Author: jpaca
*/

#ifndef SAFETY_H
#define SAFETY_H

#include "main.h"
#include <stdint.h>


// For initializing timer 4
extern TIM_HandleTypeDef htim4;

// State definitions - See state
#define STATE_NORMAL            (0)
#define STATE_FAULT_OVER_CURR   (1U)
#define STATE_FAULT_USB         (2U)
#define STATE_FAULT_OVER_TEMP   (3U)
#define	STATE_FAULT_REV_POL     (4U)
#define STATE_FAULT_UART        (5U)
#define STATE_FAULT_WATCHDOG    (6U)

// Thresholds - NOT SURE ABOUT THESE YET, NEED TO TEST VALUES BEFORE IMPLEMENTING
 #define MAX_TEMP_ALLOWED         (3000U)
 #define MAX_POSITIVE_CURRENT     (3800U)
 #define MAX_NEGATIVE_CURRENT     (500U)

// Debug LEDs
// These were defined in the Safety Driver Flowchart
#define DEBUG_LED_NO_POWER      0,  0,  0
#define DEBUG_LED_NORMAL_OP     0,  0,  1
#define DEBUG_LED_OVER_CURR     0,  1,  0
#define DEBUG_LED_OVER_TEMP     0,  1,  1
#define DEBUG_LED_USB           1,  0,  0
#define DEBUG_LED_REV_POL       1,  0,  1
#define DEBUG_LED_UART          1,  1,  0
#define DEBUG_LED_WATCHDOG      1,  1,  1

// Multiplexer channel for cycling through, for readability
#define MUX_CHANNEL_0		(0)
#define MUX_CHANNEL_1		(1U)
#define MUX_CHANNEL_2		(2U)
#define MUX_CHANNEL_3		(3U)
#define MUX_CHANNEL_4		(4U)
#define MUX_CHANNEL_5		(5U)
#define MUX_CHANNEL_6		(6U)
#define MUX_CHANNEL_7		(7U)
#define MUX_CHANNEL_8		(8U)
#define MUX_CHANNEL_9		(9U)
#define MUX_CHANNEL_10		(10U)
#define MUX_CHANNEL_11		(11U)
#define MUX_CHANNEL_12		(12U)
#define MUX_CHANNEL_13		(13U)
#define MUX_CHANNEL_14		(14U)
#define MUX_CHANNEL_15		(15U)
#define MUX_CHANNEL_END		MUX_CHANNEL_15

// Functions for updating the 3 debug LEDs
void update_debug_leds(uint8_t state);
void write_debug_leds(uint8_t led1_state, uint8_t led2_state, uint8_t led3_state);

// Fault event handlers
void DSX_Fault_Handler(uint8_t state);

// Function to init current sense timer and state
void safety_init(void);


#endif /* SAFETY_H */
