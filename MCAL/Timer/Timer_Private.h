#ifndef TIMER_PRIVATE_FILE
#define TIMER_PRIVATE_FILE


#include "../../LIB/STD.h"

//Timer/Counter 0 Control Register 
#define TCCR0 *(volatile u8*)0x53
typedef enum
{

 TCCR0_CS00  ,  //Bit0 Clock Selection for Timer/Counter 0   
 TCCR0_CS01  ,  //Bit1 Clock Selection for Timer/Counter 0
 TCCR0_CS02  ,  //Bit2 Clock Selection for Timer/Counter 0
 TCCR0_WGM01 ,  //Bit1 Mode Selection for Timer/Counter 0
 TCCR0_COM00 ,  //Bit0 Compare Match Output Timer/Counter 0 (OCR0 behavior)
 TCCR0_COM01 ,  //Bit1 Compare Match Output Timer/Counter 0 (OCR0 behavior)
 TCCR0_WGM00 ,  //Bit0 Mode Selection for Timer/Counter 0   
 TCCR0_FOC0     //Force Output Compare Timer/Counter 0 (OCR0) 

}TCCR0_t;

//Timer/Counter 0 Regiser 
#define TCNT0 *(volatile u8*)0x52
typedef enum
{

 TCNT0_B0,    //Timer/Counter 0 register Bit 0  
 TCNT0_B1,    //Timer/Counter 0 register Bit 1 
 TCNT0_B2,    //Timer/Counter 0 register Bit 2  
 TCNT0_B3,    //Timer/Counter 0 register Bit 3  
 TCNT0_B4,    //Timer/Counter 0 register Bit 4  
 TCNT0_B5,    //Timer/Counter 0 register Bit 5  
 TCNT0_B6,    //Timer/Counter 0 register Bit 6  
 TCNT0_B7     //Timer/Counter 0 register Bit 7      

}TCNTO_t;

//Timer/Counter 0 Output Compare Register 
#define OCR0  *(volatile u8*)0x5C
typedef enum
{
 OCR0_B0 ,  //Timer/Counter 0 compare register Bit 0
 OCR0_B1 ,  //Timer/Counter 0 compare register Bit 1
 OCR0_B2 ,  //Timer/Counter 0 compare register Bit 2
 OCR0_B3 ,  //Timer/Counter 0 compare register Bit 3
 OCR0_B4 ,  //Timer/Counter 0 compare register Bit 4
 OCR0_B5 ,  //Timer/Counter 0 compare register Bit 5
 OCR0_B6 ,  //Timer/Counter 0 compare register Bit 6
 OCR0_B7    //Timer/Counter 0 compare register Bit 7 

}OCR0_t;

//Timer/Counter 2 Control Registe
#define TCCR2 *(volatile u8*)0x45
typedef enum
{

TCCR2_CS20  , //Bit0 Clock Selection for Timer/Counter 2
TCCR2_CS21  , //Bit1 Clock Selection for Timer/Counter 2
TCCR2_CS22  , //Bit2 Clock Selection for Timer/Counter 2
TCCR2_WGM21 , //Bit1 Mode Selection for Timer/Counter 2
TCCR2_COM20 , //Bit0 Compare Match Output Timer/Counter 2 (OCR2 behavior)
TCCR2_COM21 , //Bit1 Compare Match Output Timer/Counter 2 (OCR2 behavior)
TCCR2_WGM20 , //Bit0 Mode Selection for Timer/Counter 2
TCCR2_FOC2  , //Force Output Compare Timer/Counter 2 (OCR2) 

}TCCR2_t;

//Timer/Counter 2 Regiser
#define TCNT2 *(volatile u8*)0x44
typedef enum
{

 TCNT2_B0 , //Timer/Counter 2 register Bit 0
 TCNT2_B1 , //Timer/Counter 2 register Bit 1
 TCNT2_B2 , //Timer/Counter 2 register Bit 2
 TCNT2_B3 , //Timer/Counter 2 register Bit 3
 TCNT2_B4 , //Timer/Counter 2 register Bit 4
 TCNT2_B5 , //Timer/Counter 2 register Bit 5
 TCNT2_B6 , //Timer/Counter 2 register Bit 6
 TCNT2_B7 , //Timer/Counter 2 register Bit 7

}TCNT2_t;


//Timer/Counter 2 Output Compare Register 
#define OCR2  *(volatile u8*)0x43
typedef enum
{
 
 OCR2_B0 , //Timer/Counter 0 compare register Bit 0 
 OCR2_B1 , //Timer/Counter 0 compare register Bit 1
 OCR2_B2 , //Timer/Counter 0 compare register Bit 2
 OCR2_B3 , //Timer/Counter 0 compare register Bit 3
 OCR2_B4 , //Timer/Counter 0 compare register Bit 4
 OCR2_B5 , //Timer/Counter 0 compare register Bit 5
 OCR2_B6 , //Timer/Counter 0 compare register Bit 6
 OCR2_B7 , //Timer/Counter 0 compare register Bit 7 

}OCR2_t;


//Timer/Counter  Interrurpt Mask Register (TIMSK) FOR TIMER0, 1, AND 2 
#define TIMSK *(volatile u8*)0x59
typedef enum
{

 TIMSK_TOIE0  ,  //Timer/Counter 0 Overflow Interrupt Enable
 TIMSK_OCIE0  ,  //Timer/Counter 0 Output Compare Match Interrupt Enable
 TIMSK_TOIE1  ,  
 TIMSK_OCIE1B ,  
 TIMSK_OCIE1A ,  
 TIMSK_TICIE1  ,  
 TIMSK_TOIE2  ,   //Timer/Counter 2 Overflow Interrupt Enable
 TIMSK_OCIE2  ,   //Timer/Counter 0 Output Compare Match Interrupt Enable

}TIMSK_t;


//Timer/Counter  Interrupt Flag Register (TIFR)
#define TIFR  *(volatile u8*)0x58
typedef enum
{

 TIFR_TOV0  =   0 , //Timer/Counter 0 Overflow Flag 
 TIFR_OCF0  =   1 , //Output Compare Flag 0 FOR Timer/Counter 0
 TIFR_TOV2  =   6 , //Timer/Counter 2  Overflow Flag
 TIFR_OCF2  =   7 , //Output Compare Flag 2 FOR Timer/Counter 2

}TIFR_t;


//Special Function IO Register – SFIOR
#define SFIOR *(volatile u8*)0x50
typedef enum
{
 SFIOR_PSR10 , //Prescaler Reset Timer/Counter 0 and 1  
 SFIOR_PSR2 , //Prescaler Reset Timer/Counter 2
}SFIOR_t;


//Asynchronous Status Register – ASSR
#define ASSR  *(volatile u8*)0x42
typedef enum
{
 ASSR_TCR2UB, //Timer/Counter Control Register2 Update Busy
 ASSR_OCR2UB, //Output Compare Register 2 Update Busy
 ASSR_TCN2UB, //Timer/Counter 2 Update Busy
 ASSR_AS2 ,  //Asynchronous Timer/Counter2

}ASSR_t;





//Clock Selection Options
#define TIMER_V_GND             0
#define TIMER_PS_1              1
#define TIMER_PS_8              2   
#define TIMER_PS_32             3  //For Timer/Counter 2 only
#define TIMER_PS_64             4
#define TIMER_PS_128            5  //For Timer/Counter 2 only
#define TIMER_PS_256            6
#define TIMER_PS_1024           7
#define TIMER_FALLING_EGDE      8   //For Timer/Counter 0 and 1 only
#define TIMER_RISING_EGDE       9   //For Timer/Counter 0 and 1 only

//Asynchronas Options for Timer2
//to be done


//Timer Modes TIMER0 and TIMER2
#define TIMER_NORMAL           0
#define TIMER_CTC              1
#define TIMER_PHASE_PWM        2
#define TIMER_FAST_PWM         3


//Timer Modes for Timer 1
//to be done


//Interrupt Modes for Timer 0 and 2
#define TIMER_INT_MODE                         1
#define TIMER_POLLING_MODE                     0



//OCx pin behavior for non-PWM modes
#define TIMER_OCX_DISCONNECTED           0
#define TIMER_TOGGLE_OCX                 1
#define TIMER_CLEAR_OCX                  2
#define TIMER_SET_OCX                    3

//OCx pin behavior PWM modes 
#define TIMER_FAST_PWM_NON_INVERTING     4
#define TIMER_FAST_PWM_INVERTING         5
#define TIMER_PHASE_PWM_NON_INVERTING    6
#define TIMER_PHASE_PWM_INVERTING        7


//Timer numbers
#define TIMER_0  0
#define TIMER_1  1
#define TIMER_2  2



//ISR Count
#define TIMER_ISR_COUNT   8

//ISR Pointers Location
#define TIMER_2_CTC_ISR                 0
#define TIMER_2_OVERFLOW_ISR            1
#define TIMER_1_CAPTURE_EVENT_ISR       2
#define TIMER_1_CTC_A_ISR               3
#define TIMER_1_CTC_B_ISR               4
#define TIMER_1_OVERFLOW_ISR            5
#define TIMER_0_CTC_ISR                 6
#define TIMER_0_OVERFLOW_ISR            7


//Duty cycle ranges
#define TIMER_DUTYCYCLE_100    1
#define TIMER_DUTYCYCLE_0      0

//TCNtx Values
#define TIMER_TCNT0_TOP   256
#define TIMER_TCNT1_TOP   65536
#define TIMER_TCNT2_TOP   256

//Available PWM frequencies for phase PWM
#define TIMER_PHASE_PWM_31373_HZ   TIMER_PS_1
#define TIMER_PHASE_PWM_3922_HZ    TIMER_PS_8
#define TIMER_PHASE_PWM_980_HZ     TIMER_PS_32  //For Timer/Counter 2 only
#define TIMER_PHASE_PWM_490_HZ     TIMER_PS_64  
#define TIMER_PHASE_PWM_245_HZ     TIMER_PS_128  //For Timer/Counter 2 only
#define TIMER_PHASE_PWM_123_HZ     TIMER_PS_256  
#define TIMER_PHASE_PWM_31_HZ      TIMER_PS_128  

//Available PWM frequencies for phase PWM
#define TIMER_FAST_PWM_62500_HZ   TIMER_PS_1
#define TIMER_FAST_PWM_7813_HZ    TIMER_PS_8
#define TIMER_FAST_PWM_1953_HZ    TIMER_PS_32  //For Timer/Counter 2 only
#define TIMER_FAST_PWM_977_HZ     TIMER_PS_64  
#define TIMER_FAST_PWM_488_HZ     TIMER_PS_128  //For Timer/Counter 2 only
#define TIMER_FAST_PWM_244_HZ     TIMER_PS_256  
#define TIMER_FAST_PWM_61_HZ      TIMER_PS_128  


//Local functions' prototypes
static ErrorState_t enu_SetTimerMode (u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode);
static ErrorState_t enu_SetClockSelection(u8 Copy_u8_TimerNumber, u8 Copy_u8_ClockSelection);
static ErrorState_t enu_SetInterruptMode(u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode, u8 Copy_u8_InterruptMode);
static ErrorState_t enu_SetOCxBehavior(u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode, u8 Copy_u8_OCxPinBehavior);


#endif