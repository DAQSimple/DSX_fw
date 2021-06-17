/*
 * dsx_data_structure.c
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#include "dsx_data_structure.h"


/* Function to initialize a DSX structure */
void DSX_data_init(volatile DSX_data_t *dsx_ptr)
{
	dsx_ptr->ID 	= 0;
	dsx_ptr->loc 	= 0;
	dsx_ptr->sign 	= 0;
	dsx_ptr->val 	= 0;
	dsx_ptr->ret 	= 0;
}

// Variables for each value in the data structure so we can define getters for them
static uint32_t ID;
static uint32_t loc;
static uint32_t sign;
static uint32_t val;
static uint32_t ret;

// Setters for each value in the dsx data structure
void dsx_data_set_ID(volatile DSX_data_t *dsx_data, uint32_t set_ID){
	dsx_data->ID = set_ID;
	ID = set_ID;
}
void dsx_data_set_loc(volatile DSX_data_t *dsx_data, uint32_t set_loc){
	dsx_data->loc = set_loc;
	loc = set_loc;
}
void dsx_data_set_sign(volatile DSX_data_t *dsx_data, uint32_t set_sign){
	dsx_data->sign = set_sign;
	sign = set_sign;
}
void dsx_data_set_val(volatile DSX_data_t *dsx_data, uint32_t set_val){
	dsx_data->val = set_val;
	val = set_val;
}
void dsx_data_set_ret(volatile DSX_data_t *dsx_data, uint32_t set_ret){
	dsx_data->ret = set_ret;
	ret = set_ret;
}

// Getters for each value in the dsx data structure
uint32_t dsx_data_get_ID(void){
	return ID;
}
uint32_t dsx_data_get_loc(void){
	return loc;
}
uint32_t dsx_data_get_sign(void){
	return sign;
}
uint32_t dsx_data_get_val(void){
	return val;
}
uint32_t dsx_data_get_ret(void){
	return ret;
}
