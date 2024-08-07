/*
 * UART_main.c
 *
 *  Created on: Dec 4, 2021
 *      Author: George Bassem
 */

#include "../Libraries/Std_Types.h"
#include "../Libraries/Err_State.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/UART/UART_config.h"
#include "../HAL/UART/UART_int.h"

int main() {
	UART_enumInit();

	return 0;
}
