//General files
#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"
//Lower layers' files
#include "../../MCAL/DIO/DIO_Interface.h"

//Module's own files
#include "Hexadecoder_Config.h"
#include "Hexadecoder_Private.h"


//Functions' implementation
extern ErrorState_t Hexadecoder_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    

    #if HEXADECODER_A_GROUP <= DIO_PIN_GROUP_D && HEXADECODER_B_GROUP <= DIO_PIN_GROUP_D && HEXADECODER_C_GROUP <= DIO_PIN_GROUP_D && HEXADECODER_D_GROUP <= DIO_PIN_GROUP_D && HEXADECODER_EN1_GROUP <= DIO_PIN_GROUP_D &&  HEXADECODER_EN2_GROUP <= DIO_PIN_GROUP_D && HEXADECODER_DP_GROUP <= DIO_PIN_GROUP_D  

        #if HEXADECODER_A_PIN <= DIO_PIN_7 && HEXADECODER_B_PIN <= DIO_PIN_7 && HEXADECODER_C_PIN <= DIO_PIN_7 && HEXADECODER_D_PIN <= DIO_PIN_7 && HEXADECODER_EN1_PIN <= DIO_PIN_7 && HEXADECODER_EN2_PIN <= DIO_PIN_7 && HEXADECODER_DP_PIN <= DIO_PIN_7
        
        switch (HEXADECODER_A_GROUP)
        {
            case DIO_PIN_GROUP_A:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_A,HEXADECODER_A_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_B:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B,HEXADECODER_A_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_C:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C,HEXADECODER_A_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_D:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D,HEXADECODER_A_PIN, DIO_PIN_WRITE);
            break;
        }

        switch (HEXADECODER_B_GROUP)
        {
            case DIO_PIN_GROUP_A:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_A,HEXADECODER_B_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_B:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B,HEXADECODER_B_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_C:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C,HEXADECODER_B_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_D:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D,HEXADECODER_B_PIN, DIO_PIN_WRITE);
            break;
        }

        switch (HEXADECODER_C_GROUP)
        {
            case DIO_PIN_GROUP_A:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_A,HEXADECODER_C_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_B:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B,HEXADECODER_C_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_C:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C,HEXADECODER_C_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_D:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D,HEXADECODER_C_PIN, DIO_PIN_WRITE);
            break;
        }
        
        switch (HEXADECODER_D_GROUP)
        {
            case DIO_PIN_GROUP_A:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_A,HEXADECODER_D_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_B:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B,HEXADECODER_D_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_C:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C,HEXADECODER_D_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_D:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D,HEXADECODER_D_PIN, DIO_PIN_WRITE);
            break;
        }

        switch (HEXADECODER_EN1_GROUP)
        {
            case DIO_PIN_GROUP_A:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_A,HEXADECODER_EN1_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_B:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B,HEXADECODER_EN1_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_C:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C,HEXADECODER_EN1_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_D:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D,HEXADECODER_EN1_PIN, DIO_PIN_WRITE);
            break;
        }

        switch (HEXADECODER_EN2_GROUP)
        {
            case DIO_PIN_GROUP_A:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_A,HEXADECODER_EN2_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_B:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B,HEXADECODER_EN2_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_C:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C,HEXADECODER_EN2_PIN, DIO_PIN_WRITE);
            break;

            case DIO_PIN_GROUP_D:
            DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D,HEXADECODER_EN2_PIN, DIO_PIN_WRITE);
            break;
        }
        
        
        
        Local_u8_ErrorFlag =ES_OK;
        #else 
        #error "Out of Range values in Hexadecoder pins"
        #endif
    #else
    #error "Out of range values in Hexadecoder Groups"    
    #endif

    return Local_u8_ErrorFlag;

}

extern ErrorState_t Hexadecoder_enu_DisplayNum(u8 Copy_u8_Num)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u8_Num <= HEXADECODER_MAXIMUM_DISPLAYED_NUM)
    {
        // A:
        DIO_enu_SetPinValue(HEXADECODER_A_GROUP,HEXADECODER_A_PIN, (Copy_u8_Num >> 0) & 1);
        // B:
        DIO_enu_SetPinValue(HEXADECODER_B_GROUP,HEXADECODER_B_PIN, (Copy_u8_Num >> 1) & 1);
        // C:
        DIO_enu_SetPinValue(HEXADECODER_C_GROUP,HEXADECODER_C_PIN, (Copy_u8_Num >> 2) & 1);
        // D:
        DIO_enu_SetPinValue(HEXADECODER_D_GROUP,HEXADECODER_D_PIN, (Copy_u8_Num >> 3) & 1);

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }

    return Local_u8_ErrorFlag;
} 

extern ErrorState_t Hexadecoder_enu_EnableSSG(u8 Copy_u8_SSGNum)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    switch (Copy_u8_SSGNum)
    {
        case SSG_1:
        DIO_enu_SetPinValue(HEXADECODER_EN1_GROUP,HEXADECODER_EN1_PIN,DIO_HIGH);
        Local_u8_ErrorFlag = ES_OK;
        break;

        case SSG_2:
        DIO_enu_SetPinValue(HEXADECODER_EN2_GROUP,HEXADECODER_EN2_PIN,DIO_HIGH);
        Local_u8_ErrorFlag = ES_OK;
        break;

        default:
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        break;
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t Hexadecoder_enu_DisableSSG(u8 Copy_u8_SSGNum)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    switch (Copy_u8_SSGNum)
    {
        case SSG_1:
        DIO_enu_SetPinValue(HEXADECODER_EN1_GROUP,HEXADECODER_EN1_PIN,DIO_LOW);
        Local_u8_ErrorFlag = ES_OK;
        break;

        case SSG_2:
        DIO_enu_SetPinValue(HEXADECODER_EN2_GROUP,HEXADECODER_EN2_PIN,DIO_LOW);
        Local_u8_ErrorFlag = ES_OK;
        break;

        default:
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        break;
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t Hexadecoder_enu_StopDisplay(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    DIO_enu_SetPinValue(HEXADECODER_EN1_GROUP,HEXADECODER_EN1_PIN,DIO_LOW);
    DIO_enu_SetPinValue(HEXADECODER_EN2_GROUP,HEXADECODER_EN2_PIN,DIO_LOW);

    return Local_u8_ErrorFlag;
}
