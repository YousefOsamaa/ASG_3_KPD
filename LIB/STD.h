
#ifndef STD_FILE
#define STD_FILE


/*typedef <dataType> <newName>*/

typedef unsigned char         u8 ;
typedef unsigned short int    u16;
typedef unsigned long int     u32;
typedef unsigned long long    u64;
typedef signed char           s8 ;
typedef signed short int      s16;
typedef signed long int       s32;
typedef signed long long      s64;
typedef float                 f32;
typedef double                f64;
typedef long double           f80;

#define NULL			((void*)0)

typedef enum {False, True} Bool;
typedef enum {STD_DECIMAL_BASE = 10, STD_HEXADECIMAL_BASE = 16, STD_OCTADECIMAL_BASE = 8, STD_BINARY_BASE = 2}Base;

#endif
