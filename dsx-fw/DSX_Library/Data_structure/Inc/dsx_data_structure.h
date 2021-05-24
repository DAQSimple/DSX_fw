/*
 * dsx_data_structure.h
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#ifndef DATA_STRUCTURE_INC_DSX_DATA_STRUCTURE_H_
#define DATA_STRUCTURE_INC_DSX_DATA_STRUCTURE_H_


/* DSX data structure definition as bit field*/
typedef struct DSX_data_struct{
	uint32_t ID   	:7;
	uint32_t loc  	:6;
	uint32_t sign 	:1;
	uint32_t val  	:12;
	uint32_t ret  	:4;
}DSX_data_t;


#endif /* DATA_STRUCTURE_INC_DSX_DATA_STRUCTURE_H_ */
