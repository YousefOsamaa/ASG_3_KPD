#ifndef LCD_INTERFACE_FILE
#define LCD_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//Custom Pattern Numbers
#define LCD_CUSTOM_PATTERN_0       0
#define LCD_CUSTOM_PATTERN_1       1
#define LCD_CUSTOM_PATTERN_2       2
#define LCD_CUSTOM_PATTERN_3       3
#define LCD_CUSTOM_PATTERN_4       4
#define LCD_CUSTOM_PATTERN_5       5
#define LCD_CUSTOM_PATTERN_6       6
#define LCD_CUSTOM_PATTERN_7       7

//Page Numbers
#define LCD_PAGE_1   1
#define LCD_PAGE_2   2
#define LCD_PAGE_3   3
#define LCD_PAGE_4   4


#define LCD_ROW_1       1
#define LCD_ROW_2       2

#define LCD_COLUMN_1    1
#define LCD_COLUMN_2    2
#define LCD_COLUMN_3    3
#define LCD_COLUMN_4    4
#define LCD_COLUMN_5    5
#define LCD_COLUMN_6    6
#define LCD_COLUMN_7    7
#define LCD_COLUMN_8    8
#define LCD_COLUMN_9    9
#define LCD_COLUMN_10   10
#define LCD_COLUMN_11   11
#define LCD_COLUMN_12   12
#define LCD_COLUMN_13   13
#define LCD_COLUMN_14   14
#define LCD_COLUMN_15   15
#define LCD_COLUMN_16   16

//I/D
#define LCD_AC_DEC    0
#define LCD_AC_INC    1

//Functions' protoypes
extern ErrorState_t LCD_enu_Initialization(void);

extern ErrorState_t LCD_enu_SendCommand (u8 Copy_u8_Command);

extern ErrorState_t LCD_enu_SendData (u8 Copy_u8_Data);

extern ErrorState_t LCD_enu_GoToPosition(u8 Copy_u8_Row, u8 Copy_u8_Column,u8 Copy_PageNumber);

extern ErrorState_t LCD_enu_SendString(const char* Copy_pch_StringPointer);

extern ErrorState_t LCD_enu_ClearPage(u8 Copy_u8_PageNumber);

extern ErrorState_t LCD_enu_AddCustomCharacter(u8 Copy_au8_CharacterCode,u8 Copy_u8_PatternNumber);

extern ErrorState_t LCD_enu_DrawSpecialCharacter(u8* Copy_au8_CharacterCode,u8 Copy_u8_PatternSize, u8 Copy_u8_Startpattern, u8 Copy_u8_Row, u8 Copy_u8_Column, u8 Copy_u8_Page, u8 Copy_u8_PrintingDrection);

extern ErrorState_t LCD_enu_WriteIntegerNum(s32 Copy_s32_Num,u8 Copy_u8_Row,u8 Copy_u8_Column,u8 Copy_u8_Page);

extern ErrorState_t LCD_enu_WriteFloatNum(f32 Copy_f32_Num, u8 Copy_u8_Row,u8 Copy_u8_Column,u8 Copy_u8_Page);


#endif