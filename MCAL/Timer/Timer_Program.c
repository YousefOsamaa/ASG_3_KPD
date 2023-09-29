#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "Timer_Private.h"
#include "Timer_Config.h"

extern u8 Timer_u8_TimerCount;
extern TIMER_t Timer_astr_TimerList[];

static void (* apfun_ISRpointers[TIMER_ISR_COUNT])(void*)= { NULL};
static void* apvid_ISRParameters[TIMER_ISR_COUNT] = {NULL};

//APIs implementaion
extern ErrorState_t Timer_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_OK;
    u8 Local_u8_Counter = 0;

    u8 Local_au8_ErrorStates [4] ={0};

    for ( Local_u8_Counter = 0; Local_u8_Counter < Timer_u8_TimerCount; Local_u8_Counter++)
    {
        
      Local_au8_ErrorStates[0] = enu_SetTimerMode(Timer_astr_TimerList[Local_u8_Counter].TimerNumber, Timer_astr_TimerList[Local_u8_Counter].TimerMode);
      Local_au8_ErrorStates[1] = enu_SetClockSelection(Timer_astr_TimerList[Local_u8_Counter].TimerNumber, Timer_astr_TimerList[Local_u8_Counter].ClockSelection);
      Local_au8_ErrorStates[2] = enu_SetInterruptMode(Timer_astr_TimerList[Local_u8_Counter].TimerNumber, Timer_astr_TimerList[Local_u8_Counter].TimerMode, Timer_astr_TimerList[Local_u8_Counter].InterruptMode);
      Local_au8_ErrorStates[3] = enu_SetOCxBehavior(Timer_astr_TimerList[Local_u8_Counter].TimerNumber, Timer_astr_TimerList[Local_u8_Counter].TimerMode ,Timer_astr_TimerList[Local_u8_Counter].OCxPinBehavior);
    
      if((Local_au8_ErrorStates[0] == ES_NOK) || (Local_au8_ErrorStates[1] == ES_NOK) || (Local_au8_ErrorStates[2] == ES_NOK) || (Local_au8_ErrorStates[3] == ES_NOK))
      {
        Local_u8_ErrorFlag = ES_NOK;
      }
    }
    


    return Local_u8_ErrorFlag;
}

extern ErrorState_t Timer_enu_SetOCRxValue(u8 Copy_u8_TimerNumber, u16 Copy_u16_Value)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_TimerNumber)
    {
        case TIMER_0:
        {
            OCR0 = Copy_u16_Value;

            Local_u8_ErrorFlag = ES_OK;
            break;
        }

        case TIMER_1:
        {

            break;
        }

        case TIMER_2:
        {
            OCR2 = Copy_u16_Value;

            Local_u8_ErrorFlag = ES_OK;

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

extern ErrorState_t Timer_enu_SetTCNTxValue(u8 Copy_u8_TimerNumber, u16 Copy_u16_Value)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_TimerNumber)
    {
        case TIMER_0:
        {
            TCNT0 = (u8)Copy_u16_Value;

            Local_u8_ErrorFlag = ES_OK;
            break;
        }

        case TIMER_1:
        {

            break;
        }

        case TIMER_2:
        {
            TCNT2 = (u8)Copy_u16_Value;

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

extern ErrorState_t Timer_enu_ReadTCNTxValue(u8 Copy_u8_TimerNumber, u16* Copy_u16_Value)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u16_Value)
    {
        switch (Copy_u8_TimerNumber)
        {
            case TIMER_0:
            {
                *Copy_u16_Value = TCNT0;

                Local_u8_ErrorFlag = ES_OK;
                break;
            }

            case TIMER_1:
            {

                break;
            }

            case TIMER_2:
            {
                *Copy_u16_Value = TCNT2;

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

extern ErrorState_t Timer_enu_SetClock (u8 Copy_u8_TimerNumber, u8 Copy_u8_ClockSelection)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    Local_u8_ErrorFlag = enu_SetClockSelection(Copy_u8_TimerNumber, Copy_u8_ClockSelection);

    return Local_u8_ErrorFlag;
}

ErrorState_t Timer_enu_SetDutyCycleForPWM(u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode, u8 Copy_u8_PulseType, f32 Copy_f32_DutyCyclePercentage)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if ((Copy_f32_DutyCyclePercentage >= TIMER_DUTYCYCLE_0) && (Copy_f32_DutyCyclePercentage <= TIMER_DUTYCYCLE_100))
    {
        switch (Copy_u8_TimerNumber)
        {
            case TIMER_0:
            {
                if (Copy_u8_TimerMode == TIMER_PHASE_PWM)
                {
                    if(Copy_u8_PulseType == TIMER_PHASE_PWM_NON_INVERTING)
                    {
                        //Using Duty Cycle Rule for non-inverting fast PWM mode
                        OCR0 = Copy_f32_DutyCyclePercentage*TIMER_TCNT0_TOP;

                        Local_u8_ErrorFlag = ES_OK;
                    }
                    else if (Copy_u8_PulseType == TIMER_PHASE_PWM_INVERTING)
                    {
                        //Using Duty Cycle Rule for non inverting fast PWM mode
                        OCR0 = TIMER_TCNT0_TOP - (Copy_f32_DutyCyclePercentage*TIMER_TCNT0_TOP) ;

                        Local_u8_ErrorFlag = ES_OK;
                    }
                    else
                    {
                        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                    }

                }
                else if (Copy_u8_TimerMode == TIMER_FAST_PWM)
                {
                    if(Copy_u8_PulseType == TIMER_FAST_PWM_NON_INVERTING)
                    {
                        //Using Duty Cycle Rule for non-inverting fast PWM mode
                        OCR0 = ((Copy_f32_DutyCyclePercentage)*(TIMER_TCNT0_TOP + 1)) - 1;

                        Local_u8_ErrorFlag = ES_OK;
                    }
                    else if (Copy_u8_PulseType == TIMER_FAST_PWM_INVERTING)
                    {
                        //Using Duty Cycle Rule for non inverting fast PWM mode
                        OCR0 = TIMER_TCNT0_TOP - ((Copy_f32_DutyCyclePercentage)*(TIMER_TCNT0_TOP + 1)) ;

                        Local_u8_ErrorFlag = ES_OK;
                    }
                    else
                    {
                        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                    }
                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }

                break;
            }

            case TIMER_1:
            {
                
                break;
            }

            case TIMER_2:
            {
                if (Copy_u8_TimerMode == TIMER_PHASE_PWM)
                {
                    if(Copy_u8_PulseType == TIMER_PHASE_PWM_NON_INVERTING)
                    {
                        //Using Duty Cycle Rule for non-inverting fast PWM mode
                        OCR2 = Copy_f32_DutyCyclePercentage*TIMER_TCNT2_TOP;

                        Local_u8_ErrorFlag = ES_OK;
                    }
                    else if (Copy_u8_PulseType == TIMER_PHASE_PWM_INVERTING)
                    {
                        //Using Duty Cycle Rule for non inverting fast PWM mode
                        OCR2 = TIMER_TCNT2_TOP - (Copy_f32_DutyCyclePercentage*TIMER_TCNT2_TOP) ;

                        Local_u8_ErrorFlag = ES_OK;
                    }
                    else
                    {
                        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                    }

                }
                else if (Copy_u8_TimerMode == TIMER_FAST_PWM)
                {
                    if(Copy_u8_PulseType == TIMER_FAST_PWM_NON_INVERTING)
                    {
                        //Using Duty Cycle Rule for non-inverting fast PWM mode
                        OCR2 = ((Copy_f32_DutyCyclePercentage)*(TIMER_TCNT2_TOP + 1)) - 1;

                        Local_u8_ErrorFlag = ES_OK;
                    }
                    else if (Copy_u8_PulseType == TIMER_FAST_PWM_INVERTING)
                    {
                        //Using Duty Cycle Rule for non inverting fast PWM mode
                        OCR2 = TIMER_TCNT2_TOP - ((Copy_f32_DutyCyclePercentage)*(TIMER_TCNT2_TOP + 1));

                        Local_u8_ErrorFlag = ES_OK;
                    }
                    else
                    {
                        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                    }

                    Local_u8_ErrorFlag = ES_OK;
                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }
                
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
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }


    return Local_u8_ErrorFlag;
}

extern ErrorState_t Timer_enu_SetCallBack (u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode, void (*Copy_pfun_AppFunction)(void*), void* Copy_pvid_Parameters)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    if(Copy_pfun_AppFunction)
    {
        switch (Copy_u8_TimerNumber)
        {
            case TIMER_0:
            {
                if(Copy_u8_TimerMode == TIMER_NORMAL)
                {
                    apfun_ISRpointers[TIMER_0_OVERFLOW_ISR] = Copy_pfun_AppFunction;

                    apvid_ISRParameters[TIMER_0_OVERFLOW_ISR] = Copy_pvid_Parameters;

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if(Copy_u8_TimerMode == TIMER_CTC)
                {
                    apfun_ISRpointers[TIMER_0_CTC_ISR] = Copy_pfun_AppFunction;

                    apvid_ISRParameters[TIMER_0_CTC_ISR] = Copy_pvid_Parameters;

                    Local_u8_ErrorFlag = ES_OK;
                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }

                break;
            }

            case TIMER_1:
            {

                break;
            }

            case TIMER_2:
            {
                if(Copy_u8_TimerMode == TIMER_NORMAL)
                {
                    apfun_ISRpointers[TIMER_2_OVERFLOW_ISR] = Copy_pfun_AppFunction;

                    apvid_ISRParameters[TIMER_2_OVERFLOW_ISR] = Copy_pvid_Parameters;

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if(Copy_u8_TimerMode == TIMER_CTC)
                {
                    apfun_ISRpointers[TIMER_2_CTC_ISR] = Copy_pfun_AppFunction;

                    apvid_ISRParameters[TIMER_2_CTC_ISR] = Copy_pvid_Parameters;

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
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}


//ISR
void __vector_4 (void)__attribute__((signal));
void __vector_5 (void)__attribute__((signal));
void __vector_10 (void)__attribute__((signal));
void __vector_11 (void)__attribute__((signal));

void __vector_4 (void)
{
    if(apfun_ISRpointers[TIMER_2_CTC_ISR])
    {
       apfun_ISRpointers[TIMER_2_CTC_ISR](apvid_ISRParameters[TIMER_2_CTC_ISR]);
    }
}

void __vector_5 (void)
{
    if(apfun_ISRpointers[TIMER_2_CTC_ISR])
    {
       apfun_ISRpointers[TIMER_2_CTC_ISR](apvid_ISRParameters[TIMER_2_CTC_ISR]);
    }
}

void __vector_10 (void)
{
    if(apfun_ISRpointers[TIMER_0_CTC_ISR])
    {
       apfun_ISRpointers[TIMER_0_CTC_ISR](apvid_ISRParameters[TIMER_0_CTC_ISR]);
    }
}

void __vector_11 (void)
{
    if(apfun_ISRpointers[TIMER_0_OVERFLOW_ISR])
    {
        apfun_ISRpointers[TIMER_0_OVERFLOW_ISR](apvid_ISRParameters[TIMER_0_OVERFLOW_ISR]);
    }
}



//Local functions' implementation
static ErrorState_t enu_SetTimerMode (u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch(Copy_u8_TimerNumber)
    {
        case TIMER_0:
        {

            if(Copy_u8_TimerMode == TIMER_NORMAL)
            {
                //Bits contain 00
                TCCR0 &= ~(1 << TCCR0_WGM00);
                TCCR0 &= ~(1 << TCCR0_WGM01);

                Local_u8_ErrorFlag = ES_OK;
            }
            else if(Copy_u8_TimerMode == TIMER_CTC)
            {
                //Bits contain 01
                TCCR0 |= (1 << TCCR0_WGM00);
                TCCR0 &= ~(1 << TCCR0_WGM01);
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if(Copy_u8_TimerMode == TIMER_PHASE_PWM)
            {
                //Bits contain 10
                TCCR0 &= ~(1 << TCCR0_WGM00);
                TCCR0 |= (1 << TCCR0_WGM01);
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if(Copy_u8_TimerMode == TIMER_FAST_PWM)
            {
                //Bits contain 11
                TCCR0 |= (1 << TCCR0_WGM00);
                TCCR0 |= (1 << TCCR0_WGM01);

                Local_u8_ErrorFlag = ES_OK;
            }
            else 
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }
            
            break;
        }
     
        case TIMER_1:
        {

        }
        break;
     
        case TIMER_2:
        {
            if(Copy_u8_TimerMode == TIMER_NORMAL)
            {
                //Bits contain 00
                TCCR2 &= ~(1 << TCCR2_WGM20);
                TCCR2 &= ~(1 << TCCR2_WGM21);

                Local_u8_ErrorFlag = ES_OK;
            }
            else if(Copy_u8_TimerMode == TIMER_CTC)
            {
                //Bits contain 01
                TCCR2 |= (1 << TCCR2_WGM20);
                TCCR2 &= ~(1 << TCCR2_WGM21);
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if(Copy_u8_TimerMode == TIMER_PHASE_PWM)
            {
                //Bits contain 10
                TCCR2 &= ~(1 << TCCR2_WGM20);
                TCCR2 |= (1 << TCCR2_WGM21);
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if(Copy_u8_TimerMode == TIMER_FAST_PWM)
            {
                //Bits contain 11
                TCCR2 |= (1 << TCCR2_WGM20);
                TCCR2 |= (1 << TCCR2_WGM21);

                Local_u8_ErrorFlag = ES_OK;
            }
            else 
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }

        }
        break;

        default:
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        break;
    }


    return Local_u8_ErrorFlag;
}

static ErrorState_t enu_SetClockSelection(u8 Copy_u8_TimerNumber, u8 Copy_u8_ClockSelection)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    switch (Copy_u8_TimerNumber)
    {
        case TIMER_0:
        {
            switch (Copy_u8_ClockSelection)
            {
                case TIMER_V_GND:
                {
                    //Bits contain 000
                    TCCR0 &= ~ (1 << TCCR0_CS00);
                    TCCR0 &= ~ (1 << TCCR0_CS01);
                    TCCR0 &= ~ (1 << TCCR0_CS02);

                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_1:
                {
                    //Bits contain 001
                    TCCR0 |= (1 << TCCR0_CS00);
                    TCCR0 &= ~ (1 << TCCR0_CS01);
                    TCCR0 &= ~ (1 << TCCR0_CS02);

                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_8:
                {
                    //Bits contain 010
                    TCCR0 &= ~(1 << TCCR0_CS00);
                    TCCR0 |= (1  << TCCR0_CS01);
                    TCCR0 &= ~(1 << TCCR0_CS02);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_64:
                {
                    //Bits contain 011
                    TCCR0 |= (1 << TCCR0_CS00);
                    TCCR0 |= (1 << TCCR0_CS01);
                    TCCR0 &= ~ (1 << TCCR0_CS02);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_256:
                {
                    //Bits contain 100
                    TCCR0 &= ~(1 << TCCR0_CS00);
                    TCCR0 &= ~(1 << TCCR0_CS01);
                    TCCR0 |= (1 << TCCR0_CS02);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_1024:
                {
                    //Bits contain 101
                    TCCR0 |= (1 << TCCR0_CS00);
                    TCCR0 &= ~ (1 << TCCR0_CS01);
                    TCCR0 |= (1 << TCCR0_CS02);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_FALLING_EGDE:
                {
                    //Bits contain 110
                    TCCR0 &= ~(1 << TCCR0_CS00);
                    TCCR0 |= (1 << TCCR0_CS01);
                    TCCR0 |= (1 << TCCR0_CS02);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_RISING_EGDE:
                {
                    //Bits contain 111
                    TCCR0 |= (1 << TCCR0_CS00);
                    TCCR0 |= (1 << TCCR0_CS01);
                    TCCR0 |= (1 << TCCR0_CS02);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                
                default:
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                break;
            }
            
            break;
        }
    
        case TIMER_1:
        {

            
            break;
        }
    
        case TIMER_2:
        {
            //Choosing I/O clock each time 
            //Bit contains 0
            ASSR &= ~( 1 << ASSR_AS2);
            
            switch (Copy_u8_ClockSelection)
            {
                case TIMER_V_GND:
                {
                    //Bits contain 000
                    TCCR2 &= ~ (1 << TCCR2_CS20);
                    TCCR2 &= ~ (1 << TCCR2_CS21);
                    TCCR2 &= ~ (1 << TCCR2_CS22);

                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_1:
                {
                    //Bits contain 001
                    TCCR2 |= (1 << TCCR2_CS20);
                    TCCR2 &= ~ (1 << TCCR2_CS21);
                    TCCR2 &= ~ (1 << TCCR2_CS22);

                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_8:
                {
                    //Bits contain 010
                    TCCR2 &= ~(1 << TCCR2_CS20);
                    TCCR2 |= (1  << TCCR2_CS21);
                    TCCR2 &= ~(1 << TCCR2_CS22);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_32:
                {
                    //Bits contain 011
                    TCCR2 |= (1 << TCCR2_CS20);
                    TCCR2 |= (1 << TCCR2_CS21);
                    TCCR2 &= ~ (1 << TCCR2_CS22);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_64:
                {
                    //Bits contain 100
                    TCCR2 &= ~(1 << TCCR2_CS20);
                    TCCR2 &= ~(1 << TCCR2_CS21);
                    TCCR2 |= (1 << TCCR2_CS22);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_128:
                {
                    //Bits contain 101
                    TCCR2 |= (1 << TCCR2_CS20);
                    TCCR2 &= ~ (1 << TCCR2_CS21);
                    TCCR2 |= (1 << TCCR2_CS22);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_256:
                {
                    //Bits contain 110
                    TCCR2 &= ~(1 << TCCR2_CS20);
                    TCCR2 |= (1 << TCCR2_CS21);
                    TCCR2 |= (1 << TCCR2_CS22);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                case TIMER_PS_1024:
                {
                    //Bits contain 111
                    TCCR2 |= (1 << TCCR2_CS20);
                    TCCR2 |= (1 << TCCR2_CS21);
                    TCCR2 |= (1 << TCCR2_CS22);
                    
                    Local_u8_ErrorFlag = ES_OK;
                    break;
                }
                
                default:
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                break;
            }

            

            break;
        }
    
        default:
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        break;
    }
    return Local_u8_ErrorFlag;
}

static ErrorState_t enu_SetInterruptMode(u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode, u8 Copy_u8_InterruptMode)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    switch (Copy_u8_TimerNumber)
    {
        case TIMER_0:
        {
            if (Copy_u8_TimerMode == TIMER_NORMAL)
            {
                //Clearing bit 0 (TOIE0)
                TIMSK &= (0xFE);
                
                //Choosing Interrupt Mode
                TIMSK |= (Copy_u8_InterruptMode << TIMSK_TOIE0);

                Local_u8_ErrorFlag = ES_OK;
            }
            else if (Copy_u8_TimerMode == TIMER_CTC)
            {
                //Clearing bit 1 (OCIE0)
                TIMSK &= (0xFD);

                //Choosing Interrupt Mode
                TIMSK |= (Copy_u8_InterruptMode << TIMSK_OCIE0);

                Local_u8_ErrorFlag = ES_OK;
            
            }
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }
            
            break;
        }

        case TIMER_1:
        {
            break;
        }

        case TIMER_2:
        {
            if (Copy_u8_TimerMode == TIMER_NORMAL)
            {
                //Clearing bit 6 (TOIE2)
                TIMSK &= (0xBF);
                
                //Choosing Interrupt Mode
                TIMSK |= (Copy_u8_InterruptMode << TIMSK_TOIE2);

                Local_u8_ErrorFlag = ES_OK;
            }
            else if (Copy_u8_TimerMode == TIMER_CTC)
            {
                //Clearing bit 7 (OCIE2)
                TIMSK &= (0x7F);

                //Choosing Interrupt Mode
                TIMSK |= (Copy_u8_InterruptMode << TIMSK_OCIE2);

                Local_u8_ErrorFlag = ES_OK;
            
            }
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }
                        
            break;
        }

        default:
        Local_u8_ErrorFlag - ES_OUT_OF_RANGE;
        break;
    }


    return Local_u8_ErrorFlag;
}

static ErrorState_t enu_SetOCxBehavior(u8 Copy_u8_TimerNumber, u8 Copy_u8_TimerMode, u8 Copy_u8_OCxPinBehavior)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_TimerNumber)
    {
        case TIMER_0:
        {   
            //Clearing bits 5 and 4
            TCCR0 &= (0xCF);

            if(Copy_u8_OCxPinBehavior == TIMER_OCX_DISCONNECTED)
            {
                //OXc is disconnected
                //Bits aleardy cleared
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if((Copy_u8_TimerMode == TIMER_NORMAL) || (Copy_u8_TimerMode == TIMER_CTC))
            {
                //Non-PWM modes
                if(Copy_u8_OCxPinBehavior == TIMER_TOGGLE_OCX)
                {
                    //Bits contain 01
                    TCCR0 |= (1 << TCCR0_COM00);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if (Copy_u8_OCxPinBehavior == TIMER_CLEAR_OCX)
                {
                    //Bits contain 10
                    TCCR0 |= (1 << TCCR0_COM01);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if (Copy_u8_OCxPinBehavior == TIMER_SET_OCX)
                {
                    //Bits contain 11
                    TCCR0 |= (3 << TCCR0_COM00);
                    
                    Local_u8_ErrorFlag = ES_OK;
                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }

            }   
            else if ((Copy_u8_TimerMode == TIMER_PHASE_PWM) || (Copy_u8_TimerMode == TIMER_FAST_PWM))
            {
                //PWM modes
                if((Copy_u8_OCxPinBehavior == TIMER_FAST_PWM_NON_INVERTING || (Copy_u8_OCxPinBehavior == TIMER_PHASE_PWM_NON_INVERTING)))
                {
                    //Bits contain 10
                    TCCR0 |= (1 << TCCR0_COM01);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if ((Copy_u8_OCxPinBehavior == TIMER_FAST_PWM_INVERTING) || (Copy_u8_OCxPinBehavior == TIMER_PHASE_PWM_INVERTING))
                {
                    //Bits contain 11
                    TCCR0 |= (3 << TCCR0_COM00);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }

            } 
            else
            {
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            }
            break;
        }
        
        case TIMER_1:
        {
            
            break;
        }
        
        case TIMER_2:
        {
            
            //Clearing bits 5 and 4
            TCCR2 &= (0xCF);

            if(Copy_u8_OCxPinBehavior == TIMER_OCX_DISCONNECTED)
            {
                //OXc is disconnected
                //Bits aleardy cleared
                
                Local_u8_ErrorFlag = ES_OK;
            }
            else if((Copy_u8_TimerMode == TIMER_NORMAL) || (Copy_u8_TimerMode == TIMER_CTC))
            {
                //Non-PWM modes
                if(Copy_u8_OCxPinBehavior == TIMER_TOGGLE_OCX)
                {
                    //Bits contain 01
                    TCCR2 |= (1 << TCCR2_COM20);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if (Copy_u8_OCxPinBehavior == TIMER_CLEAR_OCX)
                {
                    //Bits contain 10
                    TCCR2 |= (1 << TCCR2_COM21);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if (Copy_u8_OCxPinBehavior == TIMER_SET_OCX)
                {
                    //Bits contain 11
                    TCCR2 |= (3 << TCCR2_COM20);
                    
                    Local_u8_ErrorFlag = ES_OK;
                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }

            }   
            else if ((Copy_u8_TimerMode == TIMER_PHASE_PWM) || (Copy_u8_TimerMode == TIMER_FAST_PWM))
            {
                //PWM modes
                if(Copy_u8_OCxPinBehavior == TIMER_FAST_PWM_NON_INVERTING)
                {
                    //Bits contain 10
                    TCCR2 |= (1 << TCCR2_COM21);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if (Copy_u8_OCxPinBehavior == TIMER_FAST_PWM_INVERTING)
                {
                    //Bits contain 11
                    TCCR2 |= (3 << TCCR2_COM20);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }

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