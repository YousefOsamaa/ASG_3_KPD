//General files
#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//Lower layers' files


//Module's own files
#include "DIO_Config.h"
#include "DIO_Private.h"


//Functions' implementation
extern ErrorState_t DIO_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;


    Local_u8_ErrorFlag = ES_OK;

    return Local_u8_ErrorFlag;
}

extern ErrorState_t DIO_enu_SetPinDiretion(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber, u8 Copy_u8_PinDirection)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if((Copy_u8_PinGroup <= DIO_PIN_GROUP_D) && (Copy_u8_PinNumber <= DIO_PIN_7) && (Copy_u8_PinDirection <= DIO_PIN_WRITE) )
    {
        switch (Copy_u8_PinGroup)
        {
            case DIO_PIN_GROUP_A:

            //Masking the bit
            DIO_DDRA &= ~( 1 << Copy_u8_PinNumber );
            //Placing the Pin Direction Value
            DIO_DDRA |= ( Copy_u8_PinDirection << Copy_u8_PinNumber );
            break;

            case DIO_PIN_GROUP_B:
            //Masking the bit
            DIO_DDRB &= ~( 1 << Copy_u8_PinNumber);
            //Placing the Pin Direction Value
            DIO_DDRB |= ( Copy_u8_PinDirection << Copy_u8_PinNumber );
            break;

            case DIO_PIN_GROUP_C:
            //Masking the bit
            DIO_DDRC &= ~( 1 << Copy_u8_PinNumber);
            //Placing the Pin Direction Value
            DIO_DDRC |= ( Copy_u8_PinDirection << Copy_u8_PinNumber);
            break;

            case DIO_PIN_GROUP_D:
            //Masking the bit
            DIO_DDRD &= ~( 1 << Copy_u8_PinNumber);
            //Placing the Pin Direction Value
            DIO_DDRD |= ( Copy_u8_PinDirection << Copy_u8_PinNumber);
            break;

            default:
            break;
        }

        Local_u8_ErrorFlag = ES_OK;

    }
    else
    {
        Local_u8_ErrorFlag =ES_OUT_OF_RANGE;
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t DIO_enu_SetPinState(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber, u8 Copy_u8_PinState)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if((Copy_u8_PinGroup <= DIO_PIN_GROUP_D) && (Copy_u8_PinNumber <= DIO_PIN_7) && (Copy_u8_PinState <= DIO_PULL_UP))
    {
        switch (Copy_u8_PinGroup)
        {
            case DIO_PIN_GROUP_A:
            DIO_PORTA &= ~( 1 << Copy_u8_PinNumber);
            DIO_PORTA |= ( Copy_u8_PinState << Copy_u8_PinNumber);
            break;

            case DIO_PIN_GROUP_B:
            DIO_PORTB &= ~( 1 << Copy_u8_PinNumber);
            DIO_PORTB |= ( Copy_u8_PinState << Copy_u8_PinNumber);
            break;

            case DIO_PIN_GROUP_C:
            DIO_PORTC &= ~( 1 << Copy_u8_PinNumber);
            DIO_PORTC |= ( Copy_u8_PinState << Copy_u8_PinNumber);
            break;

            case DIO_PIN_GROUP_D:
            DIO_PORTD &= ~( 1 << Copy_u8_PinNumber);
            DIO_PORTD |= ( Copy_u8_PinState << Copy_u8_PinNumber);
            break;

            default:
            break;
        }

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t DIO_enu_SetPinValue(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber, u8 Copy_u8_PinValue)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if((Copy_u8_PinGroup <= DIO_PIN_GROUP_D ) && (Copy_u8_PinNumber <= DIO_PIN_7 ) && (Copy_u8_PinValue <= DIO_HIGH))
    {
        switch (Copy_u8_PinGroup)
        {
            case DIO_PIN_GROUP_A:
            if(Copy_u8_PinValue == DIO_HIGH)
            {
                DIO_PORTA |= ( 1 << Copy_u8_PinNumber );
            }
            else
            {
                DIO_PORTA &= ~ (1 << Copy_u8_PinNumber);
            }
            break;

            case DIO_PIN_GROUP_B:
            if(Copy_u8_PinValue == DIO_HIGH)
            {
                DIO_PORTB |= ( 1 << Copy_u8_PinNumber );
            }
            else
            {
                DIO_PORTB &= ~ (1 << Copy_u8_PinNumber);
            }
            break;

            case DIO_PIN_GROUP_C:
            if(Copy_u8_PinValue == DIO_HIGH)
            {
                DIO_PORTC |= ( 1 << Copy_u8_PinNumber );
            }
            else
            {
                DIO_PORTC &= ~ (1 << Copy_u8_PinNumber);
            }
            break;

            case DIO_PIN_GROUP_D:
            if(Copy_u8_PinValue == DIO_HIGH)
            {
                DIO_PORTD |= ( 1 << Copy_u8_PinNumber );
            }
            else
            {
                DIO_PORTD &= ~ (1 << Copy_u8_PinNumber);
            }
            break;
        }

        Local_u8_ErrorFlag = ES_OK;


    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t DIO_enu_TogglePinValue(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if ( (Copy_u8_PinGroup <= DIO_PIN_GROUP_D) && (Copy_u8_PinNumber <= DIO_PIN_7))
    {
        switch (Copy_u8_PinGroup)
        {
            case DIO_PIN_GROUP_A:
            DIO_PORTA ^= ( 1 << Copy_u8_PinNumber);
            break;

            case DIO_PIN_GROUP_B:
            DIO_PORTB ^= ( 1 << Copy_u8_PinNumber);
            break;

            case DIO_PIN_GROUP_C:
            DIO_PORTC ^= ( 1 << Copy_u8_PinNumber);
            break;

            case DIO_PIN_GROUP_D:
            DIO_PORTD ^= ( 1 << Copy_u8_PinNumber);
            break;

            default:
            break;
        }

        Local_u8_ErrorFlag = ES_OK;

    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t DIO_enu_GetPinValue(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber, u8* Copy_pu8_PinValue)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_pu8_PinValue)
    {

        if((Copy_u8_PinGroup <= DIO_PIN_GROUP_D ) && (Copy_u8_PinNumber <= DIO_PIN_7 ) )
        {
            switch (Copy_u8_PinGroup)
            {
                case DIO_PIN_GROUP_A:
                (*Copy_pu8_PinValue) = (DIO_PINA >> Copy_u8_PinNumber) & 1;
                break;

                case DIO_PIN_GROUP_B:
                (*Copy_pu8_PinValue) = (DIO_PINB >> Copy_u8_PinNumber) & 1;
                break;

                case DIO_PIN_GROUP_C:
                (*Copy_pu8_PinValue) = (DIO_PINC >> Copy_u8_PinNumber) & 1;
                break;

                case DIO_PIN_GROUP_D:
                (*Copy_pu8_PinValue) = (DIO_PIND >> Copy_u8_PinNumber) & 1;
                break;

                default:
                break;
            }

            Local_u8_ErrorFlag =ES_OK;


        }
        else
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        }

    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}






