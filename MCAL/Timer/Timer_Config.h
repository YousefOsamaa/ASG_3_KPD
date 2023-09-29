#ifndef TIMER_CONFIG_FILE
#define TIMER_CONFIG_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"


#define TIMER_COUNT  2

typedef struct
{
    u8 TimerNumber;
    u8 TimerMode;
    u8 ClockSelection;
    u8 InterruptMode;
    u8 OCxPinBehavior;

}TIMER_t;



#endif