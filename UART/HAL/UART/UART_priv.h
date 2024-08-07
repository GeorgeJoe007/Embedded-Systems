/*
 * UART_priv.h
 *
 *  Created on: Dec 3, 2021
 *      Author: George Bassem
 */

#ifndef HAL_UART_UART_PRIV_H_
#define HAL_UART_UART_PRIV_H_

#define NORMAL 1
#define DOUBLE 2

#define DISABLE 0
#define ENABLE  1

#define DISABLED 0
#define ENABLED_EVEN_PARITY 2
#define ENABLED_ODD_PARITY  3

#define SYNCHRONOUS  0
#define ASYNCHRONOUS 1

#define ONE_BIT  1
#define TWO_BITS 2

#define FIVE_BITS  5
#define SIX_BITS   6
#define SEVEN_BITS 7
#define EIGHT_BITS 8
#define NINE_BITS  9

/* USART Control and Status Register A */
#define RXC  7
#define TXC  6
#define U2X  1
#define MPCM 0

/* USART Control and Status Register B */
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN  4
#define TXEN  3
#define UCSZ2 2

/* USART Control and Status Register C */
#define UCSZ0 1
#define UCSZ1 2
#define USBS  3
#define UPM0  4
#define UPM1  5
#define UMSEL 6

#define UCSRA *((u8*)0x2B)
#define UCSRB *((u8*)0x2B)
#define UCSRC *((u8*)0x40)
#define UBRRH *((u8*)0x40)
#define UBRRL *((u8*)0x29)

#define UDR *((u8*)0x2C)

#endif /* HAL_UART_UART_PRIV_H_ */
