/*
 * dsx_data_structure.c
 *
 *  Created on: May 24, 2021
 *      Author: jpaca
 */

#include "dsx_data_structure.h"


/* Function to initialize a DSX structure */
void DSX_data_init(DSX_data_t *dsx_ptr)
{
	dsx_ptr->ID 	= 0;
	dsx_ptr->loc 	= 0;
	dsx_ptr->sign 	= 0;
	dsx_ptr->val 	= 0;
	dsx_ptr->ret 	= 0;
}
