#ifndef EXTI_PRIVATE_FILE
#define EXTI_PRIVATE_FILE


//Registers addresses
#define GICR *(volatile u8*)(0x5B)
#define GIFR *(volatile u8*)(0x5A)
#define MCUCR *(volatile u8*)(0x55)
#define MCUCSR *(volatile u8*)(0x54)

//Bits Numbers
#define GICR_INT0    6
#define GICR_INT1    7
#define GICR_INT2    5

#define GIFR_INTF0   6
#define GIFR_INTF1   7
#define GIFR_INTF2   5

#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3

#define MCUCSR_ISC2  6


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

//ISR Count
#define EXTI_ISR_Count  3



//local functions' prototypes

static ErrorState_t enu_SetMode(u8 Copy_u8_INTNumber, u8 Copy_u8_Mode);

static ErrorState_t enu_SetSenseLevel(u8 Copy_u8_INTNumber, u8 Copy_u8_SenseLevel);

static ErrorState_t enu_SetFlagValue(u8 Copy_u8_INTNumber, u8 Copy_u8_Value);

#endif