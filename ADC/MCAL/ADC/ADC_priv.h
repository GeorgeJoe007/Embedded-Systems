/*
 * ADC_priv.h
 *
 *  Created on: Feb 27, 2022
 *      Author: George Bassem
 */

#ifndef MCAL_ADC_PRIV_H_
#define MCAL_ADC_PRIV_H_

#define ADMUX  *((u8*)0x27)
#define ADCSRA *((u8*)0x26)
#define ADCH   *((u8*)0x25)
#define ADCL   *((u8*)0x24)
#define SFIOR  *((u8*)0x50)

/* ADC Multiplexer Selection Register */
#define REFS1 7
#define REFS0 6
#define ADLAR 5

/* ADC Control and Status Register A */
#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

/* ADC Voltage Reference Selections */
#define AREF_REF     0
#define AVCC_REF     1
#define INTERNAL_REF 3

/* ADC Result Presentation */
#define LEFT_ADJUSTEMENT  1
#define RIGHT_ADJUSTEMENT 0

#define CHANNELS 31

/* ADC Prescaler Selections */
#define DIVISION_FACTOR2   0
#define DIVISION_FACTOR4   2
#define DIVISION_FACTOR8   3
#define DIVISION_FACTOR16  4
#define DIVISION_FACTOR32  5
#define DIVISION_FACTOR64  6
#define DIVISION_FACTOR128 7

#endif /* MCAL_ADC_PRIV_H_ */
