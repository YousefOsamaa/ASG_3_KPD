#ifndef LCD_PRIVATE_FILE
#define LCD_PRIVATE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//MPU Interface Mode
#define LCD_4_BIT_MODE   0
#define LCD_8_BIT_MODE   1

//Number of lines display mode
#define LCD_ONE_LINE_MODE    0
#define LCD_TWO_LINES_MODE   1

//Font Mode
#define LCD_5X7_MODE    0
#define LCD_5X10_MODE   1

//I/D
#define LCD_AC_DEC    0
#define LCD_AC_INC    1

//SH
#define LCD_NO_SHIFT_DISPLAY  0
#define LCD_SHIFT_DISPLAY     1

//Cursor
#define LCD_HIDE_CURSOR    0
#define LCD_SHOW_CURSOR    1

//Blink
#define LCD_NO_BLINK      0
#define LCD_SHOW_BLINK    1

//DDRAM #defines
#define LCD_FIRST_LINE_BASE_ADDRESS 0x80
#define LCD_SECOND_LINE_BASE_ADDRESS 0xC0
#define LCD_NUMBER_OF_PAGES           4

//Custom Patterns addresses
#define LCD_CUSTOM_PATTERN_0_BASE_ADDRESS 0X40 
#define LCD_CUSTOM_PATTERN_1_BASE_ADDRESS 0X48 
#define LCD_CUSTOM_PATTERN_2_BASE_ADDRESS 0X50 
#define LCD_CUSTOM_PATTERN_3_BASE_ADDRESS 0X58 
#define LCD_CUSTOM_PATTERN_4_BASE_ADDRESS 0X60 
#define LCD_CUSTOM_PATTERN_5_BASE_ADDRESS 0X68 
#define LCD_CUSTOM_PATTERN_6_BASE_ADDRESS 0X70 
#define LCD_CUSTOM_PATTERN_7_BASE_ADDRESS 0X78


//Custom Pattern Numbers
#define LCD_CUSTOM_PATTERN_0       0
#define LCD_CUSTOM_PATTERN_1       1
#define LCD_CUSTOM_PATTERN_2       2
#define LCD_CUSTOM_PATTERN_3       3
#define LCD_CUSTOM_PATTERN_4       4
#define LCD_CUSTOM_PATTERN_5       5
#define LCD_CUSTOM_PATTERN_6       6
#define LCD_CUSTOM_PATTERN_7       7

//Maximum Values
#define LCD_MAX_INTEGER_LENGTH    16

//Error Factor
#define LCD_FLOAT_ERROR   0.00001
#define LCD_DOUBLE_ERROR   0.0000001

static ErrorState_t enu_PassByteAndLatch(u8 Copy_u8_PassedByte);

static ErrorState_t enu_AddCustomCharacter(u8* Copy_au8_CharacterCode,u8 Copy_u8_PatternNumber);

static ErrorState_t enu_ConvertDigitToASCII(u8 *Copy_pu8_Digit);

static ErrorState_t enu_ReverseInteger(u32* Copy_pu32_Num);

static ErrorState_t enu_ConvertFloatToInteger(f32* Copy_f32_DecimalDigits, u8 Copy_u8_FloatPrecision);


#endif 
