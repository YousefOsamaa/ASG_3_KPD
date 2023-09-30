#ifndef CALCULATOR_PRIVATE_FILE
#define CALCULATOR_PRIVATE_FILE


typedef enum
{
    CALCULATOR_ADDITION_SYMBOL = '+',
    CALCULATOR_DIFFERENCE_SYMBOL = '-' ,
    CALCULATOR_DIVISION_SYMBOL = '/',
    CALCULATOR_MULTIPLICATION_SYMBOL = 'x',
    CALCULATOR_ON_OR_CLEAR_SYMBOL = 'C',
    CALCULATOR_EQUAL_SYMBOL = '='
    

}Operators_t;

typedef enum
{
    CALCULATOR_NINE_SYMBOL =   '9' ,
    CALCULATOR_EIGHT_SYMBOL =  '8' ,
    CALCULATOR_SEVEN_SYMBOL =  '7' ,
    CALCULATOR_SIX_SYMBOL =    '6' ,
    CALCULATOR_FIVE_SYMBOL =   '5' ,
    CALCULATOR_FOUR_SYMBOL =   '4' , 
    CALCULATOR_THREE_SYMBOL =  '3' ,
    CALCULATOR_TWO_SYMBOL =    '2' ,
    CALCULATOR_ONE_SYMBOL =    '1' ,
    CALCULATOR_ZERO_SYMBOL =   '0'

}Digits_t;

typedef enum
{
    CALCULATOR_OPERATOR_STATE,
    CALCULATOR_FIRST_DIGIT_STATE,
    CALCULATOR_SECOND_DIGIT_STATE,
    CALCULATOR_ASSIGNMENT_STATE,
    CALCULATOR_RESULT_STATE,
    CALCULATOR_CLEAR_WAITING_STATE

}States_t;

#define CALCULATOR_ASCII_OFFSET     48


//Local functions' prototypes

static ErrorState_t enu_GetUserInput(u8* Copy_pu8_UserInput);

static ErrorState_t enu_CalculateResult(void);

static ErrorState_t enu_WrongChoiceSelected(u8 Copy_Page_Number);

#endif