/*
 * UART_int.h
 *
 *  Created on: Dec 4, 2021
 *      Author: George Bassem
 */

#ifndef HAL_UART_UART_INT_H_
#define HAL_UART_UART_INT_H_

ES_t UART_enumInit(void);
ES_t UART_enumTransmitData(u8 Copy_u8DAta);
ES_t UART_enumReceiveData(void);
ES_t UART_enumEnableTransmitCompleteInterrupt(void);
ES_t UART_enumDisableTransmitCompleteInterrupt(void);
ES_t UART_enumEnableReceiveCompleteInterrupt(void);
ES_t UART_enumDisableReceiveCompleteInterrupt(void);

#endif /* HAL_UART_UART_INT_H_ */
