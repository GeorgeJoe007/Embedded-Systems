/*
 * LCD_int.h
 *
 *  Created on: Oct 16, 2021
 *      Author: George Bassem
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enumInit(void);
ES_t LCD_enumSendCommand(u8 Copy_u8Command);
ES_t LCD_enumSendData(u8 Copy_u8Data);

#endif /* LCD_INT_H_ */
