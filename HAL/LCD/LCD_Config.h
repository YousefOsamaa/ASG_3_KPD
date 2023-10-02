#ifndef LCD_CONFIG_FILE
#define LCD_CONFIG_FILE


//LCD MOde LCD_4_BIT_MODE LCD_8_BIT_MODE
#define LCD_MODE  LCD_4_BIT_MODE

//LCD Number of lines display mode  LCD_ONE_LINE_MODE  LCD_TWO_LINES_MODE
#define LCD_NUMBER_OF_LINES_DSPLAY  LCD_TWO_LINES_MODE

//Font Mode  LCD_5X7_MODE LCD_5X10_MODE
#define LCD_FONT_MODE  LCD_5X7_MODE

//AC moving direction  LCD_AC_INC  LCD_AC_DEC  
#define LCD_CURSOR_MOVING_DIRECTION   LCD_AC_INC

//Display Shift     //LCD_SHIFT_DISPLAY LCD_NO_SHIFT_DISPLAY
#define LCD_DISPLAY_SHIFT_MODE LCD_SHIFT_DISPLAY

//Cursor     LCD_SHOW_CURSOR    LCD_HIDE_CURSOR
#define LCD_CURSOR_DISPLAY    LCD_SHOW_CURSOR

//Cursor Blink  LCD_SHOW_BLINK   LCD_NO_BLINK
#define LCD_BLINK_MODE  LCD_SHOW_BLINK


//Power pins
// #define LCD_VS_GROUP     
// #define LCD_VS_PIN

// #define LCD_VD_GROUP
// #define LCD_VD_PIN

// #define LCD_V0_GROUP
// #define LCD_V0_PIN


//Control Pins
#define LCD_RS_GROUP    DIO_PIN_GROUP_B
#define LCD_RS_PIN      DIO_PIN_1
 
#define LCD_RW_GROUP    DIO_PIN_GROUP_B
#define LCD_RW_PIN      DIO_PIN_2

#define LCD_EN_GROUP    DIO_PIN_GROUP_B
#define LCD_EN_PIN      DIO_PIN_3


//Data pins
#define LCD_D0_GROUP    DIO_PIN_GROUP_B    
#define LCD_D0_PIN      DIO_PIN_0

#define LCD_D1_GROUP    DIO_PIN_GROUP_B
#define LCD_D1_PIN      DIO_PIN_7

#define LCD_D2_GROUP    DIO_PIN_GROUP_B
#define LCD_D2_PIN      DIO_PIN_4

#define LCD_D3_GROUP    DIO_PIN_GROUP_B
#define LCD_D3_PIN      DIO_PIN_5

#define LCD_D4_GROUP    DIO_PIN_GROUP_A
#define LCD_D4_PIN      DIO_PIN_4

#define LCD_D5_GROUP    DIO_PIN_GROUP_A
#define LCD_D5_PIN      DIO_PIN_5

#define LCD_D6_GROUP    DIO_PIN_GROUP_A
#define LCD_D6_PIN      DIO_PIN_6

#define LCD_D7_GROUP    DIO_PIN_GROUP_A
#define LCD_D7_PIN      DIO_PIN_7


//BL power:
#define LCD_A_GROUP
#define LCD_A_PIN

#define LCD_K_GROUP
#define LCD_K_PIN


#define LCD_FLOAT_PRECISION  3



#endif 
