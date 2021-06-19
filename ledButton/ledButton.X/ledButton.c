/*
 * File:   ledButton.c
 * Author: valmy
 *
 * Created on 19 de Junho de 2021, 13:18
 */

#define F_CPU 16000000L
//#define true 1
//#define false 0
#include <avr/io.h>
#include<stdbool.h>
#include<util/delay.h>
#define and &&
#define or ||
#define digitalWriteHIGH(n) PORTB |= (1 << n)
#define digitalWriteLOW(n) PORTB &= ~(1 << n)
#define digitalRead(n) PINB & (1 << n)
#define botao1 0x00
#define botao2 0x01
#define led 0x02
bool pressionadoBotao1 = false;
bool pressionadoBotao2 = false;
int main(void) {
    DDRB =  0b00000100;
    MCUCR = 0b00000001;
    PORTB = 0b00000000;
    while (true) {
        if(digitalRead(botao1)){
            _delay_ms(10);
            pressionadoBotao1 = true;
        }
        if(pressionadoBotao1 and !(digitalRead(botao1))){
            digitalWriteHIGH(led);
            pressionadoBotao1 = false;
        }
        if(digitalRead(botao2)){
            _delay_ms(10);
            pressionadoBotao2 = true;
        }
        if(pressionadoBotao2 and !(digitalRead(botao2))){
            digitalWriteLOW(led);
            pressionadoBotao2 = false;
        }

    }
}
