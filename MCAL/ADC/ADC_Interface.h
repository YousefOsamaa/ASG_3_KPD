#ifndef ADC_INTERFACE_FILE
#define ADC_INTERFACE_FILE


#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//ADC Voltafe References 
#define ADC_AREF      0
#define ADC_AVCC      1
#define ADC_INTERNAL  2

//Data adjustment direction
#define ADC_RIGHT_ADJUSTED  0
#define ADC_LEFT_ADJUSTED   1

//Input Channels

//1] Single Ended
#define ADC_ADC0              0          
#define ADC_ADC1              1        
#define ADC_ADC2              2
#define ADC_ADC3              3
#define ADC_ADC4              4
#define ADC_ADC5              5
#define ADC_ADC6              6
#define ADC_ADC7              7

//2] Differential
#define ADC_ADC0_ADC0_10x     8
#define ADC_ADC1_ADC0_10x     9
#define ADC_ADC0_ADC0_200x    10
#define ADC_ADC1_ADC0_200x    11

#define ADC_ADC2_ADC2_10x     12
#define ADC_ADC3_ADC2_10x     13
#define ADC_ADC2_ADC2_200x    14
#define ADC_ADC3_ADC2_200x    15


#define ADC_ADC0_ADC1_1x      16
#define ADC_ADC1_ADC1_1x      17
#define ADC_ADC2_ADC1_1x      18
#define ADC_ADC3_ADC1_1x      19
#define ADC_ADC4_ADC1_1x      10      
#define ADC_ADC5_ADC1_1x      21
#define ADC_ADC6_ADC1_1x      22
#define ADC_ADC7_ADC1_1x      23
#define ADC_ADC0_ADC2_1x      24
#define ADC_ADC1_ADC2_1x      25
#define ADC_ADC2_ADC2_1x      26
#define ADC_ADC3_ADC2_1x      27
#define ADC_ADC4_ADC2_1x      28
#define ADC_ADC5_ADC2_1x      29

//3] Testing
#define ADC_V_BG              30
#define ADC_V_GND             31



//Trigger Sources
#define ADC_FREE_RUNNING               0
#define ADC_ANALOG_COMPARATOR          1
#define ADC_EXTERNL_INT0               2
#define ADC_TIMER0_COMPARE_MATCH       3
#define ADC_TIMER0_OVERFLOW            4
#define ADC_TIMER_COMPARE_MATCH_B      5
#define ADC_TIMER1_OVERFLOW            6
#define ADC_TIMER1_CAPTURE_EVENT       7
#define ADC_SINGLE_CONVERSION          8 



//Interrupt Event Status
#define ADC_INT_ENABLE      1   
#define ADC_INT_DISABLE     0



//PS division factor
#define ADC_PS_2   1
#define ADC_PS_4   2
#define ADC_PS_8   3
#define ADC_PS_16  4
#define ADC_PS_32  5
#define ADC_PS_64  6
#define ADC_PS_128 7


//APIs prototypes

extern ErrorState_t ADC_enu_Initialization(void);

extern ErrorState_t ADC_enu_ReadPolling(u8 Copy_u8_Channel, u16* Copy_pu16_Result);

extern ErrorState_t ADC_enu_StartConversion(void);

extern ErrorState_t ADC_enu_SetTriggerringSource(u8 Copy_u8_TriggeringSource);

extern ErrorState_t ADC_enu_ChangePrescalerFactor(u8 Copy_u8_DivisonFactor);

extern ErrorState_t ADC_enu_ReadADCH(u16* Copy_pu16_Result);

extern ErrorState_t ADC_enu_ReadADCL(u16* Copy_pu16_Result);

extern ErrorState_t ADC_enu_ReadData(u16* Copy_pu16_Result);

extern ErrorState_t ADC_enu_EnableINT(void);

extern ErrorState_t ADC_enu_DisableINT(void);

extern ErrorState_t ADC_enu_EnableADC(void);

extern ErrorState_t ADC_enu_DisableADC(void);

extern ErrorState_t ADC_enu_SetCallBack(void (*Copy_pfun_AppFunction)(void), void* Copy_u8_Parameters);


#endif