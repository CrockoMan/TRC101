/*****************************************************
Project : TRC101 Приемник
Version : 
Date    :
Author  : 

Chip type           : ATmega16
Clock frequency     : 4,000000 MHz
*****************************************************/

#include <mega16.h>
#include <delay.h>
#include <string.h>
#include <trc.h>


#asm
   .equ __lcd_port=0x15 ;PORTC
#endasm
#include <lcd.h>



#define LEDDDR  DDRA
#define LEDOFF() PORTA |=  (1<<3)
#define LEDON()  PORTA &= ~(1<<3)

#define LED2OFF() PORTA |=  (1<<(1))
#define LED2ON()  PORTA &= ~(1<<(1))


 



void main(void)
{
    unsigned char cData[20], cTmp[]="-= DieHard =-", i;
    DDRA = (1<<1) |  (1<<3);

    LED2OFF();
    TrcPortInit();
    TrcInitRcv();
    FIFOReset();
    
    lcd_init(16);
    _lcd_write_data(0x2A);
    
    LEDOFF();

    while (1)
        {
            GetTRCPoket(cData,13);
            LEDON();
            delay_ms(50);
            LEDOFF();
            cData[13]=0;
            
            lcd_clear();
            lcd_puts(cData);

            if(strcmp(cData,cTmp)==0);
            {
                LED2ON();
                delay_ms(100);
                LED2OFF();
            }
            for(i=0; i<20; i++)   cData[i]=0;

            
            delay_ms(400);
            lcd_clear();
            lcd_gotoxy(0,0);


            delay_ms(5);
            FIFOReset();
            LEDOFF();
            LED2OFF();
        };
}
