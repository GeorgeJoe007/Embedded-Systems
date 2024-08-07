/*
 * DIO_prog.c
 *
 *  Created on: Oct 9, 2021
 *      Author: George Bassem
 */

#include "../../Libraries/Std_Types.h"
#include "../../Libraries/Err_State.h"

#include "DIO_priv.h"
#include "DIO_int.h"

ES_t DIO_enumSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction) {
	ES_t Local_enumErrorState = NOK;

	if (Copy_u8GroupID <= GROUP_D && Copy_u8PinID <= PIN7 && Copy_u8Direction <= OUTPUT) {
		switch (Copy_u8GroupID) {
		case GROUP_A:
			DDRA &= ~(1 << Copy_u8PinID);
			DDRA |= (Copy_u8Direction << Copy_u8PinID);
			break;

		case GROUP_B:
			DDRB &= ~(1 << Copy_u8PinID);
			DDRB |= (Copy_u8Direction << Copy_u8PinID);
			break;

		case GROUP_C:
			DDRC &= ~(1 << Copy_u8PinID);
			DDRC |= (Copy_u8Direction << Copy_u8PinID);
			break;

		case GROUP_D:
			DDRD &= ~(1 << Copy_u8PinID);
			DDRD |= (Copy_u8Direction << Copy_u8PinID);
			break;
		}

		Local_enumErrorState = OK;
	}

	else {
		Local_enumErrorState = Range;
	}

	return Local_enumErrorState;
}

ES_t DIO_enumSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value) {
	ES_t Local_enumErrorState = NOK;

	if (Copy_u8GroupID <= GROUP_D && Copy_u8PinID <= PIN7 && Copy_u8Value <= HIGH) {
		switch (Copy_u8GroupID) {
		case GROUP_A:
			PORTA &= ~(1 << Copy_u8PinID);
			PORTA |= (Copy_u8Value << Copy_u8PinID);
			break;

		case GROUP_B:
			PORTB &= ~(1 << Copy_u8PinID);
			PORTB |= (Copy_u8Value << Copy_u8PinID);
			break;

		case GROUP_C:
			PORTC &= ~(1 << Copy_u8PinID);
			PORTC |= (Copy_u8Value << Copy_u8PinID);
			break;

		case GROUP_D:
			PORTD &= ~(1 << Copy_u8PinID);
			PORTD |= (Copy_u8Value << Copy_u8PinID);
			break;
		}

		Local_enumErrorState = OK;
	}

	else {
		Local_enumErrorState = Range;
	}

    return Local_enumErrorState;
}

ES_t DIO_enumGetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 *Copy_u8Value) {
	ES_t Local_enumErrorState = NOK;

	if (Copy_u8GroupID <= GROUP_D && Copy_u8PinID <= PIN7) {
		switch (Copy_u8GroupID) {
		case GROUP_A:
			*Copy_u8Value = ((PINA >> Copy_u8PinID) & 1);
			break;

		case GROUP_B:
			*Copy_u8Value = ((PINB >> Copy_u8PinID) & 1);
			break;

		case GROUP_C:
			*Copy_u8Value = ((PINC >> Copy_u8PinID) & 1);
			break;

		case GROUP_D:
			*Copy_u8Value = ((PIND >> Copy_u8PinID) & 1);
			break;
		}

		Local_enumErrorState = OK;
	}

	else {
		Local_enumErrorState = Range;
	}

	return Local_enumErrorState;
}
