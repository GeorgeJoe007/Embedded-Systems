#ifndef TIM0_PRIV_H_
#define TIM0_PRIV_H_

#define OCR0  *((volatile u8*) 0x5C)
#define TIMSK *((volatile u8*) 0x59)
#define TIFR  *((volatile u8*) 0x58)
#define TCCR0 *((volatile u8*) 0x53)
#define TCNT0 *((volatile u8*) 0x52)

// TCCR0
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0

// TIMSK
#define OCIE0 1
#define TOIE0 0

//TIFR
#define OCF0 1
#define TOV0 0

#endif