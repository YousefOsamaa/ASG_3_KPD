#ifndef HEXADECODER_INTERFACE_FILE
#define HEXADECODER_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Interface.h"

//Seven Segments Numbering From left to right
#define SSG_1     0
#define SSG_2     1

//Functions' Prototypes
extern ErrorState_t Hexadecoder_enu_Initialization(void);

extern ErrorState_t Hexadecoder_enu_DisplayNum(u8 Copy_u8_Num); 

extern ErrorState_t Hexadecoder_enu_EnableSSG(u8 Copy_u8_SSGNum);

extern ErrorState_t Hexadecoder_enu_DisableSSG(u8 Copy_u8_EnablePinGroup);

extern ErrorState_t Hexadecoder_enu_StopDisplay(void);



#endif
