// This C code was automatically generated by Aixt Project
// Device = PIC24FJ128GA010
// Board = Explorer 16
// Backend = c

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#define FCY 8000000UL
#pragma config POSCMOD = HS
#pragma config OSCIOFNC = OFF
#pragma config FCKSM = CSDCMD
#pragma config FNOSC = PRIPLL
#pragma config IESO = OFF
#pragma config WDTPS = PS32768
#pragma config FWPSA = PR128
#pragma config WINDIS = ON
#pragma config FWDTEN = OFF
#pragma config ICS = PGx2
#pragma config GWRP = OFF
#pragma config GCP = OFF
#pragma config JTAGEN = OFF
#define led3    A, 0	// Onboard LEDs
#define led4    A, 1
#define led5    A, 2
#define led6    A, 3
#define led7    A, 4
#define led8    A, 5
#define led9    A, 6
#define led10   A, 7
#define sw3     D, 6	// Onboard switchs
#define sw4     D, 13
#define sw5     A, 7
#define sw6     D, 7
#define pot     B, 5	// Onboard potentiometer
#include <libpic30.h>
#define time__sleep_ms(TIME)    __delay_ms(TIME)
#include <p24FJ128GA010.h>
#define pin__output		0
#define pin__input		1
#define a0      A, 0      // pin names
#define a1      A, 1
#define a2      A, 2
#define a3      A, 3
#define a4      A, 4
#define a5      A, 5
#define a6      A, 6
#define a7      A, 7
#define a9      A, 9
#define a10     A, 10
#define a14     A, 14
#define a15     A, 15
#define b0      B, 0
#define b1      B, 1
#define b2      B, 2
#define b3      B, 3
#define b4      B, 4
#define b5      B, 5
#define b6      B, 6
#define b7      B, 7
#define b8      B, 8
#define b9      B, 9
#define b10     B, 10
#define b11     B, 11
#define b12     B, 12
#define b13     B, 13
#define b14     B, 14
#define b15     B, 15
#define c1      C, 1
#define c2      C, 2
#define c3      C, 3
#define c4      C, 4
#define c12     C, 12
#define c13     C, 13
#define c14     C, 14
#define c15     C, 15
#define d0      D, 0
#define d1      D, 1
#define d2      D, 2
#define d3      D, 3
#define d4      D, 4
#define d5      D, 5
#define d6      D, 6
#define d7      D, 7
#define d8      D, 8
#define d9      D, 9
#define d10     D, 10
#define d11     D, 11
#define d12     D, 12
#define d13     D, 13
#define d14     D, 14
#define d15     D, 15
#define e0      E, 0
#define e1      E, 1
#define e2      E, 2
#define e3      E, 3
#define e4      E, 4
#define e5      E, 5
#define e6      E, 6
#define e7      E, 7
#define e8      E, 8
#define e9      E, 9
#define f0      F, 0
#define f1      F, 1
#define f2      F, 2
#define f3      F, 3
#define f4      F, 4
#define f5      F, 5
#define f6      F, 6
#define f7      F, 7
#define f8      F, 8
#define f12     F, 12
#define f13     F, 13
#define g0      G, 0
#define g1      G, 1
#define g2      G, 2
#define g3      G, 3
#define g6      G, 6
#define g7      G, 7
#define g8      G, 8
#define g9      G, 9
#define g12     G, 12
#define g13     G, 13
#define g14     G, 14
#define g15     G, 15
#define pin__write_(PORT_NAME, PIN, VALUE)   LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = VALUE
#define pin__write(PIN_NAME, VALUE)  pin__write_(PIN_NAME, VALUE)
#define pin__high_(PORT_NAME, PIN)   LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = 1
#define pin__high(PIN_NAME)  pin__high_(PIN_NAME)
#define pin__setup_(PORT_NAME, PIN, MODE)   TRIS ## PORT_NAME ## bits.TRIS ## PORT_NAME ## PIN = MODE
#define pin__setup(PIN_NAME, PIN_MODE)  pin__setup_(PIN_NAME, PIN_MODE)
#define pin__read_(PORT_NAME, PIN)	PORT ## PORT_NAME ## bits.PORT ## PORT_NAME ## PIN
#define pin__read(PIN_NAME)  pin__read_(PIN_NAME)
#define pin__low_(PORT_NAME, PIN)   LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = 1
#define pin__low(PIN_NAME)  pin__low_(PIN_NAME)

void main__init();

void time__init();

void pin__init();

void main__init() {
	AD1PCFG = 0xFFDF;
	AD1CSSL = 0;
	AD1CON2 = 0;
	AD1CON3 = 0x1F02;
	AD1CON1bits.ADON = 1;
	TRISA = 0xff00;
	TRISDbits.TRISD6 = 1;
	TRISDbits.TRISD13 = 1;
	TRISDbits.TRISD7 = 1;
	TRISBbits.TRISB5 = 1;
	time__init();
	pin__init();
	
}

void time__init() {
}

void pin__init() {
}
const int32_t t1 = 500;

int main(void ) {
	main__init();
	pin__setup(a0, pin__output);
	while(true) {
		pin__high(a0);
		time__sleep_ms(t1);
		pin__low(a0);
		time__sleep_ms(t1);
	}
	return 0;
}
