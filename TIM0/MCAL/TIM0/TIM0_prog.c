#include "Std_Types.h"
#include "Bit_Math.h"

#include "INT_priv.h"

#include "TIM0_priv.h"
#include "TIM0_int.h"
#include "TIM0_config.h"

void (*Local_CallBack)(void) = NULL;

void TIM0_voidInit(void){
    CLR_BIT(TCCR0, FOC0);

#if TIM0_MODE == NORMAL
    CLR_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);

#elif TIM0_MODE == PWM_PHASE_CORRECT
    SET_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);

#elif TIM0_MODE == CTC
    CLR_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

#elif TIM0_MODE == FAST_PWM
    SET_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

#endif

#if TIM0_OC0_MODE == OC0_DISCONNECTED
    CLR_BIT(TCCR0, COM00);
    CLR_BIT(TCCR0, COM01);

#elif TIM0_OC0_MODE == TOGGLE_OC0 && TIM0_MODE == CTC
    SET_BIT(TCCR0, COM00);
    CLR_BIT(TCCR0, COM00);

#elif TIM0_OC0_MODE == CLEAR_OC0 || TIM0_OC0_MODE == NIN_INVERTING
    CLR_BIT(TCCR0, COM00);
    SET_BIT(TCCR0, COM01);

#elif TIM0_OC0_MODE == SET_OC0 || TIM0_OC0_MODE == INVERTING
    SET_BIT(TCCR0, COM00);
    SET_BIT(TCCR0, COM01);

#endif

#if TIM0_INT_STATUS == TIM0_INT_ENABLE
    if(TIM0_INT_SOURCE == TIM0_OVF_INT){
        SET_BIT(TIMSK, TOIE0);
    }

    else if(TIM0_INT_SOURCE == TIM0_CTC_INT){
        SET_BIT(TIMSK, OCIE0);
    }

#elif TIM0_INT_STATUS == TIM0_INT_DISABLE
    if(TIM0_INT_SOURCE == TIM0_OVF_INT){
        CLR_BIT(TIMSK, TOIE0);
    }

    else if(TIM0_INT_SOURCE == TIM0_CTC_INT){
        CLR_BIT(TIMSK, OCIE0);
    }

#endif

TCNT0 = 0;    
}

void TIM0_voidPreload(u8 Copy_u8PreloadValue){
    TCNT0 = Copy_u8PreloadValue;
}

void TIM0_voidSetCompareMatch(u8 Copy_u8CompareMatchValue){
    OCR0 = Copy_u8CompareMatchValue;
}

void TIM0_voidEnable(void){
#if TIM0_CLOCK_SOURCE == PRESCALER_1
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);

#elif TIM0_CLOCK_SOURCE == PRESCALER_8
    CLR_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);

#elif TIM0_CLOCK_SOURCE == PRESCALER_64
    SET_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);

#elif TIM0_CLOCK_SOURCE == PRESCALER_256
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);

#elif TIM0_CLOCK_SOURCE == PRESCALER_1024
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);

#elif TIM0_CLOCK_SOURCE == EXTERNAL_CLOCK_ON_FALLING_EDGE
    CLR_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);

#elif TIM0_CLOCK_SOURCE == EXTERNAL_CLOCK_ON_RISING_EDGE
    SET_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);

#endif
}

void TIM0_voidDisable(void){
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
}

void TIM0_voidClearFlag(u8 Copy_u8Flag){
    if(Copy_u8Flag == TIM0_OVF_FLAG){
        return CLR_BIT(TIFR, TOV0);
    }
    
    else if (Copy_u8Flag == TIM0_CTC_FLAG){
         return CLR_BIT(TIFR, OCF0);
    }
}

u8 TIM0_u8GetFlagStatus(u8 Copy_u8Flag){
    if(Copy_u8Flag == TIM0_OVF_FLAG){
        return GET_BIT(TIFR, TOV0);
    }
    
    else if (Copy_u8Flag == TIM0_CTC_FLAG){
         return GET_BIT(TIFR, OCF0);
    }
}

void TIM0_voidsetCallBack(void (*Copy_CallBack)(void)){
    if(Copy_CallBack != NULL){
        Local_CallBack = Copy_CallBack;
    }
}

ISR(TIMER0_COMP){
    if(TIM0_INT_SOURCE == TIM0_CTC_INT){
        Local_CallBack();
    }
}

ISR(TIMER0_OVF){
    if(TIM0_INT_SOURCE == TIM0_OVF_INT){
        Local_CallBack();
    }   
}