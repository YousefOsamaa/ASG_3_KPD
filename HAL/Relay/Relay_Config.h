#ifndef RELAY_CONFIG_FILE
#define RELAY_CONFIG_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"



//Buzzer Count
#define RELAY_COUNT  1

//Buzzer Numbers
#define RELAY_0    0

//Buzzer groups and pins
#define RELAY_0_GROUP    DIO_PIN_GROUP_D
#define RELAY_0_PIN      DIO_PIN_3


//Buzzer Struct
typedef struct 
{
    u8 Relay_Group;
    u8 Relay_Pin;
}Relay_t;

#endif
