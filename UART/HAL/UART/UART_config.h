/*
 * UART_config.h
 *
 *  Created on: Dec 3, 2021
 *      Author: George Bassem
 */

#ifndef HAL_UART_UART_CONFIG_H_
#define HAL_UART_UART_CONFIG_H_

#define TRANSMISSION_SPEED NORMAL

#define CHARACTER_SIZE EIGHT_BITS

#define USART_TRANSMITTER ENABLE
#define USART_RECIEVER ENABLE
#define REGISTER_EMPTY_INTERRUPT DISABLE

#define STOP_BITS_NUMBER ONE_BIT
#define USART_MODE SYNCHRONOUS
#define USART_PARITY_MODE DISABLED

#endif /* HAL_UART_UART_CONFIG_H_ */