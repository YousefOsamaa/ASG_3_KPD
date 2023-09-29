#ifndef DIO_INTERFACE_FILE
#define DIO_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//Pin groups
#define DIO_PIN_GROUP_A   0
#define DIO_PIN_GROUP_B   1
#define DIO_PIN_GROUP_C   2
#define DIO_PIN_GROUP_D   3


//Pin Numbers
#define DIO_PIN_0         0
#define DIO_PIN_1         1
#define DIO_PIN_2         2
#define DIO_PIN_3         3
#define DIO_PIN_4         4
#define DIO_PIN_5         5
#define DIO_PIN_6         6
#define DIO_PIN_7         7


//Pin Directions
#define DIO_PIN_READ      0
#define DIO_PIN_WRITE     1

//Pull-up resistors state
#define DIO_FLOAT         0
#define DIO_PULL_UP       1

//Voltage Levels
#define DIO_LOW           0
#define DIO_HIGH          1


//Functions' Prototypes
//extern ErrorState_t DIO_enu_Initialization(void);

extern ErrorState_t DIO_enu_SetPinDiretion(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber, u8 Copy_u8_PinDirection);

extern ErrorState_t DIO_enu_SetPinState(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber, u8 Copy_u8_PinState);

extern ErrorState_t DIO_enu_SetPinValue(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber, u8 Copy_u8_PinValue);

extern ErrorState_t DIO_enu_TogglePinValue(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber);

extern ErrorState_t DIO_enu_GetPinValue(u8 Copy_u8_PinGroup, u8 Copy_u8_PinNumber, u8* Copy_pu8_PinValue);



#endif
