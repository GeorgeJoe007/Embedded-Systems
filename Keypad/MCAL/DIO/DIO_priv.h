/*
 * priv.h
 *
 *  Created on: Oct 9, 2021
 *      Author: George Bassem
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

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

#define DDRA  *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA  *((u8*)0x39)

#define DDRB  *((u8*)0x38)
#define PORTB *((u8*)0x37)
#define PINB  *((u8*)0x36)

#define DDRC  *((u8*)0x35)
#define PORTC *((u8*)0x34)
#define PINC  *((u8*)0x33)

#define DDRD  *((u8*)0x32)
#define PORTD *((u8*)0x31)
#define PIND  *((u8*)0x30)

#endif /* DIO_PRIV_H_ */
