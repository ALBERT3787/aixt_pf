// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Pin management functions
//              (Explorer16-PIC24 port)
#include <p24FJ128GA010.h>

#define out 0   // pin direction
#define in  1

unsigned int *__addr;          //PORT address pointer
unsigned int __port_bit;     //specific bit of PORT

#define pin_mode(PIN,TYPE)   \
    __addr = (int)(PIN/16)*3 + &TRISA; \
    __port_bit = PIN%16; \
    if(TYPE==in) *__addr |=   0x0001<<__port_bit; \
    else         *__addr &= ~(0x0001<<__port_bit)

#define pin_high(PIN)    \
    *((int)(PIN/16)*3 + &LATA)  |=   0x0001<<(PIN%16)

#define pin_low(PIN)     \
    *((int)(PIN/16)*3 + &LATA)  &= ~(0x0001<<(PIN%16))

#define pin_write(PIN,VAL)   \
    __addr = (int)(PIN/16)*3 + &LATA; \
    __port_bit = PIN%16; \
    *__addr &= (~((0x0001)<<__port_bit)); \
    *__addr |= (VAL<<__port_bit)  

#define pin_read(PIN)    \
    ((*((int)(PIN/16)*3 + &PORTA) >> (PIN%16)) & 0x0001)


// void pin_mode(unsigned int PIN, unsigned int TYPE) { 
//     __addr = (int)(PIN/16)*3 + &TRISA;
//     __port_bit = PIN%16;
//     if(TYPE==in) *__addr |=   0x0001<<__port_bit;
//     else         *__addr &= ~(0x0001<<__port_bit);
// }

// void pin_high(unsigned int PIN) {   
//     *((int)(PIN/16)*3 + &LATA)  |=   0x0001<<(PIN%16);
// }

// void pin_low(unsigned int PIN) {    
//     *((int)(PIN/16)*3 + &LATA)  &= ~(0x0001<<(PIN%16));
// }

// void pin_write(unsigned int PIN, unsigned int VAL) {  
//     __addr = (int)(PIN/16)*3 + &LATA;
//     __port_bit = PIN % 16;
//     *__addr &= (~((0x0001)<<__port_bit));
//     *__addr |= (VAL<<__port_bit);  
// }

// void pin_read(unsigned int PIN) {   
//     ((*((int)(PIN/16)*3 + &PORTA) >> (PIN%16)) & 0x0001);
// }