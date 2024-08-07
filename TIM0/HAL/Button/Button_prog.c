#include "Std_Types.h"
#include "Bit_Math.h"

#include "Button_int.h"
#include "Button_priv.h"
#include "Button_config.h"

#include "DIO_int.h"

enuBUTTON_STATE Button_enuState(u8 Copy_u8GroupID, u8 Copy_u8PinID){
    u8 Local_u8Value;
    DIO_vidGetPinValue(Copy_u8GroupID, Copy_u8PinID, &Local_u8Value);

    if(RESISTOR == PULL_UP){
        if(Local_u8Value == GND){
            enuBUTTON_STATE Local_enuState = PRESSED;
        }

        else{
            Local_enuState = NOT_PRESSED;
        }
    }

    else {
        if(Local_u8Value == VCC){
            Local_enuState = PRESSED;
        }

        else{
            Local_enuState = NOT_PRESSED;
        }
    }

    return Local_enuState;
}
