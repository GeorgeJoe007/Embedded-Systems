/*
 * LCD_config.h
 *
 *  Created on: Oct 16, 2021
 *      Author: George Bassem
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_MODE FOUR_BIT

/* Control Pins Configuration */
#define PORT_RS GROUP_B
#define PIN_RS  PIN1

#define PORT_RW GROUP_B
#define PIN_RW  PIN2

#define PORT_EN GROUP_B
#define PIN_EN  PIN3

/* Data Pins Configuration */
#define PORT_D0 GROUP_A
#define PIN_D0  PIN0

#define PORT_D1 GROUP_A
#define PIN_D1  PIN1

#define PORT_D2 GROUP_A
#define PIN_D2  PIN2

#define PORT_D3 GROUP_A
#define PIN_D3  PIN3

#define PORT_D4 GROUP_A
#define PIN_D4  PIN4

#define PORT_D5 GROUP_A
#define PIN_D5  PIN5

#define PORT_D6 GROUP_A
#define PIN_D6  PIN6

#define PORT_D7 GROUP_A
#define PIN_D7  PIN7

#endif /* LCD_CONFIG_H_ */
