/*
 * File:   interrupcoesBotoes.c
 * Author: valmy
 *
 * Created on 19 de Junho de 2021, 19:38
 */
#define F_CPU 16000000L
#include<avr/io.h>
#include<stdbool.h>
#include<util/delay.h>
#include<avr/interrupt.h> //macros
#define LOW 0
#define HIGH 1
#define INPUT 0
#define OUTOUT 1
#define digitalWrite(PIN,PORT,WRITE) WRITE ? (!PORT) ? (PORTB |= (1 << PIN)) : (PORTD |= (1 << PIN)) : !PORT ? (PORTB &= ~(1 << PIN)):(PORTD&= ~(1 << PIN))
#define digitalRead(PIN,PORT)  (!PORT) ? PINB & (1 << PIN)  : PIND & (1 << PIN)
#define setAllBits(PIN,PORT)   (!PORT) ? PORTB = PIN : PORTD = PIN
#define resetAllBits(PIN,PORT) (!PORT) ? PORTB = 0x00: PORTD = 0x00
enum PORTS{B,D};
ISR(PCINT1_vect);
#define led1 0x00
#define led2 0x01
int main(){
    DDRB   = 0xFF;
    PORTB  = 0x00;
    DDRD   = 0x00;
    PORTD  = 0x00;
    
    PCICR  = 0b00000100;//PINT2
    PCMSK2 = 0b00001100;//PD2 e PD3
    sei();//chaver mestrer de controle de interrupções
    while(true);
}
ISR(PCINT2_vect){
    if(digitalRead(2,D)){
        digitalWrite(led1,B,HIGH);
    }
    if(digitalRead(3,D)){
        digitalWrite(led1,B,LOW);
    }
}