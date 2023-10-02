#include "../LIB/STD.h"
#include "../LIB/ErrorStates.h"
#include "util/delay.h"

#include "../HAL/LCD//LCD_Interface.h"
#include "../HAL/KEYPAD/Keypad_Interface.h"

#include "Calculator_Private.h"
#include "Calculator_Config.h"

static u8 u8_CalculationStage ;

static u8 u8_FirstDigit ;
static u8 u8_ArithmeticOperator ;
static u8 u8_SecondDigit ;

//APIs' implementation
extern ErrorState_t Calculator_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    //Initializing HALs
    LCD_enu_Initialization();
    Keypad_enu_Initialization();
    
    //Initializing the calculatorto start accepting digits
    u8_CalculationStage = CALCULATOR_FIRST_DIGIT_STATE;
    
    //Places cursor at the start of the screen (Home)
    LCD_enu_GoToPosition(LCD_ROW_1, LCD_COLUMN_1, LCD_PAGE_1);

    return Local_u8_ErrorFlag;
}

extern ErrorState_t Calculator_enu_Operation(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u8 Local_u8_UserInput = KEYPAD_NOT_PRESSED_VALUE;

    while (1)
    {
        switch (u8_CalculationStage)
        {
            case CALCULATOR_FIRST_DIGIT_STATE:
            case CALCULATOR_SECOND_DIGIT_STATE:
            case CALCULATOR_OPERATOR_STATE:
            case CALCULATOR_ASSIGNMENT_STATE:
            case CALCULATOR_CLEAR_WAITING_STATE:
                
                //USer input is acquired here (Digit, Operator, or command )
                Local_u8_ErrorFlag = enu_GetUserInput(&Local_u8_UserInput);

            break;
            
            case CALCULATOR_RESULT_STATE:

                Local_u8_ErrorFlag = enu_CalculateResult();
            
            break;

            default:

                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            break;

            }

    }
    
    
    return Local_u8_ErrorFlag;
}


//Local functions' implementations
static ErrorState_t enu_GetUserInput(u8* Copy_pu8_UserInput)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if (Copy_pu8_UserInput)
    {    
        switch (u8_CalculationStage)
        {
            case CALCULATOR_FIRST_DIGIT_STATE:
            {

                while (((*Copy_pu8_UserInput > CALCULATOR_NINE_SYMBOL) || (*Copy_pu8_UserInput < CALCULATOR_ZERO_SYMBOL)) || (*Copy_pu8_UserInput == KEYPAD_NOT_PRESSED_VALUE))
                {
                    //Getting keypressed from keypad
                    Keypad_enu_GetButtonPressedValue(Copy_pu8_UserInput);

                }

                //Displaying chosen digit on LCD
                LCD_enu_WriteIntegerNum(*Copy_pu8_UserInput - CALCULATOR_ASCII_OFFSET, LCD_ROW_1, LCD_COLUMN_1, LCD_PAGE_1);

                //Saves the digit in a global variable
                u8_FirstDigit = *Copy_pu8_UserInput - CALCULATOR_ASCII_OFFSET;

                //now it's time to take an arithmetic operator from the user
                u8_CalculationStage = CALCULATOR_OPERATOR_STATE;

                break;
            }
            case CALCULATOR_OPERATOR_STATE:
            {
                while ((*Copy_pu8_UserInput != CALCULATOR_ADDITION_SYMBOL && *Copy_pu8_UserInput != CALCULATOR_DIFFERENCE_SYMBOL && *Copy_pu8_UserInput != CALCULATOR_DIVISION_SYMBOL && *Copy_pu8_UserInput != CALCULATOR_MULTIPLICATION_SYMBOL) || (*Copy_pu8_UserInput == KEYPAD_NOT_PRESSED_VALUE))
                {
                    //Getting keypressed from keypad
                    Keypad_enu_GetButtonPressedValue(Copy_pu8_UserInput);

                }

                //Displaying arithmetic symbol on LCD
                LCD_enu_GoToPosition(LCD_ROW_1, LCD_COLUMN_2, LCD_PAGE_1);
                LCD_enu_SendData(*Copy_pu8_UserInput);

                //Saves the operator in a global variable
                u8_ArithmeticOperator = *Copy_pu8_UserInput;
                
                //Now it's time to take THE second digit from the user
                u8_CalculationStage = CALCULATOR_SECOND_DIGIT_STATE;

                break;
            }

            case CALCULATOR_SECOND_DIGIT_STATE:
            {

                while (((*Copy_pu8_UserInput > CALCULATOR_NINE_SYMBOL) || (*Copy_pu8_UserInput < CALCULATOR_ZERO_SYMBOL)) || (*Copy_pu8_UserInput == KEYPAD_NOT_PRESSED_VALUE))
                {
                    //Getting keypressed from keypad
                    Keypad_enu_GetButtonPressedValue(Copy_pu8_UserInput);

                }

                //Displaying chosen digit on LCD
                LCD_enu_WriteIntegerNum(*Copy_pu8_UserInput - CALCULATOR_ASCII_OFFSET, LCD_ROW_1, LCD_COLUMN_3, LCD_PAGE_1);

                //Saves the operator in a global variable
                u8_SecondDigit = *Copy_pu8_UserInput - CALCULATOR_ASCII_OFFSET;

                //now it's time to take the assignmsent operator  from the user
                u8_CalculationStage = CALCULATOR_ASSIGNMENT_STATE;

                break;
            }
            case CALCULATOR_ASSIGNMENT_STATE:
            {
                while((*Copy_pu8_UserInput != CALCULATOR_EQUAL_SYMBOL) || (*Copy_pu8_UserInput == KEYPAD_NOT_PRESSED_VALUE))
                {
                    //Getting keypressed from keypad
                    Keypad_enu_GetButtonPressedValue(Copy_pu8_UserInput);

                }

                //Displaying Assignment operator symbol on LCD
                LCD_enu_GoToPosition(LCD_ROW_1, LCD_COLUMN_4, LCD_PAGE_1);
                LCD_enu_SendData(*Copy_pu8_UserInput);

                //now it's time to take an arithmetic operator from the user
                u8_CalculationStage = CALCULATOR_RESULT_STATE;
                
                break;
            }

            case CALCULATOR_CLEAR_WAITING_STATE:

                while((*Copy_pu8_UserInput != CALCULATOR_ON_OR_CLEAR_SYMBOL) || (*Copy_pu8_UserInput == KEYPAD_NOT_PRESSED_VALUE))
                {

                    //Getting keypressed from keypad
                    Keypad_enu_GetButtonPressedValue(Copy_pu8_UserInput);
                    
                }

                //Clearing Page
                LCD_enu_ClearPage(LCD_PAGE_1);
                
                //Resetting Cusrsor
                LCD_enu_GoToPosition(LCD_ROW_1, LCD_COLUMN_1, LCD_PAGE_1);

                u8_CalculationStage = CALCULATOR_FIRST_DIGIT_STATE;


            break;
        
            default:
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            break;
        }

    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }
    
    return Local_u8_ErrorFlag;

}

static ErrorState_t enu_CalculateResult(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    switch (u8_ArithmeticOperator)
    {
        case CALCULATOR_ADDITION_SYMBOL:
        {
            LCD_enu_WriteIntegerNum(u8_FirstDigit + u8_SecondDigit, LCD_ROW_1, LCD_COLUMN_5, LCD_PAGE_1);

            Local_u8_ErrorFlag = ES_OK;
            
            break;
        }

        case CALCULATOR_DIFFERENCE_SYMBOL:
        {

            LCD_enu_WriteIntegerNum(u8_FirstDigit - u8_SecondDigit, LCD_ROW_1, LCD_COLUMN_5, LCD_PAGE_1);
            

            Local_u8_ErrorFlag = ES_OK;

            break;
        }

        case CALCULATOR_DIVISION_SYMBOL:
        {
            f32 Local_f32_DivisionResult = ((f32)u8_FirstDigit)/u8_SecondDigit;
            
            LCD_enu_WriteFloatNum(Local_f32_DivisionResult, LCD_ROW_1, LCD_COLUMN_5, LCD_PAGE_1);
            
            Local_u8_ErrorFlag = ES_OK;
            
            break;
        }
        case CALCULATOR_MULTIPLICATION_SYMBOL:
        {

            LCD_enu_WriteIntegerNum(u8_FirstDigit*u8_SecondDigit, LCD_ROW_1, LCD_COLUMN_5, LCD_PAGE_1);

            Local_u8_ErrorFlag = ES_OK;
            
            break;
        }
    
         default:
         Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
         break;
    }


    //Advance to the next stage 
    u8_CalculationStage = CALCULATOR_CLEAR_WAITING_STATE;


    return Local_u8_ErrorFlag;
}

static ErrorState_t enu_WrongChoiceSelected(u8 Copy_Page_Number)
{
    u8 Local_u8_ErrorFlag = ES_NOK;


    //Displaying 'X' for wrong choice entered
    LCD_enu_GoToPosition(LCD_ROW_2, LCD_COLUMN_16, Copy_Page_Number);
    LCD_enu_SendData('X');
    _delay_ms(500);

    //Erasing x after 500 ms (could be done by counter)                        
    LCD_enu_GoToPosition(LCD_ROW_2,LCD_COLUMN_16,Copy_Page_Number);
    LCD_enu_SendData(' ');

    Local_u8_ErrorFlag = ES_OK;

    return Local_u8_ErrorFlag;
}
