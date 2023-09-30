#ifndef KEYPAD__CONFIG_FILE
#define KEYPAD__CONFIG_FILE


//Rows and Columns size (Max 4x4)
#define KEYPAD_ROWS_NUMBER      4
#define KEYPAD_COLUMNS_NUMBER   4

//Rows groups and pins
#define KEYPAD_R0_GROUP   DIO_PIN_GROUP_C
#define KEYPAD_R0_PIN     DIO_PIN_0

#define KEYPAD_R1_GROUP   DIO_PIN_GROUP_C
#define KEYPAD_R1_PIN     DIO_PIN_1

#define KEYPAD_R2_GROUP   DIO_PIN_GROUP_C
#define KEYPAD_R2_PIN     DIO_PIN_2

#define KEYPAD_R3_GROUP   DIO_PIN_GROUP_C
#define KEYPAD_R3_PIN     DIO_PIN_3

//Columns groups and pins
#define KEYPAD_C0_GROUP   DIO_PIN_GROUP_C
#define KEYPAD_C0_PIN     DIO_PIN_4

#define KEYPAD_C1_GROUP   DIO_PIN_GROUP_C
#define KEYPAD_C1_PIN     DIO_PIN_5

#define KEYPAD_C2_GROUP   DIO_PIN_GROUP_C
#define KEYPAD_C2_PIN     DIO_PIN_6

#define KEYPAD_C3_GROUP   DIO_PIN_GROUP_C
#define KEYPAD_C3_PIN     DIO_PIN_7



#define KEYPAD_KEY_VALUES  {\
                            {'7', '8', '9', '/' },\ 
                            {'4', '5', '6', 'x' },\
                            {'1', '2', '3', '-' },\   
                            {'C', '0', '=', '+' },\
                          }



#endif

