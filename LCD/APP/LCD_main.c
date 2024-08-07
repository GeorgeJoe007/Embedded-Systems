/*
 * LCD_main.c
 *
 *  Created on: Oct 16, 2021
 *      Author: George Bassem
 */

#include "../Libraries/Std_Types.h"
#include "../Libraries/Err_State.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_int.h"

#include <util/delay.h>

int main () {
	LCD_enumInit();

	return 0;
}
