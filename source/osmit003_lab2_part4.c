/*   Author: Olivia Smith
 *   Partner: Pei Lin
 *   Lab Section: 022
 *   Assignment: Lab 2 Exercise 4
 *   Exercise Description: Challenge
 *       An amusement park kid ride cart has three seats, with 8-bit weight
 *       sensors connected to ports A, B, and C (measuring from 0-255 kilograms). 
 *       Set PD0 to 1 if the cart's total passenger weight exceeds the maximum 
 *       of 140 kg. Also, the cart must be balanced: Set port PD1 to 1 if the difference
 *       between A and C exceeds 80 kg. Can you also devise a way to inform the ride
 *       operator of the approximate weight using the remaining bits on D? 

 *   I acknowledge all content contained herein, excluding template or example
 *   code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
#define MAX_WEIGHT 140

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;

    unsigend char tmpD;
    unsigned char weight;
    unsigned char differenceAC;
    unsigned char shiftedWeight;

    while (1) {
        weight = PINA + PINB + PINC;
        differenceAC = (PINA > PINC) ? (PINA - PINC) : (PINC - PINA); // simplifies a possible messy comparison later
        shiftedWeight = weight >> 2;

        tmpD = 0x00;                   // initialize D as blank

        if (weight > MAX_WEIGHT) {
            tmpD = tmpD | 0x01;        // if weight exceeds limit, set PD0 = 1
        }

        if (differenceAC > 80) {
            tmpD = tmpD | 0x02;        // if the cart is not balanced, set PD1 = 1
        }

        tmpD = tmpD | (shiftedWeight << 2);    // display shifted weight in PD7-PD2

        // The approximate weight is obtained by multiplying the value on PD7-PD2 by 4.
        // The resulting weight will be within 3kg of the actual weight.

        PORTD = tmpD;
    }
    return 0;
}