#ifndef SW_INTERFACE_FILE
#define SW_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//Switch Numbers
#define SW_NUMBER_0     0
#define SW_NUMBER_1     1
#define SW_NUMBER_2     2
//   .
//   .
//#define SW_NUMBER_N   N
//Functions' prototypes

extern ErrorState_t SW_enu_Initialization(void);

extern ErrorState_t SW_enu_GetSwValue(u8 Copy_u8_SwitchNumber, u8* Copu_pu8_SwitchValue);

#endif


