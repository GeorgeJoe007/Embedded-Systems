/*
 * ADC_int.h
 *
 *  Created on: Feb 27, 2022
 *      Author: George Bassem
 */

#ifndef MCAL_ADC_INT_H_
#define MCAL_ADC_INT_H_

ES_t ADC_enumInit(void);
ES_t ADC_enumSelectChannel(u8 Copy_u8ChannelID);
ES_t ADC_enumEnable(void);
ES_t ADC_enumDisable(void);
ES_t ADC_enumStartConversion(void);
ES_t ADC_enumEnableAutoTrigger(u8 Copy_u8Source);
ES_t ADC_enumDisableAutoTrigger(void);
ES_t ADC_enumEnableInterrupt(void);
ES_t ADC_enumDisableInterrupt(void);
ES_t ADC_enumRead(u16 *Copy_u16ReadingValue);
ES_t ADC_enumPolling(void);

#endif /* MCAL_ADC_INT_H_ */
