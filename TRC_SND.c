/*****************************************************
Project : TRC101 Передатчик
Date    :
Author  : К. Гурашкин

Chip type           : ATmega16
Clock frequency     : 4,000000 MHz
*****************************************************/

#include <mega16.h>
#include <delay.h>
#include <trc.h>

#define LEDDDR  DDRA
#define LEDPIN  0
#define LEDOFF() PORTA |=  (1<<(0))
#define LEDON()  PORTA &= ~(1<<(0))




void main(void)
{

    char cString1[]= "-= DieHard =-";
    char cString2[]= "- BoogieMan -";
    char cString3[]= "TheIceFantasy";
    
    char i=0;
    LEDDDR = (1<<LEDPIN);


    LEDON();
    TrcPortInit();
    TrcInitSnd();
    LEDOFF();
    delay_ms(1000);
    
    while (1)
    {
        for(i=0;i<3;i++)
        {
            LEDON();
            if(i==0)  TrcSendPocket(cString1, 13);  // Отправить пакет байт
            if(i==1)  TrcSendPocket(cString2, 13);  // Отправить пакет байт
            if(i==2)  TrcSendPocket(cString3, 13);  // Отправить пакет байт
            LEDOFF();
            delay_ms(4000);
        }

    };
}