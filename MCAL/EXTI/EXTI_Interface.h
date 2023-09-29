#ifndef EXTI_INTERFACE_FILE
#define EXTI_INTERFACE_FILE


#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//INTs numbers
#define EXTI_INT0  0
#define EXTI_INT1  1
#define EXTI_INT2  2

//INT modes
#define EXTI_INT_MODE      1
#define EXTI_POLLING_MODE  0


//Sense Levels
#define EXTI_LOW_LEVEL       0
#define EXTI_LOGICAL_CHANGE  1
#define EXTI_FALLING_EDGE    2
#define EXTI_RISING_EDGE     3

//Voltage Levels
#define EXTI_LOW    0
#define EXTI_HIGH   1


extern ErrorState_t EXTI_enu_Initialization(void);

extern ErrorState_t EXTI_enu_ISC(u8 Copy_u8_INTNumber, u8 Copy_u8_SenseLevel);

extern ErrorState_t EXTI_enu_INTMode(u8 Copy_u8_INTNumber, u8 Copy_u8_Mode);

extern ErrorState_t EXTI_enu_GetPIF (u8 Copy_u8_INTNumber, u8* Copy_pu8_Result);

extern ErrorState_t EXTI_enu_SeTPIF (u8 Copy_u8_INTNumber, u8 Copy_u8_Value);

extern ErrorState_t EXTI_enu_SetCallBack(u8 Copy_u8_INTNumber, void (* Copy_pfun_AppFunction)(void), void* Copy_pvid_Parameters);





#endif