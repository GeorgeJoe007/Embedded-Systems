#ifndef TIM0_INT_H_
#define TIM0_INT_H_

#define NULL 0

// TIM0 Waveform Generation Modes
#define NORMAL            0
#define PWM_PHASE_CORRECT 1
#define CTC               2
#define FAST_PWM          3

// TIM0 Compare Output Modes, non-PWM Mode
#define OC0_DISCONNECTED 0
#define TOGGLE_OC0       1
#define CLEAR_OC0        2
#define SET_OC0          3

// TIM0 Compare Output Modes, Fast PWM Mode
#define NIN_INVERTING 2
#define INVERTING     3

// TIM0 Clock Source
#define PRESCALER_1                    1
#define PRESCALER_8                    2
#define PRESCALER_64                   3
#define PRESCALER_256                  4
#define PRESCALER_1024                 5
#define EXTERNAL_CLOCK_ON_FALLING_EDGE 6
#define EXTERNAL_CLOCK_ON_RISING_EDGE  7

// TIM0 Interrupts
#define TIM0_OVF_INT 0
#define TIM0_CTC_INT 1

// TIM0 Interrupts Flags
#define TIM0_OVF_FLAG 0
#define TIM0_CTC_FLAG 1

// TIM0 Interrupt Status
#define TIM0_INT_DISABLE 0
#define TIM0_INT_ENABLE  1

void TIM0_voidInit(void);
void TIM0_voidPreload(u8 Copy_u8PreloadValue);
void TIM0_voidSetCompareMatch(u8 Copy_u8CompareMatchValue);
void TIM0_voidEnable(void);
void TIM0_voidDisable(void);
void TIM0_voidClearFlag(u8 Copy_u8Flag);
u8 TIM0_u8GetFlagStatus(u8 Copy_u8Flag);
void TIM0_voidsetCallBack(void (*Copy_CallBack)(void));

#endif