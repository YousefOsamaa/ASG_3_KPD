#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"

u8 EXTI_u8_INTCount = EXTI_INT_COUNT;

EXTI_t EXTI_astr_INTList [EXTI_INT_COUNT]= {
                                             {EXTI_INT0, EXTI_INT_MODE, EXTI_RISING_EDGE},
                                             {EXTI_INT1,EXTI_INT_MODE, EXTI_LOW_LEVEL},
                                             {EXTI_INT2, EXTI_INT_MODE, EXTI_LOW_LEVEL}
                            }               ;