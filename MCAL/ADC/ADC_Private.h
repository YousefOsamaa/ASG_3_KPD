#ifndef ADC_PRIVATE_FILE
#define ADC_PRIVATE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"



//Registers addresses

#define ADMUX  *(volatile u8*)0x27
#define ADCSRA *(volatile u8*)0x26
#define ADCH   *(volatile u8*)0x25
#define ADCL   *(volatile u8*)0x24
#define SFIOR  *(volatile u8*)0x50

//Bits Numbers

#define ADMUX_REFS1     7
#define ADMUX_REFS0     6
#define ADMUX_ADLAR     5
#define ADMUX_MUX4      4
#define ADMUX_MUX3      3
#define ADMUX_MUX2      2
#define ADMUX_MUX1      1
#define ADMUX_MUX0      0

#define ADCSRA_ADEN     7
#define ADCSRA_ADSC     6
#define ADCSRA_ADATE    5
#define ADCSRA_ADIF     4
#define ADCSRA_ADIE     3
#define ADCSRA_ADPS2    2
#define ADCSRA_ADPS1    1
#define ADCSRA_ADPS0    0

#define ADCH_B7       7 
#define ADCH_B6       6 
#define ADCH_B5       5 
#define ADCH_B4       4 
#define ADCH_B3       3 
#define ADCH_B2       2 
#define ADCH_B1       1 
#define ADCH_B0       0 

#define ADCL_B7       7 
#define ADCL_B6       6 
#define ADCL_B5       5 
#define ADCL_B4       4 
#define ADCL_B3       3 
#define ADCL_B2       2 
#define ADCL_B1       1 
#define ADCL_B0       0 

#define SFIOR_ADTS2   7
#define SFIOR_ADTS1   6
#define SFIOR_ADTS0   5

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


//Voltage Levels

#define ADC_LOW    0
#define ADC_HIGH   1

//Local Functions protoypes


#endif