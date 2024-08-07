#include "Std_Types.h"
#include "Bit_Math.h"

#include "LED_int.h"

#include "DIO_int.h"

#include "util/delay.h"

void LED_vidON(u8 Copy_u8GroupID, u8 Copy_u8PinID){
        DIO_vidSetPinDirection(Copy_u8GroupID, Copy_u8PinID, OUTPUT);
        DIO_vidSetPinValue(Copy_u8GroupID, Copy_u8PinID, HIGH);
}

void LED_vidOFF(u8 Copy_u8GroupID, u8 Copy_u8PinID){
        DIO_vidSetPinDirection(Copy_u8GroupID, Copy_u8PinID, OUTPUT);
        DIO_vidSetPinValue(Copy_u8GroupID, Copy_u8PinID, LOW);
}

void LED_vidToggle(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Speed){
    DIO_vidTogglePin(Copy_u8GroupID, Copy_u8PinID);
    delay_ms_(Copy_u8Speed);
}
