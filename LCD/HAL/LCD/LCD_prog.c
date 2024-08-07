/*
 * LCD_prog.c
 *
 *  Created on: Oct 16, 2021
 *      Author: George Bassem
 */

#include "../../Libraries/Std_Types.h"
#include "../../Libraries/Err_State.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_priv.h"
#include "LCD_config.h"

#include <util/delay.h>

ES_t LCD_enumInit(void) {
	ES_t Local_enumErrorState = NotOkay;

	_delay_ms(50);

	DIO_enumSetPinDirection(PORT_RS, PIN_RS, OUTPUT);
	DIO_enumSetPinDirection(PORT_RW, PIN_RW, OUTPUT);
	DIO_enumSetPinDirection(PORT_EN, PIN_EN, OUTPUT);

	DIO_enumSetPinDirection(PORT_D4, PIN_D4, OUTPUT);
	DIO_enumSetPinDirection(PORT_D5, PIN_D5, OUTPUT);
	DIO_enumSetPinDirection(PORT_D6, PIN_D6, OUTPUT);
	DIO_enumSetPinDirection(PORT_D7, PIN_D7, OUTPUT);

#if LCD_MODE == FOUR_BIT
	DIO_enumSetPinValue(PORT_RS, PIN_RS, LOW);
	LCD_enumWriteLatch(0x28);

#elif LCD_MODE == EIGHT_BIT
	DIO_enumSetPinDirection(PORT_D0, PIN_D0, OUTPUT);
	DIO_enumSetPinDirection(PORT_D1, PIN_D1, OUTPUT);
	DIO_enumSetPinDirection(PORT_D2, PIN_D2, OUTPUT);
	DIO_enumSetPinDirection(PORT_D3, PIN_D3, OUTPUT);

	DIO_enumSetPinValue(PORT_RS, PIN_RS, LOW);
	LCD_enumWriteLatch(0x38);

#endif

	_delay_ms(1);
	DIO_enumSetPinValue(PORT_RS, PIN_RS, LOW);
	LCD_enumWriteLatch(0x0F);

	_delay_ms(1);
	DIO_enumSetPinValue(PORT_RS, PIN_RS, LOW);
	LCD_enumWriteLatch(0x01);

	_delay_ms(2);
	DIO_enumSetPinValue(PORT_RS, PIN_RS, LOW);
	LCD_enumWriteLatch(0x06);

	return Local_enumErrorState;
}

ES_t LCD_enumSendCommand(u8 Copy_u8Command) {
	ES_t Local_enumErrorState = NotOkay;

	DIO_enumSetPinValue(PORT_RS, PIN_RS, LOW);
	LCD_enumWriteLatch(Copy_u8Command);

	return Local_enumErrorState;
}

ES_t LCD_enumSendData(u8 Copy_u8Data) {
	ES_t Local_enumErrorState = NotOkay;

	DIO_enumSetPinValue(PORT_RS, PIN_RS, HIGH);
	LCD_enumWriteLatch(Copy_u8Data);

	return Local_enumErrorState;
}

static ES_t LCD_enumWriteLatch(u8 Copy_u8Byte) {
	ES_t Local_enumErrorState = NotOkay;

	DIO_enumSetPinValue(PORT_RW, PIN_RW, LOW);
	DIO_enumSetPinValue(PORT_EN, PIN_EN, LOW);

	if(Copy_u8Byte == 0x28) {
		DIO_enumSetPinValue(PORT_D4, PIN_D4, ((Copy_u8Byte >> PIN4) & 1));
		DIO_enumSetPinValue(PORT_D5, PIN_D5, ((Copy_u8Byte >> PIN5) & 1));
		DIO_enumSetPinValue(PORT_D6, PIN_D6, ((Copy_u8Byte >> PIN6) & 1));
		DIO_enumSetPinValue(PORT_D7, PIN_D7, ((Copy_u8Byte >> PIN7) & 1));

		DIO_enumSetPinValue(PORT_EN, PIN_EN, HIGH);
		_delay_ms(2);
		DIO_enumSetPinValue(PORT_EN, PIN_EN, LOW);
		_delay_ms(50);
	}

	DIO_enumSetPinValue(PORT_D4, PIN_D4, ((Copy_u8Byte >> PIN4) & 1));
	DIO_enumSetPinValue(PORT_D5, PIN_D5, ((Copy_u8Byte >> PIN5) & 1));
	DIO_enumSetPinValue(PORT_D6, PIN_D6, ((Copy_u8Byte >> PIN6) & 1));
	DIO_enumSetPinValue(PORT_D7, PIN_D7, ((Copy_u8Byte >> PIN7) & 1));

#if LCD_MODE == FOUR_BIT
	DIO_enumSetPinValue(PORT_EN, PIN_EN, HIGH);
	_delay_ms(2);
	DIO_enumSetPinValue(PORT_EN, PIN_EN, LOW);
	_delay_ms(50);

	DIO_enumSetPinValue(PORT_D4, PIN_D4, ((Copy_u8Byte >> PIN0) & 1));
	DIO_enumSetPinValue(PORT_D5, PIN_D5, ((Copy_u8Byte >> PIN1) & 1));
	DIO_enumSetPinValue(PORT_D6, PIN_D6, ((Copy_u8Byte >> PIN2) & 1));
	DIO_enumSetPinValue(PORT_D7, PIN_D7, ((Copy_u8Byte >> PIN3) & 1));

	DIO_enumSetPinValue(PORT_EN, PIN_EN, HIGH);
	_delay_ms(2);
	DIO_enumSetPinValue(PORT_EN, PIN_EN, LOW);
	_delay_ms(50);

#elif LCD_MODE == EIGHT_BIT
	DIO_enumSetPinValue(PORT_D0, PIN_D0, ((Copy_u8Byte >> PIN0) & 1));
	DIO_enumSetPinValue(PORT_D1, PIN_D1, ((Copy_u8Byte >> PIN1) & 1));
	DIO_enumSetPinValue(PORT_D2, PIN_D2, ((Copy_u8Byte >> PIN2) & 1));
	DIO_enumSetPinValue(PORT_D3, PIN_D3, ((Copy_u8Byte >> PIN3) & 1));

	DIO_enumSetPinValue(PORT_EN, PIN_EN, HIGH);
	_delay_ms(2);
	DIO_enumSetPinValue(PORT_EN, PIN_EN, LOW);
	_delay_ms(50);

#endif

	_delay_ms(50);

	return Local_enumErrorState;
}
