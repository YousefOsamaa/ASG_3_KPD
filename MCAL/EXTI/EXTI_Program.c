#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"


extern u8 EXTI_u8_INTCount;
extern EXTI_t EXTI_astr_INTList [];

static void (*pfun_ISRPointers[EXTI_ISR_Count])(void*) = {NULL};
static void* apvid_ISRParameters[EXTI_ISR_Count] = {NULL};


//APIs implementations

extern ErrorState_t EXTI_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;
    for( Local_u8_Counter = 0; Local_u8_Counter < EXTI_u8_INTCount; Local_u8_Counter++)
    {
        enu_SetMode(EXTI_astr_INTList[Local_u8_Counter].INTNumber, EXTI_astr_INTList[Local_u8_Counter].INTMode);
        enu_SetSenseLevel(EXTI_astr_INTList[Local_u8_Counter].INTNumber, EXTI_astr_INTList[Local_u8_Counter].INTSenseLevel);
    }
    
    Local_u8_ErrorFlag = ES_OK;

    return Local_u8_ErrorFlag;
}

extern ErrorState_t EXTI_enu_ISC(u8 Copy_u8_INTNumber, u8 Copy_u8_SenseLevel)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    Local_u8_ErrorFlag = enu_SetSenseLevel(Copy_u8_INTNumber, Copy_u8_SenseLevel);

    return Local_u8_ErrorFlag;
}

extern ErrorState_t EXTI_enu_INTMode(u8 Copy_u8_INTNumber, u8 Copy_u8_Mode)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    Local_u8_ErrorFlag = enu_SetMode(Copy_u8_INTNumber, Copy_u8_Mode);

    return Local_u8_ErrorFlag;
}

extern ErrorState_t EXTI_enu_GetPIF (u8 Copy_u8_INTNumber, u8* Copy_pu8_Result)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if (Copy_pu8_Result)
    {

        switch(Copy_u8_INTNumber)
        {
            case EXTI_INT0:
            {
                *Copy_pu8_Result = 1 & (GIFR >> GIFR_INTF0);

                Local_u8_ErrorFlag = ES_OK;
                break;
            }
            case EXTI_INT1:
            {
                *Copy_pu8_Result = 1 & (GIFR >> GIFR_INTF1);

                Local_u8_ErrorFlag = ES_OK;

                break;
            }
            case EXTI_INT2:
            {
                *Copy_pu8_Result = 1 & (GIFR >> GIFR_INTF2);

                Local_u8_ErrorFlag = ES_OK;
                break;
            }

            default:
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;

                break;
            }
        }

    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }
    return Local_u8_ErrorFlag;
}

extern ErrorState_t EXTI_enu_SeTPIF (u8 Copy_u8_INTNumber, u8 Copy_u8_Value)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    Local_u8_ErrorFlag = enu_SetFlagValue(Copy_u8_INTNumber, Copy_u8_Value);

    return Local_u8_ErrorFlag;
}

extern ErrorState_t EXTI_enu_SetCallBack(u8 Copy_u8_INTNumber, void (* Copy_pfun_AppFunction)(void), void* Copy_pvid_Parameters)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_pfun_AppFunction)
    {
        pfun_ISRPointers[Copy_u8_INTNumber] = Copy_pfun_AppFunction;

        apvid_ISRParameters[Copy_u8_INTNumber] = Copy_pvid_Parameters;

        Local_u8_ErrorFlag = ES_OK;

    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }

    return Local_u8_ErrorFlag;
}


//ISR 
void __vector_1 (void)__attribute__((signal));
void __vector_2 (void)__attribute__((signal));
void __vector_3 (void)__attribute__((signal));

void __vector_1 (void)
{
    if(pfun_ISRPointers[EXTI_INT0])
    {
        pfun_ISRPointers[EXTI_INT0] (apvid_ISRParameters[EXTI_INT0]);
    }
}
//INT1
void __vector_2 (void)
{
    if(pfun_ISRPointers[EXTI_INT1])
    {
        pfun_ISRPointers[EXTI_INT1] (apvid_ISRParameters[EXTI_INT1]);
    }
}
//INT2
void __vector_3 (void)
{
    if(pfun_ISRPointers[EXTI_INT2])
    {
        pfun_ISRPointers[EXTI_INT2] (EXTI_INT2);
    }
    
}


//Local functions' implementations

static ErrorState_t enu_SetMode(u8 Copy_u8_INTNumber, u8 Copy_u8_Mode)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_INTNumber)
    {
        case EXTI_INT0:
        {   
            if (Copy_u8_Mode == EXTI_INT_MODE)
            {
                GICR |= ( 1 << GICR_INT0);
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if (Copy_u8_Mode == EXTI_POLLING_MODE)
            {
                GICR &= ~( 1 << GICR_INT0);

                Local_u8_ErrorFlag = ES_OK;
            }
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }
         
            break;
        }

        case EXTI_INT1:
        {
            if (Copy_u8_Mode == EXTI_INT_MODE)
            {
                GICR |= ( 1 << GICR_INT1);

                Local_u8_ErrorFlag = ES_OK;
            }
            else if (Copy_u8_Mode == EXTI_POLLING_MODE)
            {
                GICR &= ~( 1 << GICR_INT1);

                Local_u8_ErrorFlag = ES_OK;
            }
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }
            
            break;
        }
        case EXTI_INT2:
        {
            if (Copy_u8_Mode == EXTI_INT_MODE)
            {
                GICR |= ( 1 << GICR_INT2);
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if (Copy_u8_Mode == EXTI_POLLING_MODE)
            {
                GICR &= ~( 1 << GICR_INT2);

                Local_u8_ErrorFlag = ES_OK;
            }
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }

            break;
        }
    
        default:
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        break;
    }


    return Local_u8_ErrorFlag;    
}

static ErrorState_t enu_SetSenseLevel(u8 Copy_u8_INTNumber, u8 Copy_u8_SenseLevel)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_INTNumber)
    {
    case EXTI_INT0:
    {   
        //Clearing both bits
        MCUCR &= ~( 3 << MCUCR_ISC00);

        if(Copy_u8_SenseLevel == EXTI_LOW_LEVEL)
        {
            //Bits already contain 00
            Local_u8_ErrorFlag = ES_OK;
        }
        else if (Copy_u8_SenseLevel == EXTI_LOGICAL_CHANGE)
        {
            //Bits contain 01
            MCUCR |= ( 1 << MCUCR_ISC00);

            Local_u8_ErrorFlag = ES_OK;
        }
        else if (Copy_u8_SenseLevel == EXTI_FALLING_EDGE)
        {
            //Bits contain 01
            MCUCR |= ( 1 << MCUCR_ISC01);

        }
        else if (Copy_u8_SenseLevel == EXTI_RISING_EDGE)
        {
            //Bits contain 11
            MCUCR |= ( 3 << MCUCR_ISC00);

            Local_u8_ErrorFlag = ES_OK;
        }
        else
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        }

        break;
    }

    case EXTI_INT1:
    {
        //Clearing both bits
        MCUCR &= ~( 3 << MCUCR_ISC10);

        if(Copy_u8_SenseLevel == EXTI_LOW_LEVEL)
        {
            //Bits already contain 00
            Local_u8_ErrorFlag = ES_OK;
        }
        else if (Copy_u8_SenseLevel == EXTI_LOGICAL_CHANGE)
        {
            //Bits contain 01
            MCUCR |= ( 1 << MCUCR_ISC10);

            Local_u8_ErrorFlag = ES_OK;
        }
        else if (Copy_u8_SenseLevel == EXTI_FALLING_EDGE)
        {
            //Bits contain 01
            MCUCR |= ( 1 << MCUCR_ISC11);

        }
        else if (Copy_u8_SenseLevel == EXTI_RISING_EDGE)
        {
            //Bits contain 11
            MCUCR |= ( 3 << MCUCR_ISC10);

            Local_u8_ErrorFlag = ES_OK;
        }
        else
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        }

        break;
    }

    case EXTI_INT2:
    {
        if(Copy_u8_SenseLevel == EXTI_FALLING_EDGE)
        {
            //Bit contains 0
            MCUCSR &= ~(1 << MCUCSR_ISC2);

            Local_u8_ErrorFlag = ES_OK;
        }
        else if ( Copy_u8_SenseLevel == EXTI_RISING_EDGE)
        {
            //Bit contains 1
            MCUCSR |= (1 << MCUCSR_ISC2);

            Local_u8_ErrorFlag = ES_OK;
        }

        break;
    }
    
    default:
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        break;
    }
    }


    return Local_u8_ErrorFlag;
}

static ErrorState_t enu_SetFlagValue(u8 Copy_u8_INTNumber, u8 Copy_u8_Value)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_INTNumber)
    {
        case EXTI_INT0:
        {   
            if (Copy_u8_Value == EXTI_HIGH)
            {
                GIFR |= ( 1 << GIFR_INTF0);
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if (Copy_u8_Value == EXTI_LOW)
            {
                GIFR &= ~( 1 << GIFR_INTF0);

                Local_u8_ErrorFlag = ES_OK;
            }
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }
         
            break;
        }

        case EXTI_INT1:
        {
            if (Copy_u8_Value == EXTI_HIGH)
            {
                GIFR |= ( 1 << GIFR_INTF1);

                Local_u8_ErrorFlag = ES_OK;
            }
            else if (Copy_u8_Value == EXTI_LOW)
            {
                GIFR &= ~( 1 << GIFR_INTF1);

                Local_u8_ErrorFlag = ES_OK;
            }
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }
            
            break;
        }
        case EXTI_INT2:
        {
            if (Copy_u8_Value == EXTI_HIGH)
            {
                GIFR |= ( 1 << GIFR_INTF2);
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if (Copy_u8_Value == EXTI_LOW)
            {
                GIFR &= ~( 1 << GIFR_INTF2);

                Local_u8_ErrorFlag = ES_OK;
            }
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }

            break;
        }
    
        default:
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        break;
    }


    return Local_u8_ErrorFlag;     
}