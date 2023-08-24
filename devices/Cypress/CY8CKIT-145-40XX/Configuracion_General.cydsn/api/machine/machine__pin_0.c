// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Javier León, Camilo Lucas & Fernando Martínez Santa

enum PIN_NAMES {
    led1 = 0,    
    led4,
    led5,
    led6,
    led7,
    led8,
    led9,
    led10,
    led11,
    do0,
    do1,
    do2,
    di0,
    di1,    
    di2,        
};

// void pin_high(pins PIN) {   
//     *((int)(PIN/16)*3 + &LATA)  |=   0x0001<<(PIN%16);
// }

// void pin_low(pins PIN) {    
//     *((int)(PIN/16)*3 + &LATA)  &= ~(0x0001<<(PIN%16));
// }

void pin_write(pin_name PIN_NAMES, int VAL) {  
    addr = (int)(PIN/16)*3 + &LATA;
    port_bit = PIN % 16;
    *addr &= (~((0x0001)<<port_bit));
    *addr |= (VAL<<port_bit);  
}

// void pin_read(pins PIN) {   
//     ((*((int)(PIN/16)*3 + &PORTA) >> (PIN%16)) & 0x0001);
// }