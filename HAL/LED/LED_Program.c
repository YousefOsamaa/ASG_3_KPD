#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Private.h"
#include "LED_Config.h"

extern u8 LED_u8_LEDsCount;

extern LED_t LED_astr_LEDsList [];

//APIs' implementations
extern ErrorState_t LED_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    u8 Local_u8_Counter = 0;
    
    for (Local_u8_Counter = 0; Local_u8_Counter < LED_u8_LEDsCount; Local_u8_Counter++ )
    {
        DIO_enu_SetPinDiretion(LED_astr_LEDsList[Local_u8_Counter].LED_Group,LED_astr_LEDsList[Local_u8_Counter].LED_Pin,DIO_PIN_WRITE);
        DIO_enu_SetPinValue(LED_astr_LEDsList[Local_u8_Counter].LED_Group,LED_astr_LEDsList[Local_u8_Counter].LED_Pin,DIO_LOW);
    }

    Local_u8_ErrorFlag = ES_OK;

    return Local_u8_ErrorFlag;
}

extern ErrorState_t LED_enu_TurnOnLED(u8 Copy_u8_LEDNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u8_LEDNumber < LED_u8_LEDsCount)
    {
        Local_u8_ErrorFlag = DIO_enu_SetPinValue(LED_astr_LEDsList[Copy_u8_LEDNumber].LED_Group,LED_astr_LEDsList[Copy_u8_LEDNumber].LED_Pin,DIO_HIGH);

    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t LED_enu_TurnOffLED(u8 Copy_u8_LEDNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u8_LEDNumber <= LED_u8_LEDsCount)
    {
        Local_u8_ErrorFlag = DIO_enu_SetPinValue(LED_astr_LEDsList[Copy_u8_LEDNumber].LED_Group,LED_astr_LEDsList[Copy_u8_LEDNumber].LED_Pin,DIO_LOW);

    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }


    return Local_u8_ErrorFlag;
}

extern ErrorState_t LED_enu_TurnOnAllLEDs (void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;

    for(Local_u8_Counter = 0; Local_u8_Counter < LED_u8_LEDsCount; Local_u8_Counter++)
    {
        DIO_enu_SetPinValue(LED_astr_LEDsList[Local_u8_Counter].LED_Group,LED_astr_LEDsList[Local_u8_Counter].LED_Pin,DIO_HIGH);
    }
    //Error Flags handling to be done later
    Local_u8_ErrorFlag = ES_OK;

    return Local_u8_ErrorFlag;
}

extern ErrorState_t LED_enu_TurnOffAllLEDs (void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;

    for(Local_u8_Counter = 0; Local_u8_Counter < LED_u8_LEDsCount; Local_u8_Counter++)
    {
        DIO_enu_SetPinValue(LED_astr_LEDsList[Local_u8_Counter].LED_Group,LED_astr_LEDsList[Local_u8_Counter].LED_Pin,DIO_LOW);
    }
    
    //Error Flags handling to be done later
    Local_u8_ErrorFlag = ES_OK;
    
    return Local_u8_ErrorFlag;
}
