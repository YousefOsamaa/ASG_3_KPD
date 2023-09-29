#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Interface.h"


#include "Relay_Private.h"
#include "Relay_Config.h"

extern u8 Relay_u8_RelayCount ;
extern Relay_t Relay_astr_RelayList[];

//APIs implementation

extern ErrorState_t Relay_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;
    for(Local_u8_Counter = 0; Local_u8_Counter < Relay_u8_RelayCount; Local_u8_Counter++)
    {
        DIO_enu_SetPinDiretion(Relay_astr_RelayList[Local_u8_Counter].Relay_Group,Relay_astr_RelayList[Local_u8_Counter].Relay_Pin,DIO_PIN_WRITE);
        DIO_enu_SetPinValue(Relay_astr_RelayList[Local_u8_Counter].Relay_Group,Relay_astr_RelayList[Local_u8_Counter].Relay_Pin,DIO_LOW);
    }

    //TO be handled later
    Local_u8_ErrorFlag = ES_OK;




    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Relay_enu_TuronOnRelay(u8 Copy_u8_RelayNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u8_RelayNumber < Relay_u8_RelayCount)
    {
        Local_u8_ErrorFlag = DIO_enu_SetPinValue(Relay_astr_RelayList[Copy_u8_RelayNumber].Relay_Group,Relay_astr_RelayList[Copy_u8_RelayNumber].Relay_Pin,DIO_HIGH);
        
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }






    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Relay_enu_TuronOffRelay(u8 Copy_u8_RelayNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u8_RelayNumber < Relay_u8_RelayCount)
    {
        Local_u8_ErrorFlag = DIO_enu_SetPinValue(Relay_astr_RelayList[Copy_u8_RelayNumber].Relay_Group,Relay_astr_RelayList[Copy_u8_RelayNumber].Relay_Pin,DIO_LOW);
        
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }



    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Relay_enu_TurnOnAllRelays(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;
    for(Local_u8_Counter = 0; Local_u8_Counter < Relay_u8_RelayCount; Local_u8_Counter++)
    {

     DIO_enu_SetPinValue(Relay_astr_RelayList[Local_u8_Counter].Relay_Group,Relay_astr_RelayList[Local_u8_Counter].Relay_Pin,DIO_HIGH);
        
    }

    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;



    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Relay_enu_TurnOffAllRelays(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_Counter = 0;
    for(Local_u8_Counter = 0; Local_u8_Counter < Relay_u8_RelayCount; Local_u8_Counter++)
    {

     DIO_enu_SetPinValue(Relay_astr_RelayList[Local_u8_Counter].Relay_Group,Relay_astr_RelayList[Local_u8_Counter].Relay_Pin,DIO_LOW);
        
    }


    return Local_u8_ErrorFlag; 
}
