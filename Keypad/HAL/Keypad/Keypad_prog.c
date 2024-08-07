/*
 * Keypad_prog.c
 *
 *  Created on: Oct 16, 2021
 *      Author: George Bassem
 */

#include "../../Libraries/Std_Types.h"
#include "../../Libraries/Err_State.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Keypad_priv.h"
#include "Keypad_config.h"

#include <util\delay.h>

ES_t Keypad_enumInit (void) {
	ES_t Local_enumErrorState = NOK;

	DIO_enumSetPinDirection (PORT_ROW0, PIN_ROW0, INPUT);
	DIO_enumSetPinDirection (PORT_ROW1, PIN_ROW1, INPUT);
	DIO_enumSetPinDirection (PORT_ROW2, PIN_ROW2, INPUT);
	DIO_enumSetPinDirection (PORT_ROW3, PIN_ROW3, INPUT);
	
	DIO_enumSetPinDirection (PORT_COLUMN0, PIN_COLUMN0, OUTPUT);
	DIO_enumSetPinDirection (PORT_COLUMN1, PIN_COLUMN1, OUTPUT);
	DIO_enumSetPinDirection (PORT_COLUMN2, PIN_COLUMN2, OUTPUT);
	DIO_enumSetPinDirection (PORT_COLUMN3, PIN_COLUMN3, OUTPUT);

	DIO_enumSetPinValue (PORT_COLUMN0, PIN_COLUMN0, HIGH);
	DIO_enumSetPinValue (PORT_COLUMN1, PIN_COLUMN1, HIGH);
	DIO_enumSetPinValue (PORT_COLUMN2, PIN_COLUMN2, HIGH);
	DIO_enumSetPinValue (PORT_COLUMN3, PIN_COLUMN3, HIGH);

	return Local_enumErrorState;
}

ES_t Keypad_enumGetPressed (u8 *Copy_u8KeyValue) {
	ES_t Local_enumErrorState = NOK;

	u8 Local_u8ColumnPorts [COLUMN_NUMBER] = {PORT_COLUMN0, PORT_COLUMN1, PORT_COLUMN2, PORT_COLUMN3};
	u8 Local_u8ColumnPins [COLUMN_NUMBER] = {PIN_COLUMN0, PIN_COLUMN1, PIN_COLUMN2, PIN_COLUMN3};

	u8 Local_u8RowPorts [ROW_NUMBER] = {PORT_ROW0, PORT_ROW1, PORT_ROW2, PORT_ROW3};
	u8 Local_u8RowPins [ROW_NUMBER] = {PIN_ROW0, PIN_ROW1, PIN_ROW2, PIN_ROW3};

	u8 Local_u8PinValue;

	for (u8 Local_u8ColumnIterator = 0; Local_u8ColumnIterator < COLUMN_NUMBER; Local_u8ColumnIterator++) {
		DIO_enumSetPinValue(Local_u8ColumnPorts [Local_u8ColumnIterator], Local_u8ColumnPins [Local_u8ColumnIterator], LOW);

		for (u8 Local_u8RowIterator = 0; Local_u8RowIterator < ROW_NUMBER; Local_u8RowIterator++) {
			DIO_enumGetPinValue(Local_u8RowPorts [Local_u8RowIterator], Local_u8RowPins [Local_u8RowIterator], &Local_u8PinValue);

			if (Local_u8PinValue == 0) {
				_delay_ms (10);
				DIO_enumGetPinValue(Local_u8RowPorts [Local_u8RowIterator], Local_u8RowPins [Local_u8RowIterator], &Local_u8PinValue);

				if (Local_u8PinValue == 0) {
					while (Local_u8PinValue == 0)
						DIO_enumGetPinValue(Local_u8RowPorts [Local_u8RowIterator], Local_u8RowPins [Local_u8RowIterator], &Local_u8PinValue);

					u8 Local_u8KeypadValues [ROW_NUMBER][COLUMN_NUMBER] = KEYPAD_VALUES;
					*Copy_u8KeyValue = Local_u8KeypadValues [Local_u8RowIterator][Local_u8ColumnIterator];

					Local_enumErrorState = OK;
				}

				Local_enumErrorState = Pressed;
			}
		}

		DIO_enumSetPinValue(Local_u8ColumnPorts [Local_u8ColumnIterator], Local_u8ColumnPins [Local_u8ColumnIterator], HIGH);
	}

	return Local_enumErrorState;
}
