/*
 * Encoder.c
 *
 *  Created on: Jun. 5, 2021
 *      Author: Manraj Sangha
 */
#include "Encoder.h"

void Encoder_Set_CPR(uint16_t CPR){
	  htim4.Init.Period = 65535;
}
