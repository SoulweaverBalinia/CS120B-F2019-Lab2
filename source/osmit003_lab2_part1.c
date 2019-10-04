/*   Author: Olivia Smith
 *   Partner: Pei Lin
 *   Lab Section: 022
 *   Assignment: Lab 2 Exercise 1
 *   Exercise Description: Garage open at night
 *       A garage door sensor connects to PA0 (1 means door open), and a light sensor
 *       connects to PA1 (1 means light is sensed). Write a program that illuminates
 *       an LED connected to PB0 (1 means illuminate) if the garage door is open at night.
 *
 *   I acknowledge all content contained herein, excluding template or example
 *   code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

typedef enum bool {false, true};

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    bool garageDoorOpen;
    bool night;

    while (1) {
        garageDoorOpen = ((PINA & 0x01) == 0x01) ? true : false; // if PA0 is 1, garage door is open
        night = ((PINA & 0x02) == 0x02) ? false : true;          // if PA1 is 0, it is night

        if (garageDoorOpen && night) {
            PORTB = 0x01;    // lights up PB0 if garage door is open and it is night
        } else {
            PORTB = 0x00;    // PB0 is off otherwise
        }
    }
    return 0;
}