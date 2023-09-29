#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_Interface.h"


#include "LCD_Config.h"
#include "LCD_Private.h"


//Functions' implementations'
extern ErrorState_t LCD_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    //Intitial delay
     _delay_ms(35);
   
    DIO_enu_SetPinDiretion(LCD_RS_GROUP,LCD_RS_PIN,DIO_PIN_WRITE);
    DIO_enu_SetPinDiretion(LCD_RW_GROUP,LCD_RW_PIN,DIO_PIN_WRITE);
    DIO_enu_SetPinDiretion(LCD_EN_GROUP,LCD_EN_PIN,DIO_PIN_WRITE);

    DIO_enu_SetPinDiretion(LCD_D7_GROUP,LCD_D7_PIN,DIO_PIN_WRITE);
    DIO_enu_SetPinDiretion(LCD_D6_GROUP,LCD_D6_PIN,DIO_PIN_WRITE);
    DIO_enu_SetPinDiretion(LCD_D5_GROUP,LCD_D5_PIN,DIO_PIN_WRITE);
    DIO_enu_SetPinDiretion(LCD_D4_GROUP,LCD_D4_PIN,DIO_PIN_WRITE);
        

    #if LCD_MODE == LCD_8_BIT_MODE
       
        DIO_enu_SetPinDiretion(LCD_D3_GROUP,LCD_D3_PIN,DIO_PIN_WRITE);
        DIO_enu_SetPinDiretion(LCD_D2_GROUP,LCD_D2_PIN,DIO_PIN_WRITE);
        DIO_enu_SetPinDiretion(LCD_D1_GROUP,LCD_D1_PIN,DIO_PIN_WRITE);
        DIO_enu_SetPinDiretion(LCD_D0_GROUP,LCD_D0_PIN,DIO_PIN_WRITE);

        
        //Function Set
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
        enu_PassByteAndLatch(0x38);

    #elif LCD_MODE == LCD_4_BIT_MODE

        //Function Set
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
                
        DIO_enu_SetPinValue(LCD_D7_GROUP,LCD_D7_PIN,DIO_LOW);
        DIO_enu_SetPinValue(LCD_D6_GROUP,LCD_D6_PIN,DIO_LOW);
        DIO_enu_SetPinValue(LCD_D5_GROUP,LCD_D5_PIN,DIO_HIGH);
        DIO_enu_SetPinValue(LCD_D4_GROUP,LCD_D4_PIN,DIO_LOW);

        DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_HIGH);
        _delay_ms(1);
        DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_LOW);
       
        
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
        enu_PassByteAndLatch(0x28);

    #else
        #error "Worng LCD_MODE chose" 

    #endif


    //Display ON/OFF control
    DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
    enu_PassByteAndLatch(0x0F);

    //Display clear
    DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
    enu_PassByteAndLatch(0x01);

    //Entry Mode Set
    DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
    enu_PassByteAndLatch(0x06);
    

    Local_u8_ErrorFlag = ES_OK; //should be checked on with a for loop
    return Local_u8_ErrorFlag;
}

extern ErrorState_t LCD_enu_SendCommand (u8 Copy_u8_Command)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    DIO_enu_SetPinValue(LCD_RS_GROUP,LCD_RS_PIN,DIO_LOW);
    
    enu_PassByteAndLatch(Copy_u8_Command);

    Local_u8_ErrorFlag = ES_OK; //Should be checked by a for loop
    return Local_u8_ErrorFlag;

}

extern ErrorState_t LCD_enu_SendData (u8 Copy_u8_Data)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    DIO_enu_SetPinValue(LCD_RS_GROUP,LCD_RS_PIN,DIO_HIGH);
    
    enu_PassByteAndLatch(Copy_u8_Data);

    Local_u8_ErrorFlag = ES_OK; //Should be checked by a for loop

    return Local_u8_ErrorFlag;

}

extern ErrorState_t LCD_enu_GoToPosition(u8 Copy_u8_Row, u8 Copy_u8_Column, u8 Copy_PageNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    if((Copy_u8_Column <= 16 && Copy_u8_Column >= 1) && (Copy_u8_Row <= 2 && Copy_u8_Row >= 1) && (Copy_PageNumber <= LCD_NUMBER_OF_PAGES && Copy_PageNumber >= 1))
    {
        DIO_enu_SetPinValue(LCD_RS_GROUP,LCD_RS_PIN,DIO_LOW);
        enu_PassByteAndLatch(LCD_FIRST_LINE_BASE_ADDRESS + (Copy_u8_Column - 1) + (LCD_SECOND_LINE_BASE_ADDRESS - LCD_FIRST_LINE_BASE_ADDRESS)*(Copy_u8_Row - 1)  + 16*(Copy_PageNumber -1));
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }


    return Local_u8_ErrorFlag;
}

extern ErrorState_t LCD_enu_SendString(const char* Copy_pc_StringPointer)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    if(Copy_pc_StringPointer)
    {
        while (*Copy_pc_StringPointer)
        {
            DIO_enu_SetPinValue(LCD_RS_GROUP , LCD_RS_PIN , DIO_HIGH);
            enu_PassByteAndLatch(*Copy_pc_StringPointer++);


        }
        
        Local_u8_ErrorFlag = ES_OK;

    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t LCD_enu_ClearPage(u8 Copy_u8_PageNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    if(Copy_u8_PageNumber >= 1 && Copy_u8_PageNumber <= LCD_NUMBER_OF_PAGES)
    {
        u8 Local_u8_Counter = 0;

        //Clearing first line:

        //Placing cursor at the beginning of the line
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
        enu_PassByteAndLatch(16*(Copy_u8_PageNumber - 1) + LCD_FIRST_LINE_BASE_ADDRESS);
        
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_HIGH);

        for(Local_u8_Counter = 0; Local_u8_Counter < 16; Local_u8_Counter++)
        {
            //Placing Space in each location
            enu_PassByteAndLatch(' ');
        }
        


        //Clearing second line
        
        //Placing cursor at the beginning of the line
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
        enu_PassByteAndLatch(16*(Copy_u8_PageNumber - 1) + LCD_SECOND_LINE_BASE_ADDRESS);
        
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_HIGH);

        for(Local_u8_Counter = 0; Local_u8_Counter < 16; Local_u8_Counter++)
        {
            //Placing Space in each location
            enu_PassByteAndLatch(' ');
        }
        

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }

    return Local_u8_ErrorFlag;

}

extern ErrorState_t LCD_enu_DrawSpecialCharacter(u8* Copy_au8_CharacterCode,u8 Copy_u8_PatternSize, u8 Copy_u8_Startpattern, u8 Copy_u8_Row, u8 Copy_u8_Column,u8 Copy_u8_Page,u8 Copy_u8_PrintingDrection)
{
    u8 Local_u8_ErorrFlag = ES_NOK;
    
    if(Copy_au8_CharacterCode)
    {
        u8* Local_pu8_PassingPointer = NULL;
        u8 Local_u8_LoopCounter = 0;

        if(((Copy_u8_PatternSize >= 1) && (Copy_u8_PatternSize <= 8)) && (Copy_u8_Startpattern <= LCD_CUSTOM_PATTERN_7) && ((LCD_CUSTOM_PATTERN_7  - Copy_u8_Startpattern + 1) >= Copy_u8_PatternSize) && ((Copy_u8_Row >= 1) && (Copy_u8_Row <= 2)) && ((Copy_u8_Column >= 1) && (Copy_u8_Column <= 16)) && (Copy_u8_PrintingDrection <= LCD_AC_INC) && (Copy_u8_Page <= LCD_NUMBER_OF_PAGES))
        {
            //Adding Each distinct Custom character to CGRAM
            for(Local_u8_LoopCounter = 0; Local_u8_LoopCounter < Copy_u8_PatternSize*8; Local_u8_LoopCounter += 8)
            {
                Local_pu8_PassingPointer = Copy_au8_CharacterCode + Local_u8_LoopCounter;
                enu_AddCustomCharacter(Local_pu8_PassingPointer,Copy_u8_Startpattern + (Local_u8_LoopCounter/8));
            }

            //Choosing IR
            DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
            
            //Chaninging AC direction with Entry Mode Set command
            switch (Copy_u8_PrintingDrection)
            {
                case LCD_AC_INC:
                enu_PassByteAndLatch(0x06);
                break;
            
                case LCD_AC_DEC:
                enu_PassByteAndLatch(0x04);
                break;            
                
                default:
                break;
            }

            //Choosing IR
            DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
            
            //Placing Cursor in the intended Position
            enu_PassByteAndLatch( LCD_FIRST_LINE_BASE_ADDRESS + (Copy_u8_Column - 1) + (LCD_SECOND_LINE_BASE_ADDRESS - LCD_FIRST_LINE_BASE_ADDRESS)*(Copy_u8_Row - 1) + 16*(Copy_u8_Page - 1));


            //Choosing DR
            DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_HIGH);
            
            //Printing the special character
            for(Local_u8_LoopCounter = 0; Local_u8_LoopCounter < Copy_u8_PatternSize; Local_u8_LoopCounter++)
            {
                enu_PassByteAndLatch(Local_u8_LoopCounter);

            }
            
            Local_u8_ErorrFlag = ES_OK;
        }
        else
        {
            Local_u8_ErorrFlag = ES_OUT_OF_RANGE;
        }
        

    }
    else
    {
        Local_u8_ErorrFlag = ES_NULL_POINTER;
    }


    return Local_u8_ErorrFlag;
}

extern ErrorState_t LCD_enu_WriteIntegerNum(s32 Copy_s32_Num,u8 Copy_u8_Row,u8 Copy_u8_Column,u8 Copy_u8_Page)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    s32 Local_u32_TempVariable;
    u8 Local_u8_DigitCount = 0;
    u8 local_u8_NegativeFlag = False;

    //Handling the negative case
    if(Copy_s32_Num < 0)
    {
        local_u8_NegativeFlag = True;
        Copy_s32_Num *= -1;
    }

    Local_u32_TempVariable = Copy_s32_Num;
    //Counting Number digits 
    do
    {
        Local_u8_DigitCount++;
        Local_u32_TempVariable  /= 10;

    }while(Local_u32_TempVariable);



    if(((Copy_u8_Row >= 1) && (Copy_u8_Row <= 2)) && ((Copy_u8_Column >= 1) && (Copy_u8_Column <= 16))  && (Copy_u8_Page <= LCD_NUMBER_OF_PAGES) && (Local_u8_DigitCount <= LCD_MAX_INTEGER_LENGTH))
    {
        Local_u32_TempVariable = Copy_s32_Num;
        enu_ReverseInteger(&Local_u32_TempVariable);

        //Choosing IR
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN,DIO_LOW);
        //Placing Cursor
        enu_PassByteAndLatch(LCD_FIRST_LINE_BASE_ADDRESS + (Copy_u8_Column - 1) + (LCD_SECOND_LINE_BASE_ADDRESS - LCD_FIRST_LINE_BASE_ADDRESS)*(Copy_u8_Row - 1) + 16*(Copy_u8_Page - 1));
        
        //Choosing DR
        DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN,DIO_HIGH);
        //Printing Negative Sign
        if(local_u8_NegativeFlag)
        {
            enu_PassByteAndLatch('-');
        }
        //Printing one digit at a time

        while (Local_u32_TempVariable)
        {
            enu_PassByteAndLatch((Local_u32_TempVariable % 10) + 48);
            Local_u32_TempVariable /= 10;
            Local_u8_DigitCount--;
        }
        //Printing any trail zeroes that might have got lost when the number was reversed
        while (Local_u8_DigitCount)
        {
            enu_PassByteAndLatch('0');
            Local_u8_DigitCount--;
        }
        
        
        
        
        Local_u8_ErrorFlag = ES_OK;

    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }
    


    return Local_u8_ErrorFlag;
}

extern ErrorState_t LCD_enu_WriteFloatNum(f32 Copy_f32_Num, u8 Copy_u8_Row,u8 Copy_u8_Column,u8 Copy_u8_Page)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    //Temp Variables
    u32 Local_u32_WholeDigits;
    f32 Local_f32_DecimalDigits;
    //Counters
    u8 Local_u8_WholeDigitCount = 0;
    u8 Local_u8_DecimalDigitCount = 0;
    //Flags
    u8 local_u8_NegativeFlag = False;

    //Handling the negative case
    if(Copy_f32_Num < 0)
    {
        local_u8_NegativeFlag = True;
        Copy_f32_Num *= -1;
    }


    Local_u32_WholeDigits = Copy_f32_Num;

    Local_f32_DecimalDigits = Copy_f32_Num - (f32)(Local_u32_WholeDigits);
   
    //Counting whole digits 
    do
    {
        Local_u8_WholeDigitCount++;
        Local_u32_WholeDigits  /= 10;

    }while(Local_u32_WholeDigits);

    
    DIO_enu_SetPinValue(LCD_RS_GROUP,LCD_RS_PIN,DIO_HIGH);
    //Counting decimal digits
    Local_u32_WholeDigits = 0;
    while((Local_f32_DecimalDigits - (f32)Local_u32_WholeDigits) >= LCD_FLOAT_ERROR)
    {
        Local_f32_DecimalDigits *= 10;
        Local_u32_WholeDigits = Local_f32_DecimalDigits;
        Local_u8_DecimalDigitCount++;
        
    
    }

    if(((Copy_u8_Row >= 1) && (Copy_u8_Row <= 2)) && ((Copy_u8_Column >= 1) && (Copy_u8_Column <= 16))  && (Copy_u8_Page <= LCD_NUMBER_OF_PAGES) && ((Local_u32_WholeDigits + Local_u8_DecimalDigitCount) <= LCD_MAX_INTEGER_LENGTH))
    {
        //Choosing IR
        DIO_enu_SetPinValue(LCD_RS_GROUP,LCD_RS_PIN,DIO_LOW);
        //Setting the Cursor in position
        enu_PassByteAndLatch(LCD_FIRST_LINE_BASE_ADDRESS + (Copy_u8_Column - 1) + (LCD_SECOND_LINE_BASE_ADDRESS - LCD_FIRST_LINE_BASE_ADDRESS)*(Copy_u8_Row - 1) + 16*(Copy_u8_Page - 1));    
        
        
        //Choosing DR
        DIO_enu_SetPinValue(LCD_RS_GROUP,LCD_RS_PIN,DIO_HIGH);
        //Printing Negative Sign if exists
        if(local_u8_NegativeFlag)
        {
            enu_PassByteAndLatch('-');
        }

        //A] Printing whole digits 
        Local_u32_WholeDigits = Copy_f32_Num;
        enu_ReverseInteger(&Local_u32_WholeDigits);


        //Choosing DR
        DIO_enu_SetPinValue(LCD_RS_GROUP,LCD_RS_PIN,DIO_HIGH);
        //Printing one digit at a time        
        while(Local_u32_WholeDigits)
        {
            enu_PassByteAndLatch((Local_u32_WholeDigits % 10) + 48);
            Local_u32_WholeDigits /= 10;
            Local_u8_WholeDigitCount--;
        }
        //Printing any lost zeroes when the number was reversed 
        while(Local_u8_WholeDigitCount)
        {
            enu_PassByteAndLatch('0');
            Local_u8_WholeDigitCount--;
        }


        //B] Printing decimal digits
        if(Local_f32_DecimalDigits)
        {
            //Choosing DR
            DIO_enu_SetPinValue(LCD_RS_GROUP,LCD_RS_PIN,DIO_HIGH);

            //Printing decimal point only if decimal digit exits
            enu_PassByteAndLatch('.');

            //Reversing Digits (Using Local_u32_Wholedigits for safety) 'u32'
            Local_u32_WholeDigits = Local_f32_DecimalDigits;
            enu_ReverseInteger(&Local_u32_WholeDigits);
            
            //Printing one digit at a time 
            while(Local_u32_WholeDigits)
            {
                enu_PassByteAndLatch((Local_u32_WholeDigits % 10) + 48);
                Local_u32_WholeDigits /= 10;
                Local_u8_DecimalDigitCount--;
            }
            //Printing any lost zeroes when the number was reversed 
            while(Local_u8_DecimalDigitCount)
            {
                enu_PassByteAndLatch('0');
                Local_u8_DecimalDigitCount--;
            }
            
            

        }

        Local_u8_ErrorFlag = ES_OK;


    }
    else
    {
        Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
    }

    return Local_u8_ErrorFlag;

}

//Local Functions' implementations
static ErrorState_t enu_PassByteAndLatch(u8 Copy_u8_PassedByte)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    DIO_enu_SetPinValue(LCD_RW_GROUP,LCD_RW_PIN,DIO_LOW);
    
    DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_LOW);

    DIO_enu_SetPinValue(LCD_D7_GROUP,LCD_D7_PIN,(Copy_u8_PassedByte >> 7) & 1);
    DIO_enu_SetPinValue(LCD_D6_GROUP,LCD_D6_PIN,(Copy_u8_PassedByte >> 6) & 1);
    DIO_enu_SetPinValue(LCD_D5_GROUP,LCD_D5_PIN,(Copy_u8_PassedByte >> 5) & 1);
    DIO_enu_SetPinValue(LCD_D4_GROUP,LCD_D4_PIN,(Copy_u8_PassedByte >> 4) & 1);

    #if LCD_MODE == LCD_8_BIT_MODE
        
        DIO_enu_SetPinValue(LCD_D3_GROUP, LCD_D3_PIN, (Copy_u8_PassedByte >> 3) & 1);
        DIO_enu_SetPinValue(LCD_D2_GROUP, LCD_D2_PIN, (Copy_u8_PassedByte >> 2) & 1);
        DIO_enu_SetPinValue(LCD_D1_GROUP, LCD_D1_PIN, (Copy_u8_PassedByte >> 1) & 1);
        DIO_enu_SetPinValue(LCD_D0_GROUP, LCD_D0_PIN, (Copy_u8_PassedByte >> 0) & 1);

        DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_HIGH);
        _delay_ms(1);
        DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_LOW);

    #elif LCD == LCD_4_BIT_MODE 

        DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_HIGH);
        _delay_ms(1);
        DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_LOW);
        
        DIO_enu_SetPinValue(LCD_D7_GROUP,LCD_D7_PIN,(Copy_u8_PassedByte >> 3) & 1);
        DIO_enu_SetPinValue(LCD_D6_GROUP,LCD_D6_PIN,(Copy_u8_PassedByte >> 2) & 1);
        DIO_enu_SetPinValue(LCD_D5_GROUP,LCD_D5_PIN,(Copy_u8_PassedByte >> 1) & 1);
        DIO_enu_SetPinValue(LCD_D4_GROUP,LCD_D4_PIN,(Copy_u8_PassedByte >> 0) & 1);

        DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_HIGH);
        _delay_ms(1);
        DIO_enu_SetPinValue(LCD_EN_GROUP,LCD_EN_PIN,DIO_LOW);
    #endif


    //LCD MPU command delay
    _delay_ms(2);

    Local_u8_ErrorFlag = ES_OK; //Should be grouped in an array and returned after a for loop 
    return Local_u8_ErrorFlag;
    

}

static ErrorState_t enu_AddCustomCharacter(u8* Copy_au8_CharacterCode,u8 Copy_u8_PatternNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    if(Copy_au8_CharacterCode)
    {   
        if(Copy_u8_PatternNumber <= LCD_CUSTOM_PATTERN_7)
        {

            u8 Local_u8_Counter = 0;
            
            //Choosing IR to send A command
            DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_LOW);
            
            switch (Copy_u8_PatternNumber)
            {
                //Setting the custom pattern base address in AC

                case LCD_CUSTOM_PATTERN_0:
                enu_PassByteAndLatch(LCD_CUSTOM_PATTERN_0_BASE_ADDRESS);
                break;
                
                case LCD_CUSTOM_PATTERN_1:
                enu_PassByteAndLatch(LCD_CUSTOM_PATTERN_1_BASE_ADDRESS);
                break;

                case LCD_CUSTOM_PATTERN_2:
                enu_PassByteAndLatch(LCD_CUSTOM_PATTERN_2_BASE_ADDRESS);
                break;           
                
                case LCD_CUSTOM_PATTERN_3:
                enu_PassByteAndLatch(LCD_CUSTOM_PATTERN_3_BASE_ADDRESS);
                break;           
                
                case LCD_CUSTOM_PATTERN_4:
                enu_PassByteAndLatch(LCD_CUSTOM_PATTERN_4_BASE_ADDRESS);
                break;           
                
                case LCD_CUSTOM_PATTERN_5:
                enu_PassByteAndLatch(LCD_CUSTOM_PATTERN_5_BASE_ADDRESS);
                break;           
                
                case LCD_CUSTOM_PATTERN_6:
                enu_PassByteAndLatch(LCD_CUSTOM_PATTERN_6_BASE_ADDRESS);
                break;           

                case LCD_CUSTOM_PATTERN_7:
                enu_PassByteAndLatch(LCD_CUSTOM_PATTERN_7_BASE_ADDRESS);
                break;           

                default:
                break;
            }

            //Choosing DR to send data
            DIO_enu_SetPinValue(LCD_RS_GROUP, LCD_RS_PIN, DIO_HIGH);

            for(Local_u8_Counter = 0; Local_u8_Counter < 8; Local_u8_Counter++)
            {
                enu_PassByteAndLatch(Copy_au8_CharacterCode[Local_u8_Counter]);
            }

            Local_u8_ErrorFlag = ES_OK;

        }
        else
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        }
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}

static ErrorState_t enu_ConvertDigitToASCII(u8 *Copy_u8_Digit)
{
    u8 Local_u8_ErorFlag = ES_NOK;

    if(Copy_u8_Digit)
    {
        if(((*Copy_u8_Digit >= 0) && (*Copy_u8_Digit <= 9)))
        {

            *Copy_u8_Digit = *Copy_u8_Digit + 48;
            Local_u8_ErorFlag = ES_OK;
        }
        else
        {
            Local_u8_ErorFlag = ES_OUT_OF_RANGE;
        }
    }
    else
    {
        Local_u8_ErorFlag = ES_NULL_POINTER;
    }


    return Local_u8_ErorFlag;
}

static ErrorState_t enu_ReverseInteger(u32* Copy_pu32_Num)
{
    //Must cast any to u32 when using this function

    u8 Local_u8_ErrorFlag = ES_OK;

    if(Copy_pu32_Num)
    {   
        u32 Local_u32_ReversedNum = 0;
        while(*Copy_pu32_Num)
        {
            Local_u32_ReversedNum = (Local_u32_ReversedNum*10) + (*Copy_pu32_Num % 10);
            *Copy_pu32_Num /= 10;
        }

        *Copy_pu32_Num = Local_u32_ReversedNum;

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}
