/*
 * Keypad_main.c
 *
 *  Created on: Oct 16, 2021
 *      Author: George Bassem
 */

#include "../Libraries/Std_Types.h"
#include "../Libraries/Err_State.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/Keypad/Keypad_int.h"
#include "../HAL/Keypad/Keypad_config.h"

#include <util/delay.h>

int main () {
	Keypad_enumInit();

	return 0;
}
