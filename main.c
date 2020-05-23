/*
 * File:   main.c
 * Author: Safaa
 *
 * Created on May 16, 2020, 9:32 AM
 */

#define F_CPU 8000000UL

#define SS      4
#define MOSI    5
#define MISO    6
#define SCK     7

#define btn0    0
#define btn1    1
#include <xc.h>
#include <avr/interrupt.h>
#include <util/delay.h>


unsigned char counter;

void SPI_Master_init() {
    // Data Direction Configuration
    DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK);
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0); // | (1 << SPIE);
}

void SPI_write(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}

//ISR(SPI_STC_vect) {
//    SPI_write(counter++);
//}

void btn_setup() {
    DDRC &= ~((1 << btn0) | (1 << btn1));
}

char isPressed(int pinNum) {
    if (PINC & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    SPI_Master_init();

    //    sei();


    while (1) {
//        if (isPressed(btn0)) {
//            SPI_write(7);
//        }
//        if (isPressed(btn1)) {
//            SPI_write(9);
//        }
        SPI_write(counter++);
    }

    return 0;
}
