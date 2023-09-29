#ifndef TIMER_INTERFACE_FILE
#define TIMER_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"


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
#define TIMER_OCX_DISCONNECTED          0
#define TIMER_TOGGLE_OCX                1
#define TIMER_CLEAR_OCX                 2
#define TIMER_SET_OCX                   3


//OCx pin behavior PWM modes 
#define TIMER_FAST_PWM_NON_INVERTING     4
#define TIMER_FAST_PWM_INVERTING         5 
#define TIMER_PHASE_PWM_NON_INVERTING    6
#define TIMER_PHASE_PWM_INVERTING        7



//Timer numbers
#define TIMER_0  0
#define TIMER_1  1
#define TIMER_2  2

//Available PWM frequencies for phase PWM
#define TIMER_PHASE_PWM_31373_HZ   TIMER_PS_1
#define TIMER_PHASE_PWM_3922_HZ    TIMER_PS_8
#define TIMER_PHASE_PWM_980_HZ     TIMER_PS_32  //For Timer/Counter 2 only
#define TIMER_PHASE_PWM_490_HZ     TIMER_PS_64  
#define TIMER_PHASE_PWM_245_HZ     TIMER_PS_128  //For Timer/Counter 2 only
#define TIMER_PHASE_PWM_123_HZ     TIMER_PS_256  
#define TIMER_PHASE_PWM_31_HZ      TIMER_PS_128  

//Available PWM frequencies for phase PWM
#define TIMER_FAST_PWM_62500_HZ    TIMER_PS_1
#define TIMER_FAST_PWM_7813_HZ     TIMER_PS_8
#define TIMER_FAST_PWM_1953_HZ     TIMER_PS_32  //For Timer/Counter 2 only
#define TIMER_FAST_PWM_977_HZ      TIMER_PS_64  
#define TIMER_FAST_PWM_488_HZ      TIMER_PS_128  //For Timer/Counter 2 only
#define TIMER_FAST_PWM_244_HZ      TIMER_PS_256  
#define TIMER_FAST_PWM_61_HZ       TIMER_PS_1024  



//APIs prototypes
extern ErrorState_t Timer_enu_Initialization(void);

extern ErrorState_t Timer_enu_SetOCRxValue(u8 Copy_u8_TimerNumber, u16 Copy_u16_Value);

extern ErrorState_t Timer_enu_SetTCNTxValue(u8 Copy_u8_TimerNumber, u16 Copy_u16_Value);

extern ErrorState_t Timer_enu_ReadTCNTxValue(u8 Copy_u8_TimerNumber, u16* Copy_u16_Value);

extern ErrorState_t Timer_enu_SetClock (u8 Copy_u8_TimerNumber, u8 Copy_u8_ClockSelection);

extern ErrorState_t Timer_enu_SetDutyCycleForPWM(u8 Copy_u8_TimerNumber,u8 Copy_u8_TimerMode, u8 Copy_u8_PulseType, f32 Copy_f32_DutyCyclePercentage);

extern ErrorState_t Timer_enu_SetCallBack (u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode, void (*Copy_pfun_AppFunction)(void*), void* Copy_pvid_Parameters);






#endif