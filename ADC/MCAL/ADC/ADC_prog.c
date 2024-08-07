/*
 * ADC_prog.c
 *
 *  Created on: Feb 27, 2022
 *      Author: George Bassem
 */

#include "../../Libraries/Std_Types.h"
#include "../../Libraries/Err_State.h"

#include "ADC_priv.h"
#include "ADC_config.h"

ES_t ADC_enumInit(void) {
	ES_t Local_enumErrorState = NotOkay;

#if VOLTAGE_REFERENCE == AREF_REF
	ADMUX &= ~(1 << REFS0);
	ADMUX &= ~(1 << REFS1);

#elif VOLTAGE_REFERENCE == AVCC_REF
	ADMUX |= (1 << REFS0);
	ADMUX &= ~(1 << REFS1);

#elif VOLTAGE_REFERENCE == INTERNAL_REF
	ADMUX |= (1 << REFS0);
	ADMUX |= (1 << REFS1);

#endif

#if RESULT_PRESENTATION == LEFT_ADJUSTEMENT
	ADMUX |= (1 << ADLAR);

#elif RESULT_PRESENTATION == RIGHT_ADJUSTEMENT
	ADMUX &= ~(1 << ADLAR);

#endif

#if PRESCALER == DIVISION_FACTOR64
	ADCSRA &= ~(1 << ADPS0);
	ADCSRA |= (1 << ADPS1);
	ADCSRA |= (1 << ADPS2);

#endif

	return Local_enumErrorState;
}

ES_t ADC_enumSelectChannel(u8 Copy_u8ChannelID) {
	ES_t Local_enumErrorState = NotOkay;

	if(Copy_u8ChannelID <= CHANNELS) {
		ADMUX &= ~0x1F;
		ADMUX |= Copy_u8ChannelID;
	}

	return Local_enumErrorState;
}

ES_t ADC_enumEnable(void) {
	ES_t Local_enumErrorState = NotOkay;

	ADCSRA |= (1 << ADEN);

	return Local_enumErrorState;
}

ES_t ADC_enumDisable(void) {
	ES_t Local_enumErrorState = NotOkay;

	ADCSRA &= ~(1 << ADEN);

	return Local_enumErrorState;
}

ES_t ADC_StartConversion(void) {
	ES_t Local_enumErrorState = NotOkay;

	ADCSRA |= (1 << ADSC);

	return Local_enumErrorState;
}

ES_t ADC_enumEnableAutoTrigger(u8 Copy_u8Source) {
	ES_t Local_enumErrorState = NotOkay;

	if(Copy_u8Source <= 7) {
		ADCSRA &= (1 << ADATE);

		SFIOR  |= (Copy_u8Source << ADATE);
		ADCSRA |= (1 << ADATE);
	}

	return Local_enumErrorState;

}

ES_t ADC_enumDisableAutoTrigger(void) {
	ES_t Local_enumErrorState = NotOkay;

	ADCSRA &= ~(1 << ADATE);

	return Local_enumErrorState;
}

ES_t ADC_enumEnableInterrupt(void) {
	ES_t Local_enumErrorState = NotOkay;

	ADCSRA |= (1 << ADIE);

	return Local_enumErrorState;
}

ES_t ADC_enumDisableInterrupt(void) {
	ES_t Local_enumErrorState = NotOkay;

	ADCSRA &= ~(1 << ADIE);

	return Local_enumErrorState;
}

ES_t ADC_enumRead(u16 *Copy_u16ReadingValue) {
	ES_t Local_enumErrorState = NotOkay;

#if RESULT_ADJUSTEMENT == LEFT
	*Copy_u16ReadingValue = ADCH;

#elif RESULT_ADJUSTEMENT == RIGHT
	*Copy_u16ReadingValue = ADCL;
	*Copy_u16ReadingValue = (ADCH << 8);

#endif

	return Local_enumErrorState;
}

ES_t ADC_enumPolling(void){
	ES_t Local_enumErrorState = NotOkay;

	while(!(ADCSRA >> ADIF) & 1)
	ADCSRA |= (1 << ADIF);

	return Local_enumErrorState;

}
