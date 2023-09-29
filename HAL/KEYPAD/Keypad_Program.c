#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

#include "Keypad_Config.h"
#include "Keypad_Private.h"



typedef struct 
{
    u8 Switch_Group;
    u8 Switch_Pin;

}Switch_t;

Switch_t Keypad_au8_Rows [KEYPAD_ROWS_MAX_NUMBER] = { {KEYPAD_R0_GROUP,KEYPAD_R0_PIN}, 
                                                      {KEYPAD_R1_GROUP,KEYPAD_R1_PIN},
                                                      {KEYPAD_R2_GROUP,KEYPAD_R2_PIN},
                                                      {KEYPAD_R3_GROUP,KEYPAD_R3_PIN}};

Switch_t Keypad_au8_Columns [KEYPAD_COLUMNS_MAX_NUMBER] = { {KEYPAD_C0_GROUP,KEYPAD_C0_PIN}, 
                                                         {KEYPAD_C1_GROUP,KEYPAD_C1_PIN},
                                                         {KEYPAD_C2_GROUP,KEYPAD_C2_PIN},
                                                         {KEYPAD_C3_GROUP,KEYPAD_C3_PIN}};

extern ErrorState_t Keypad_enu_Initialization(void)
{   
    u8 Local_u8_ErrorFlag = ES_NOK;
    
     
    #if (KEYPAD_ROWS_NUMBER >= 1 && KEYPAD_ROWS_NUMBER <= KEYPAD_ROWS_MAX_NUMBER) && (KEYPAD_COLUMNS_NUMBER >= 1 && KEYPAD_COLUMNS_NUMBER <= KEYPAD_COLUMNS_MAX_NUMBER ) 
        u8 Local_u8_Counter = 0;
        
        for(Local_u8_Counter =0; Local_u8_Counter < KEYPAD_ROWS_NUMBER; Local_u8_Counter++)
        {
            DIO_enu_SetPinDiretion(Keypad_au8_Rows[Local_u8_Counter].Switch_Group,Keypad_au8_Rows[Local_u8_Counter].Switch_Pin,DIO_PIN_READ);
            DIO_enu_SetPinState(Keypad_au8_Rows[Local_u8_Counter].Switch_Group,Keypad_au8_Rows[Local_u8_Counter].Switch_Pin,DIO_PULL_UP);
        }
        
        for(Local_u8_Counter =0; Local_u8_Counter < KEYPAD_COLUMNS_NUMBER; Local_u8_Counter++)
        {
            DIO_enu_SetPinDiretion(Keypad_au8_Columns[Local_u8_Counter].Switch_Group,Keypad_au8_Columns[Local_u8_Counter].Switch_Pin,DIO_PIN_WRITE);
            DIO_enu_SetPinState(Keypad_au8_Columns[Local_u8_Counter].Switch_Group,Keypad_au8_Columns[Local_u8_Counter].Switch_Pin,DIO_LOW);
        }
        
        Local_u8_ErrorFlag = ES_OK;
    #else

        #error "Maximum number or rows or columns is exceeded"
    #endif

    return Local_u8_ErrorFlag;

}

extern ErrorState_t Keypad_enu_GetButtonPressedValue(u8* Copy_pu8_ButtonValue)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    if(Copy_pu8_ButtonValue)
    {
        u8 Local_u8_RowCounter = 0;
        u8 Local_u8_ColumnCounter = 0;
        
        u8 Local_u8_RowValue;
        Bool Local_bool_FoundFlag = False;

        *Copy_pu8_ButtonValue = KEYPAD_NOT_PRESSED_VALUE;
        

        for(Local_u8_RowCounter = 0; Local_u8_RowCounter < KEYPAD_ROWS_NUMBER; Local_u8_RowCounter++)
        {
            //scanning the rows for any closed switches
            DIO_enu_GetPinValue(Keypad_au8_Rows[Local_u8_RowCounter].Switch_Group,Keypad_au8_Rows[Local_u8_RowCounter].Switch_Pin,&Local_u8_RowValue);   
            
            if(Local_u8_RowValue == DIO_LOW)
            {
                _delay_ms(3);
                //scanning the rows for any closed switches
                DIO_enu_GetPinValue(Keypad_au8_Rows[Local_u8_RowCounter].Switch_Group,Keypad_au8_Rows[Local_u8_RowCounter].Switch_Pin,&Local_u8_RowValue);   
                
                if(Local_u8_RowValue == DIO_LOW)
                {

                    for(Local_u8_ColumnCounter =0; Local_u8_ColumnCounter < KEYPAD_COLUMNS_NUMBER; Local_u8_ColumnCounter++)
                    {
                        //Placing a high signal on the column 
                        DIO_enu_SetPinValue(Keypad_au8_Columns[Local_u8_ColumnCounter].Switch_Group,Keypad_au8_Columns[Local_u8_ColumnCounter].Switch_Pin,DIO_HIGH);

                        //getting the value of the row 
                        DIO_enu_GetPinValue(Keypad_au8_Rows[Local_u8_RowCounter].Switch_Group,Keypad_au8_Rows[Local_u8_RowCounter].Switch_Pin,&Local_u8_RowValue);

                        if(Local_u8_RowValue == DIO_HIGH)
                        {
                            //Creating 2D array
                            u8 Keypad_au8_KeyadValues [KEYPAD_ROWS_NUMBER][KEYPAD_COLUMNS_NUMBER] = KEYPAD_KEY_VALUES;
                            
                            //Placing key Value in button
                            *Copy_pu8_ButtonValue = Keypad_au8_KeyadValues[Local_u8_RowCounter][Local_u8_ColumnCounter];
                            
                            //Setting Found flag to break the row loop
                            Local_bool_FoundFlag = True;

                            Local_u8_ErrorFlag = ES_OK;

                            //Clearing the high signal placed on the column
                            DIO_enu_SetPinValue(Keypad_au8_Columns[Local_u8_ColumnCounter].Switch_Group,Keypad_au8_Columns[Local_u8_ColumnCounter].Switch_Pin,DIO_LOW);
                        
                            // //Getting the value of the row 
                            // DIO_enu_GetPinValue(Keypad_au8_Rows[Local_u8_RowCounter].Switch_Group,Keypad_au8_Rows[Local_u8_RowCounter].Switch_Pin,&Local_u8_RowValue);
                            
                            // //Blocking th microcontroller until the Row returns to high again which means that the button is released
                            // while(!Local_u8_RowValue)
                            // {
                            //     //Getting the value of the row 
                            //     DIO_enu_GetPinValue(Keypad_au8_Rows[Local_u8_RowCounter].Switch_Group,Keypad_au8_Rows[Local_u8_RowCounter].Switch_Pin,&Local_u8_RowValue);
                                
                            // } --< TO BE IMPELEMNTED AS AN APPLICATION
                            
                            
                            //Breaking the column loop 
                            break;

                            

                        }
                    
                        //Clearing the high signal placed on the column
                        DIO_enu_SetPinValue(Keypad_au8_Columns[Local_u8_ColumnCounter].Switch_Group,Keypad_au8_Columns[Local_u8_ColumnCounter].Switch_Pin,DIO_LOW);
                    }

                }
                
            }

            if(Local_bool_FoundFlag)
            {
                //Breaking the row loop 
                
                break;
            }
        }

    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }


    return Local_u8_ErrorFlag;

}
