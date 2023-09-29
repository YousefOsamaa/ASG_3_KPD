#include "LED_Config.h"

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

u8 LED_u8_LEDsCount = LED_COUNT;

LED_t LED_astr_LEDsList [LED_COUNT] = {
                                        {LED_0_GROUP,LED_0_PIN},
                                        {LED_1_GROUP,LED_1_PIN},
                                        {LED_2_GROUP,LED_2_PIN},                            
                                     };
