/*
 * DIO_int.h
 *
 *  Created on: Oct 9, 2021
 *      Author: George Bassem
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

ES_t DIO_enumSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction);
ES_t DIO_enumSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value);
ES_t DIO_enumGetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 *Copy_u8Value);

#define LOW  0
#define HIGH 1

#define INPUT  0
#define OUTPUT 1

#define GROUP_A 0
#define GROUP_B 1
#define GROUP_C 2
#define GROUP_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#endif /* DIO_INT_H_ */
