#ifndef EXTI_CONFIG_FILE
#define EXTI_CONFIG_FILE



#define EXTI_INT_COUNT  1

typedef struct 
{
    u8 INTNumber;
    u8 INTMode;
    u8 INTSenseLevel;
}EXTI_t;

#endif