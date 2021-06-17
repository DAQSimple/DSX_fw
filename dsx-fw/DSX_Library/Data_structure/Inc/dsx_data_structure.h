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
	uint32_t val  	:14;
	uint32_t ret  	:4;
}DSX_data_t;


/* Function to initialize a DSX structure */
void DSX_data_init(volatile DSX_data_t *dsx_ptr);

// Setters for each value in the dsx data structure
void dsx_data_set_ID(volatile DSX_data_t *dsx_data, uint32_t set_ID);
void dsx_data_set_loc(volatile DSX_data_t *dsx_data, uint32_t set_loc);
void dsx_data_set_sign(volatile DSX_data_t *dsx_data, uint32_t set_sign);
void dsx_data_set_val(volatile DSX_data_t *dsx_data, uint32_t set_val);
void dsx_data_set_ret(volatile DSX_data_t *dsx_data, uint32_t set_ret);

// Getters for each value in the dsx data structure
uint32_t dsx_data_get_ID(void);
uint32_t dsx_data_get_loc(void);
uint32_t dsx_data_get_sign(void);
uint32_t dsx_data_get_val(void);
uint32_t dsx_data_get_ret(void);


#endif /* DATA_STRUCTURE_INC_DSX_DATA_STRUCTURE_H_ */
