#ifndef DIO_PRIVATE_FILE
#define DIO_PRIVATE_FILE


//Registers' addresses
#define DIO_PORTA *(volatile u8*)(0x3B)
#define DIO_DDRA  *(volatile u8*)(0x3A)
#define DIO_PINA  *(volatile u8*)(0x39)

#define DIO_PORTB *(volatile u8*)(0x38)
#define DIO_DDRB  *(volatile u8*)(0x37)
#define DIO_PINB  *(volatile u8*)(0x36)

#define DIO_PORTC *(volatile u8*)(0x35)
#define DIO_DDRC  *(volatile u8*)(0x34)
#define DIO_PINC  *(volatile u8*)(0x33)

#define DIO_PORTD *(volatile u8*)(0x32)
#define DIO_DDRD  *(volatile u8*)(0x31)
#define DIO_PIND  *(volatile u8*)(0x30)


//Pin groups
#define DIO_PIN_GROUP_A   0
#define DIO_PIN_GROUP_B   1
#define DIO_PIN_GROUP_C   2
#define DIO_PIN_GROUP_D   3


//Pin Numbers
#define DIO_PIN_0         0
#define DIO_PIN_1         1
#define DIO_PIN_2         2
#define DIO_PIN_3         3
#define DIO_PIN_4         4
#define DIO_PIN_5         5
#define DIO_PIN_6         6
#define DIO_PIN_7         7


//Pin Directions
#define DIO_PIN_READ      0
#define DIO_PIN_WRITE     1

//Pull-up resistors state
#define DIO_FLOAT         0
#define DIO_PULL_UP       1

//Voltage Levels
#define DIO_LOW          0
#define DIO_HIGH          1


#endif
