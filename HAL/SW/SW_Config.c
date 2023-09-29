#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "SW_Config.h"


u8 SW_u8_SwCount  = SW_MAX_NUMBER;
Switch_t SW_astr_SwList [SW_MAX_NUMBER] = { {PUSHBUTTON_0_GROUP,PUSHBUTTON_0_PIN,PUSHBUTTON_0_IRESISTOR},
                                            {PUSHBUTTON_1_GROUP,PUSHBUTTON_1_PIN,PUSHBUTTON_1_IRESISTOR},
                                            {PUSHBUTTON_2_GROUP,PUSHBUTTON_2_PIN,PUSHBUTTON_2_IRESISTOR} 
                                          };
