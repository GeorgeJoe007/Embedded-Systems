/*
 * UART_prog.c
 *
 *  Created on: Dec 4, 2021
 *      Author: George Bassem
 */

#include "../../Libraries/Std_Types.h"
#include "../../Libraries/Err_State.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "UART_config.h"
#include "UART_priv.h"

ES_t UART_enumInit(void) {
	ES_t Local_enumErrorState = NOK;
	u8 UCSRA_Value, UCSRB_Value, UCSRC_Value;

#if USART_TRANSMITTER == ENABLE
	UCSRB_Value |= (1 << TXEN);

#elif USART_TRANSMITTER == DISABLE
	 UCSRB_Value &= ~(1 << TXEN);

#endif

#if USART_RECIEVER == ENABLE
	UCSRB_Value |= (1 << RXEN);

#elif USART_RECIEVER == DISABLE
	UCSRB_Value &= ~(1 << RXEN);

#endif

#if COMMUNICATION_MODE == COMMUNICATION
	UCSRA_Value |= (1 << MPCM);

#elif
	UCSRA_Value &= ~(1 << MPCM);

#endif

#if TRANSMISSION_SPEED  == NORMAL
	UCSRA_Value &= ~(1 << U2X);

#elif TRANSMISSION_SPEED == DOUBLE
	UCSRA_Value |= (1 << U2X);
#endif

#if CHARACTER_SIZE == FIVE_BITS
	UCSRB_Value &= ~(1 << UCSZ2);
	UCSRC_Value &= ~(1 << UCSZ1);
	UCSRC_Value &= ~(1 << UCSZ0);

#elif CHARACTER_SIZE == SIX_BITS
	UCSRB_Value &= ~(1 << UCSZ2);
	UCSRC_Value &= ~(1 << UCSZ1);
	UCSRC_Value |= (1 << UCSZ0);

#elif CHARACTER_SIZE == SEVEN_BITS
	UCSRB_Value &= ~(1 << UCSZ2);
	UCSRC_Value |= (1 << UCSZ1);
	UCSRC_Value &= ~(1 << UCSZ0);

#elif CHARACTER_SIZE == EIGHT_BITS
	UCSRB_Value &= ~(1 << UCSZ2);
	UCSRC_Value |= (1 << UCSZ1);
	UCSRC_Value |= (1 << UCSZ0);

#elif CHARACTER_SIZE == NINE_BITS
	UCSRB_Value |= (1 << UCSZ2);
	UCSRC_Value |= (1 << UCSZ1);
	UCSRC_Value |= (1 << UCSZ0);
#endif

#if REGISTER_EMPTY_INTERRUPT == DISABLE
	UCSRB_Value &= ~(1 << UDRIE);

#elif REGISTER_EMPTY_INTERRUPT == ENABLE
	UCSRB_Value |= (1 << UDRIE);
#endif

#if STOP_BITS_NUMBER == ONE_BIT
	UCSRC_Value &= ~(1 << USBS);

#elif STOP_BITS_NUMBER == TWO_BITS
	UCSRC_Value |= (1 << USBS);
#endif

#if USART_PARITY_MODE == DISABLED
	UCSRC_Value &= ~(1 << UPM0);
	UCSRC_Value &= ~(1 << UPM1);

#elif USART_PARITY_MODE == ENABLED_EVEN_PARITY
	UCSRC_Value &= ~(1 << UPM0);
	UCSRC_VALUE |= (1 << UPM1);

#elif USART_PARITY_MODE == ENABLED_ODD_PARITY
	UCSRC_VALUE |= (1 << UPM0);
	UCSRC_VALUE |= (1 << UPM1);
#endif

#if USART_MODE == SYNCHRONOUS
	UCSRC_Value &= ~(1 << UMSEL);

#elif USART_MODE == ASYNCHRONOUS
	UCSRC_Value |= (1 << UMSEL);
#endif

	UCSRA = UCSRA_Value;
	UCSRB = UCSRB_Value;
	UCSRC = UCSRC_Value;

	UBRRH = 0x00;
	UBRRL = 0x67;

	return Local_enumErrorState;
}

ES_t UART_enumTransmitData(u8 Copy_u8Data) {
	ES_t Local_enumErrorState = NOK;

	UDR = Copy_u8Data;

	while(!(UCSRA & (1 << TXC)));

	return Local_enumErrorState;
}

ES_t UART_enumRecieveData(void) {
	ES_t Local_enumErrorState = NOK;

	while(((UCSRA >> RXC) & 1) == 0);

	return UDR;

	return Local_enumErrorState;
}

ES_t UART_enumEnableRexeiveCompleteInterrupt(void) {
	ES_t Local_enumErrorState = NOK;

	UCSRB_Value |= (1 << RXCIE);

	return Local_enumErrorState;
}

ES_t UART_enumDisableReceiveCompleteInterrupt(void) {
	ES_t Local_enumErrorState = NOK;

	UCSRB_Value &= ~(1 << RXCIE);

	return Local_enumErrorState;
}

ES_t UART_enumEnableTransmitCompleteInterrupt(void) {
	ES_t Local_enumErrorState = NOK;

	UCSRB_Value |= (1 << TXCIE);

	return Local_enumErrorState;
}

ES_t UART_enumDisableransmitCompleteInterrupt(void) {
	ES_t Local_enumErrorState = NOK;

	UCSRB_Value &= ~(1 << TXCIE);

	return Local_enumErrorState;
}
