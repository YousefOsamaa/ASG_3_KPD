#ifndef SW_CONFIG_FILE
#define SW_CONFIG_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//Pushbuttons pins' groups
#define PUSHBUTTON_0_GROUP    DIO_PIN_GROUP_B  
#define PUSHBUTTON_1_GROUP    DIO_PIN_GROUP_D  
#define PUSHBUTTON_2_GROUP    DIO_PIN_GROUP_D


//Pushbuttons pins' numbers
#define PUSHBUTTON_0_PIN     DIO_PIN_0  
#define PUSHBUTTON_1_PIN     DIO_PIN_6  
#define PUSHBUTTON_2_PIN     DIO_PIN_2  


//Pushbuttons internal pull-up resistor state
#define PUSHBUTTON_0_IRESISTOR   DIO_FLOAT  
#define PUSHBUTTON_1_IRESISTOR   DIO_FLOAT  
#define PUSHBUTTON_2_IRESISTOR   DIO_FLOAT

//Number of Switches used
#define SW_MAX_NUMBER  1



typedef struct
{
    u8 SW_Group;
    u8 SW_Pin;
    u8 SW_IResistorState;

}Switch_t;


#endif
