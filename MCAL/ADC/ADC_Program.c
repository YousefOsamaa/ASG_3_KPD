#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "ADC_Private.h"
#include "ADC_Config.h"

static void (*pfun_ISRPointer)(void*) = NULL;
static void* pvid_ISRParameters = NULL;

//APIs implementation

extern ErrorState_t ADC_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    //Bits contain 00
    ADMUX &= ~(3 << ADMUX_REFS0 );
    
    //Handling voltage reference source:
    #if ADC_V_REFERENCE_SOURCE ==  ADC_AREF
        //bITS ALREADY CONTAIN 00  
    
    #elif ADC_V_REFERENCE_SOURCE == ADC_AVCC
       
        //Bits contain 01
        ADMUX |= (1 < ADMUX_REFS0);
    
    #elif ADC_V_REFERENCE_SOURCE == ADC_INTERNAL
       
        //Bits contain 11
        ADMUX |= (3 << ADMUX_REFS0);
    
    #else
        #error "ADC_V_REFERENCE_SOURCE is invalid"
    
    #endif 


    //Handling Data adjustment direction
    #if  ADC_DATA_ADJUSTMENT == ADC_LEFT_ADJUSTED
        //Setting ADLAR bit
        ADMUX |= ( 1 << ADMUX_ADLAR);
    
    #elif ADC_DATA_ADJUSTMENT == ADC_RIGHT_ADJUSTED
        //Clearing ADLAR bit
        ADMUX &= ~( 1 << ADMUX_ADLAR);
    
    #else
        #error "ADC_DATA_ADJUSTMENT is invalid"
    
    #endif


    //Handling Trigger Mode 
    #if ADC_TRIGGER_SOURCE == ADC_SINGLE_CONVERSION
        //Clearing ADATE bit
        ADCSRA &= ~( 1 << ADCSRA_ADATE);

    #elif  ADC_TRIGGER_SOURCE >= ADC_FREE_RUNNING &&  ADC_TRIGGER_SOURCE <= ADC_TIMER1_CAPTURE_EVENT

        //Clearing ADTS bits
        SFIOR &= (0X1F);

        //Choosing AT source
        SFIOR |= (ADC_TRIGGER_SOURCE << SFIOR_ADTS0); 
        
        //Setting ADATE bit
        ADCSRA |=  ( 1 << ADCSRA_ADATE);
    
    #else
        #error "ADC_TRIGGER_SOURCE is invalid "
    
    #endif


    //Handling Interrupt Event Status (PIE)
    #if ADC_INT_EVENT_STATUS == ADC_INT_ENABLE
        ADCSRA |= ( 1 << ADCSRA_ADIE); //Bit contains 1 
    
    #elif ADC_INT_EVENT_STATUS == ADC_INT_DISABLE
        ADCSRA &= ~( 1 << ADCSRA_ADIE); //Bit contains 0 
    
    #else
        #error "ADC_INT_EVENT_STATUS is invalid "
    
    #endif


    //Handling ADC clock speed
    //Clearing PS bits
    ADCSRA &= (0xF8);
    #if ADC_PS_FACTOR >= ADC_PS_2 && ADC_PS_FACTOR <= ADC_PS_128 
        
        ADCSRA |= (ADC_PS_FACTOR << ADCSRA_ADPS0);

    #else
        #error "ADC_PS_FACTOR is invalid"

    #endif


    //Handling input channels
    ADMUX &= (0xE0); //Clearing bits
    #if ADC_INPUT_CHANNEL >= ADC_ADC0 && ADC_INPUT_CHANNEL <= ADC_V_GND
        //Channel Selection
        ADMUX |= (ADC_INPUT_CHANNEL << ADMUX_MUX0);

    #else
        #error "ADC_INPUT_CHANNEL is invalid"

    #endif


    // /Powering ADC
    ADCSRA |= (1 << ADCSRA_ADEN );

    Local_u8_ErrorFlag = ES_OK;
    return Local_u8_ErrorFlag; 
}

extern ErrorState_t ADC_enu_ReadPolling(u8 Copy_u8_Channel, u16* Copy_pu16_Result)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if ((Copy_u8_Channel >= ADC_ADC0) && (Copy_u8_Channel <= ADC_V_GND))
    {
        //Clearing PIF, Assuming that the ADC is in Polling mode.
        ADCSRA |= (1 << ADCSRA_ADIF);
        
        //Clearing MUX it
        ADMUX &= (0xE0);

        //Choosing channel
        ADMUX |= (Copy_u8_Channel << ADMUX_MUX0);
       
        //Setting ADSC to start a conversion
        ADCSRA |= (1 << ADCSRA_ADSC);

        //Waiting for ADC to raise ADIF
        while (((ADCSRA >> ADCSRA_ADIF) & 1) == False);

        
        #if ADC_DATA_ADJUSTMENT == ADC_LEFT_ADJUSTED 

            //ADCL must be read first
            *Copy_pu16_Result = (ADCL >> 6);
            //ADCH is then read
            *Copy_pu16_Result |= ((u16)ADCH << 2);

        #elif ADC_DATA_ADJUSTMENT == ADC_RIGHT_ADJUSTED
            //ADCL must be read first
            *Copy_pu16_Result = ADCL;
            //ADCH is then read
            *Copy_pu16_Result |= (u16)ADCH << 8;

        #endif
   
        //Clearing PIF
        ADCSRA |= (1 << ADCSRA_ADIF);
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }


    Local_u8_ErrorFlag = ES_OK;
    

    


    return Local_u8_ErrorFlag;
}

extern ErrorState_t ADC_enu_StartConversion(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    ADCSRA |= (1 <<ADCSRA_ADSC);

    Local_u8_ErrorFlag = ES_OK;

    return Local_u8_ErrorFlag;
}

extern ErrorState_t ADC_enu_SetTriggerringSource(u8 Copy_u8_TriggeringSource)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    if(Copy_u8_TriggeringSource == ADC_SINGLE_CONVERSION)
    {
        //Clearing ADATE bit
        ADCSRA &= ~(1 << ADCSRA_ADATE);

        Local_u8_ErrorFlag = ES_OK;
    }
    else if((Copy_u8_TriggeringSource >= ADC_FREE_RUNNING) && (Copy_u8_TriggeringSource <= ADC_TIMER1_CAPTURE_EVENT))
    {
        //Clearing ADTS bits
        SFIOR &= ~ (1 << SFIOR_ADTS0);

        //Choosing AT source
        SFIOR |= (Copy_u8_TriggeringSource << SFIOR_ADTS0);

        //Setting ADATE bit
        ADCSRA |= (1 << ADCSRA_ADATE);

        Local_u8_ErrorFlag =ES_OK;

    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }
        
        

    return Local_u8_ErrorFlag;
}

extern ErrorState_t ADC_enu_ChangePrescalerFactor(u8 Copy_u8_DivisonFactor)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if((Copy_u8_DivisonFactor >= ADC_PS_2) && (Copy_u8_DivisonFactor <= ADC_PS_128))
    {
        //Clearins PS bits
        ADCSRA &= ~ (7 << ADCSRA_ADPS0);

        //Choosing divisuon factor
        ADCSRA |=  (Copy_u8_DivisonFactor << ADCSRA_ADPS0);

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }
    return Local_u8_ErrorFlag;
}

extern ErrorState_t ADC_enu_ReadADCH(u16* Copy_pu16_Result)
{
    u8 Local_u8_ErrorFlag = ES_NOK;


    if(Copy_pu16_Result)
    {

        #if ADC_DATA_ADJUSTMENT == ADC_RIGHT_ADJUSTED
            
            #warning "This function returns a huge error due to ADC_DATA_ADJUSTMENT current configuration"
            
            *Copy_pu16_Result = (u16)ADCH << 8;
        
        #else ADC_DATA_ADJUSTMENT == ADC_LEFT_ADJUSTED

                *Copy_pu16_Result = (u16)ADCH << 2;

        #endif

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }


    return Local_u8_ErrorFlag; 
}

extern ErrorState_t ADC_enu_ReadADCL(u16* Copy_pu16_Result)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_pu16_Result)
    {

        #if ADC_DATA_ADJUSTMENT == ADC_RIGHT_ADJUSTED
        
            #warning "This function returns a huge error due to ADC_DATA_ADJUSTMENT current configuration"
            
            *Copy_pu16_Result = ADCL;
        #elif ADC_DATA_ADJUSTMENT == ADC_LEFT_ADJUSTED

            

        #endif

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }


    return Local_u8_ErrorFlag; 
}

extern ErrorState_t ADC_enu_ReadData(u16* Copy_pu16_Result)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_pu16_Result)
    {
        #if ADC_DATA_ADJUSTMENT == ADC_LEFT_ADJUSTED 

            //ADCL must be read first
            *Copy_pu16_Result = (ADCL >> 6);
            //ADCH is then read
            *Copy_pu16_Result |= ((u16)ADCH << 2);

        #elif ADC_DATA_ADJUSTMENT == ADC_RIGHT_ADJUSTED
            //ADCL must be read first
            *Copy_pu16_Result = ADCL;
            //ADCH is then read
            *Copy_pu16_Result |= (u16)ADCH << 8;

        #endif

        

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }
    return Local_u8_ErrorFlag;
}

extern ErrorState_t ADC_enu_EnableINT(void)
{
    
    u8 Local_u8_ErrorFlag = ES_NOK;

    ADCSRA |= (1 << ADCSRA_ADIE);

    Local_u8_ErrorFlag = ES_OK;
    
    return Local_u8_ErrorFlag;
}

extern ErrorState_t ADC_enu_DisableINT(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    ADCSRA &= ~(1 << ADCSRA_ADIE);

    Local_u8_ErrorFlag = ES_OK;

    return Local_u8_ErrorFlag;
}

extern ErrorState_t ADC_enu_EnableADC(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    ADCSRA |= (1 << ADCSRA_ADEN);

    Local_u8_ErrorFlag = ES_OK;
    
    return Local_u8_ErrorFlag;

}

extern ErrorState_t ADC_enu_DisableADC(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    ADCSRA &= ~(1 << ADCSRA_ADEN);

    Local_u8_ErrorFlag = ES_OK;

    return Local_u8_ErrorFlag;

}

extern ErrorState_t ADC_enu_SetCallBack(void (*Copy_pfun_AppFunction)(void), void* Copy_u8_Parameters)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_pfun_AppFunction)
    {
        pfun_ISRPointer = Copy_pfun_AppFunction;

        pvid_ISRParameters = Copy_u8_Parameters;
        
        Local_u8_ErrorFlag = ES_OK;
    }

    return Local_u8_ErrorFlag;
    
}

//ISR functions

void __vector_16 (void)__attribute__((signal));
void __vector_16 (void)
{
    if (pfun_ISRPointer != NULL)
    {
        pfun_ISRPointer (pvid_ISRParameters);
    }
}