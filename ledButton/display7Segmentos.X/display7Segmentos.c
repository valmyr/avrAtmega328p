/* 
 * File:   display7Segmentos.c contador 0 - 9
 * Author: valmy
 *
 * Created on 19 de Junho de 2021, 16:40
 * 
 */
#define F_CPU 16000000L
#include<stdbool.h>
#include<avr/io.h>
#include<util/delay.h>
enum PORTS{B,C,D};
#define digitalWrite(PIN,INOUT,PORT) (PORT == 0) ? (INOUT ? PORTB |= (1 << PIN)) : (PORTC &= ~(1 << PIN): INOUT ? PORTC |= (1 << PIN))
#define digitalRead(PIN,PORT) (PORT == 0) ? (PINB & (1 << PIN)) : (PINC & (1 << PIN))
#define setAllBits(bit,PORT) (PORT == 0) ? (PORTB = bit) : (PORTC = bit)
#define and &&
#define botao1 0x00
#define botao2 0x00
char coderBCD [] = {
            //gfed cba 
    0xFD,//0b 1111 1100,0
    0x60,//0b 0110 0000,1
    0xDA,//0b 1101 1010,2
    0xF2,//0b 1111 0010,3
    0x66,//0b 0110 0110,4 
    0xB6,//0b 1011 0110,5 
    0xBE,//0b 1011 1110,6 
    0xE0,//0b 1110 0000,7 
    0xFE,//0b 1111 1110,8 
    0xF6,//0b 1111 0110,9 
};
char flagPressionado1 = false;
char flagPressionado2 = false;
int contador = 0;
int main(){
    DDRB  = 0xFE;//0xFE; //0b1111 1110
    DDRC  = 0x00;
    PORTC = 0x00;
    PORTB = 0x00;
    MCUCR = 0x00;
    while(true){
        if(digitalRead(botao1,B)){
            _delay_ms(5);
            flagPressionado1 = true;
        }else if(!(digitalRead(botao1,B)) and flagPressionado1){
            flagPressionado1 = false;
            contador++;
        }
        if(digitalRead(botao2,C)){
            _delay_ms(5);
            flagPressionado2 = true;
        }else if(!(digitalRead(botao2,C)) and flagPressionado2){
            flagPressionado2 = false;
            contador--;
        }
        if(contador > 9)contador = 0;
        if(contador < 0)contador = 9;
        setAllBits(coderBCD[contador],B);
        
    }
}