#ifndef INT_PRIV_H_
#define INT_PRIV_H_

// Vectors
#define INT0         __vector_1
#define INT1         __vector_2
#define INT2         __vector_3
#define TIMER2_COMP  __vector_4
#define TIMER2_OVF   __vector_5
#define TIMER1_CAPT  __vector_6
#define TIMER1_COMPA __vector_7
#define TIMER1_COMPB __vector_8
#define TIMER1_OVF   __vector_9
#define TIMER0_COMP  __vector_10
#define TIMER0_OVF   __vector_11

// ISR
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)

#endif