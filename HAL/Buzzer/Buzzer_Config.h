#ifndef BUZZER_CONFIG_FILE
#define BUZZER_CONFIG_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"



//Buzzer Count
#define BUZZER_COUNT  1

//Buzzer Numbers
#define BUZZER_0    0

//Buzzer groups and pins
#define BUZZER_0_GROUP    DIO_PIN_GROUP_D
#define BUZZER_0_PIN      DIO_PIN_4


//Buzzer Struct
typedef struct 
{
    u8 Buzzer_Group;
    u8 Buzzer_Pin;
}Buzzer_t;

#endif
