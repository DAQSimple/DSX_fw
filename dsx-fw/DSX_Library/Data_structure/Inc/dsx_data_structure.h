/*
 * dsx_data_structure.h
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#ifndef DSX_DATA_STRUCTURE_H
#define DSX_DATA_STRUCTURE_H

#include <stdint.h>

/* DSX data structure definition as bit field*/
typedef struct DSX_data_t{
	uint32_t ID   	:7;
	uint32_t loc  	:6;
	uint32_t sign 	:1;
	uint32_t val  	:12;
	uint32_t ret  	:4;
}DSX_data_t;


/* Function to initialize a DSX structure */
void DSX_data_init(volatile DSX_data_t *dsx_ptr);


#endif /* DATA_STRUCTURE_INC_DSX_DATA_STRUCTURE_H_ */
