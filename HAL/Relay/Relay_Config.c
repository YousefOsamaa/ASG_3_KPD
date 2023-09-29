#include "Relay_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"





u8 Relay_u8_RelayCount = RELAY_COUNT;

Relay_t Relay_astr_RelayList[RELAY_COUNT] = { 
                                                    {RELAY_0_GROUP,RELAY_0_PIN}
                                                };