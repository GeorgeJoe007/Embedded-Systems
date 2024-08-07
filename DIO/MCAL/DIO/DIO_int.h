#ifndef DIO_INT_H_
#define DIO_INT_H_

enum {
    GROUP_A,
    GROUP_B,
    GROUP_C,
    GROUP_D
} GROUP_ID;

enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} PIN_ID;

// Direction
#define INPUT  0
#define OUTPUT 1

// Value
#define LOW  0
#define HIGH 1

void DIO_vidSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction);
void DIO_vidSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value);
void DIO_vidGetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 *Local_u8Value);
void DIO_vidTogglePin(u8 Copy_u8GroupID, u8 Copy_u8PinID);
void DIO_vidSetPortDirection(u8 Copy_u8GroupID, u8 Copy_u8Direction);
void DIO_vidSetPortValue(u8 Copy_u8GroupID, u8 Copy_u8Value);

#endif /* DIO_INT_H_ */