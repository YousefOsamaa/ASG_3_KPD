#include "Buzzer_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"





u8 Buzzer_u8_BuzzerCount = BUZZER_COUNT;

Buzzer_t Buzzer_astr_BuzzerList[BUZZER_COUNT] = { 
                                                    {BUZZER_0_GROUP,BUZZER_0_PIN}
                                                };