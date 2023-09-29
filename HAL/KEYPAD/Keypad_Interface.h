#ifndef KEYPAD_INTERFACE_FILE
#define KEYPAD_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"


//Random value to make sure the keypad haven't been pressed.
#define KEYPAD_NOT_PRESSED_VALUE  0xFF


extern ErrorState_t Keypad_enu_Initialization(void);

extern ErrorState_t Keypad_enu_GetButtonPressedValue(u8* Copy_pu8_ButtonValue);

#endif
