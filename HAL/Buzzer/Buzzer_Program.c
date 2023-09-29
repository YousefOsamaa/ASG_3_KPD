#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Interface.h"


#include "Buzzer_Private.h"
#include "Buzzer_Config.h"


extern u8 Buzzer_u8_BuzzerCount ;
extern Buzzer_t Buzzer_astr_BuzzerList[];

//APIs implementation

extern ErrorState_t Buzzer_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;
    for(Local_u8_Counter = 0; Local_u8_Counter < Buzzer_u8_BuzzerCount; Local_u8_Counter++)
    {
        DIO_enu_SetPinDiretion(Buzzer_astr_BuzzerList[Local_u8_Counter].Buzzer_Group, Buzzer_astr_BuzzerList[Local_u8_Counter].Buzzer_Pin, DIO_PIN_WRITE);
        DIO_enu_SetPinValue(Buzzer_astr_BuzzerList[Local_u8_Counter].Buzzer_Group, Buzzer_astr_BuzzerList[Local_u8_Counter].Buzzer_Pin, DIO_LOW);
    }

    //TO be handled later
    Local_u8_ErrorFlag = ES_OK;




    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Buzzer_enu_TuronOnBuzzer(u8 Copy_u8_BuzzerNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u8_BuzzerNumber < Buzzer_u8_BuzzerCount)
    {
        Local_u8_ErrorFlag = DIO_enu_SetPinValue(Buzzer_astr_BuzzerList[Copy_u8_BuzzerNumber].Buzzer_Group,Buzzer_astr_BuzzerList[Copy_u8_BuzzerNumber].Buzzer_Pin,DIO_HIGH);
        
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }






    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Buzzer_enu_TuronOffBuzzer(u8 Copy_u8_BuzzerNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u8_BuzzerNumber < Buzzer_u8_BuzzerCount)
    {
        Local_u8_ErrorFlag = DIO_enu_SetPinValue(Buzzer_astr_BuzzerList[Copy_u8_BuzzerNumber].Buzzer_Group,Buzzer_astr_BuzzerList[Copy_u8_BuzzerNumber].Buzzer_Pin,DIO_LOW);
        
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }



    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Buzzer_enu_TurnOnAllBuzzers(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;
    for(Local_u8_Counter = 0; Local_u8_Counter < Buzzer_u8_BuzzerCount; Local_u8_Counter++)
    {

     DIO_enu_SetPinValue(Buzzer_astr_BuzzerList[Local_u8_Counter].Buzzer_Group,Buzzer_astr_BuzzerList[Local_u8_Counter].Buzzer_Pin,DIO_HIGH);
        
    }

    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;



    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Buzzer_enu_TurnOffAllBuzzers(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;
    for(Local_u8_Counter = 0; Local_u8_Counter < Buzzer_u8_BuzzerCount; Local_u8_Counter++)
    {

     DIO_enu_SetPinValue(Buzzer_astr_BuzzerList[Local_u8_Counter].Buzzer_Group,Buzzer_astr_BuzzerList[Local_u8_Counter].Buzzer_Pin,DIO_LOW);
        
    }


    return Local_u8_ErrorFlag; 
}
