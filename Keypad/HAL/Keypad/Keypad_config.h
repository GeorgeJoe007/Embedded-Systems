/*
 * Keypad_config.h
 *
 *  Created on: Oct 16, 2021
 *      Author: George Bassem
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define ROW_NUMBER    4
#define COLUMN_NUMBER 4

#define KEYPAD_VALUES { {'7', '8', '9', '+'},\
                        {'4', '5', '6', '-'},\
						{'1', '2', '3', '*'},\
						{'c', '0', '=', '/'} }

#define PORT_ROW0 GROUP_C
#define PIN_ROW0  PIN3

#define PORT_ROW1 GROUP_C
#define PIN_ROW1  PIN4

#define PORT_ROW2 GROUP_C
#define PIN_ROW2  PIN5

#define PORT_ROW3 GROUP_C
#define PIN_ROW3  PIN6

#define PORT_COLUMN0 GROUP_B
#define PIN_COLUMN0  PIN4

#define PORT_COLUMN1 GROUP_B
#define PIN_COLUMN1  PIN5

#define PORT_COLUMN2 GROUP_B
#define PIN_COLUMN2  PIN6

#define PORT_COLUMN3 GROUP_B
#define PIN_COLUMN3  PIN7

#endif /* KEYPAD_CONFIG_H_ */
