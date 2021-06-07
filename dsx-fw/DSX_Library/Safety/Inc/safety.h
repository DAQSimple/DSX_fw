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


// State definitions - See state
#define STATE_NORMAL            (0)
#define STATE_FAULT_OVER_CURR   (1U)
#define STATE_FAULT_USB         (2U)
#define STATE_FAULT_OVER_TEMP   (3U)
#define	STATE_FAULT_REV_POL     (4U)
#define STATE_FAULT_UART        (5U)
#define STATE_FAULT_WATCHDOG    (6U)

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

// Functions for updating the 3 debug LEDs
void update_debug_leds(uint8_t state);
void write_debug_leds(uint8_t led1_state, uint8_t led2_state, uint8_t led3_state);

// Function to init current sense timer and state
void safety_init(void);


#endif /* SAFETY_H */
