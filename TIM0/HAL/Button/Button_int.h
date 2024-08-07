#ifndef BUTTON_INT_H_
#define BUTTON_INT_H_

enuBUTTON_STATE Button_enuState(u8 Copy_u8GroupID, u8 Copy_u8PinID);

typedef enum {
    PRESSED,
    NOT_PRESSED
} enuBUTTON_STATE;

#endif