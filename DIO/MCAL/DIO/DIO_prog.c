#include "Std_Types.h"
#include "Bit_Math.h"
#include "Err_State.h"

#include "DIO_priv.h"
#include "DIO_int.h"

void DIO_vidSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction){
    if(Copy_u8GroupID <= GROUP_D && Copy_u8PinID <= PIN7 && Copy_u8Direction <= OUTPUT){
        switch(Copy_u8GroupID){
            case GROUP_A:
            CLR_BIT(DDRA, Copy_u8PinID);

            DDRA |= (Copy_u8Direction << Copy_u8PinID);
            break;

            case GROUP_B:
            CLR_BIT(DDRB, Copy_u8PinID);

            DDRB |= (Copy_u8Direction << Copy_u8PinID);
            break;

            case GROUP_C:
            CLR_BIT(DDRC, Copy_u8PinID);

            DDRC |= (Copy_u8Direction << Copy_u8PinID);
            break;

            case GROUP_D:
            CLR_BIT(DDRD, Copy_u8PinID);

            DDRD |= (Copy_u8Direction << Copy_u8PinID);
            break;
        }
    }
}

void DIO_vidSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value){
    if(Copy_u8GroupID <= GROUP_D && Copy_u8PinID <= PIN7 && Copy_u8Value <= HIGH){
        switch(Copy_u8GroupID){
            case GROUP_A:
            CLR_BIT(DDRA, Copy_u8PinID);

            PORTA |= (Copy_u8Value << Copy_u8PinID);
            break;

            case GROUP_B:
            CLR_BIT(DDRB, Copy_u8PinID);

            PORTB |= (Copy_u8Value << Copy_u8PinID);
            break;

            case GROUP_C:
            CLR_BIT(DDRC, Copy_u8PinID);

            PORTC |= (Copy_u8Value << Copy_u8PinID);
            break;

            case GROUP_D:
            CLR_BIT(DDRD, Copy_u8PinID);

            PORTD |= (Copy_u8Value << Copy_u8PinID);
            break;
        }
    }   
}

void DIO_vidGetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 *Local_u8Value){
    if(Copy_u8GroupID <= GROUP_D && Copy_u8PinID <= PIN7){
        switch(Copy_u8GroupID){
            case GROUP_A:
            *Local_u8Value = GET_BIT(PINA, Copy_u8PinID);
            break;

            case GROUP_B:
            *Local_u8Value = GET_BIT(PINB, Copy_u8PinID);
            break;

            case GROUP_C:
            *Local_u8Value = GET_BIT(PINC, Copy_u8PinID);
            break;

            case GROUP_D:
            *Local_u8Value = GET_BIT(PIND, Copy_u8PinID);
            break;
        }
    }
}

void DIO_vidTogglePin(u8 Copy_u8GroupID, u8 Copy_u8PinID) {
    if(Copy_u8GroupID <= GROUP_D && Copy_u8PinID <= PIN7){
        switch(Copy_u8GroupID){
            case GROUP_A:
            TOGGLE_BIT(PORTA, Copy_u8PinID);
            break;

            case GROUP_B:
            TOGGLE_BIT(PORTB, Copy_u8PinID);
            break;

            case GROUP_C:
            TOGGLE_BIT(PORTC, Copy_u8PinID);
            break;

            case GROUP_D:
            TOGGLE_BIT(PORTD, Copy_u8PinID);
            break;
        }
    }
}

void DIO_vidSetPortDirection(u8 Copy_u8GroupID, u8 Copy_u8Direction){
    if(Copy_u8GroupID <= GROUP_D && Copy_u8Direction <= OUTPUT){
        switch(Copy_u8Direction){
            case OUTPUT:
            switch(Copy_u8GroupID){
                case GROUP_A:
                DDRA = 0xFF;
                break;

                case GROUP_B:
                DDRB = 0xFF;
                break;

                case GROUP_C:
                DDRC = 0xFF;
                break;

                case GROUP_D:
                DDRD = 0xFF;
                break;
            }
            break;

            case INPUT:
            switch(Copy_u8GroupID){
                case GROUP_A:
                DDRA = 0x00;
                break;

                case GROUP_B:
                DDRB = 0x00;
                break;

                case GROUP_C:
                DDRC = 0x00;
                break;

                case GROUP_D:
                DDRD = 0x00;
                break;
            }
            break;
        }
    }
}

void DIO_vidSetPortValue(u8 Copy_u8GroupID, u8 Copy_u8Value){
    if(Copy_u8GroupID <= GROUP_D && Copy_u8Value <= HIGH){
        switch(Copy_u8GroupID){
            case GROUP_A:
            PORTA = Copy_u8Value;
            break;

            case GROUP_B:
            PORTB = Copy_u8Value;
            break;

            case GROUP_C:
            PORTC = Copy_u8Value;
            break;

            case GROUP_D:
            PORTD = Copy_u8Value;
            break;
        }
    }
}