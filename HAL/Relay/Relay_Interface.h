#ifndef RELAY_INTERFACE_FILE
#define RELAY_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"


//Buzzer Numbers
#define RELAY_0    0


//APIs prototypes

extern ErrorState_t Relay_enu_Initialization(void);

extern ErrorState_t Relay_enu_TuronOnRelay(u8 Copy_u8_RelayNumber);

extern ErrorState_t Relay_enu_TuronOffRelay(u8 Copy_u8_RelayNumber);

extern ErrorState_t Relay_enu_TurnOnAllRelays(void);

extern ErrorState_t Relay_enu_TurnOffAllRelays(void);

#endif
