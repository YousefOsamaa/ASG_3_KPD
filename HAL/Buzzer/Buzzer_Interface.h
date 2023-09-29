#ifndef BUZZER_INTERFACE_FILE
#define BUZZER_INTERFACE_FILE

#include "../../General/STD.h"
#include "../../General/ErrorStates.h"


//Buzzer Numbers
#define BUZZER_0    0


//APIs prototypes

extern ErrorState_t Buzzer_enu_Initialization(void);

extern ErrorState_t Buzzer_enu_TuronOnBuzzer(u8 Copy_u8_BuzzerNumber);

extern ErrorState_t Buzzer_enu_TuronOffBuzzer(u8 Copy_u8_BuzzerNumber);

extern ErrorState_t Buzzer_enu_TurnOnAllBuzzers(void);

extern ErrorState_t Buzzer_enu_TurnOffAllBuzzers(void);



#endif