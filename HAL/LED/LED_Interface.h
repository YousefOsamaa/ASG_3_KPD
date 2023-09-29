#ifndef LED_INTERFACE_FILE
#define LED_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//LEDS Numbers
#define LED_0    0
#define LED_1    1
#define LED_2    2
//   .
//   .
//#define LED_N   N

//APIs' prototypes
extern ErrorState_t LED_enu_Initialization(void);

extern ErrorState_t LED_enu_TurnOnLED(u8 Copy_u8_LEDNumber);

extern ErrorState_t LED_enu_TurnOffLED(u8 Copy_u8_LEDNumber);

extern ErrorState_t LED_enu_TurnOnAllLEDs (void);

extern ErrorState_t LED_enu_TurnOffAllLEDs (void);


#endif
