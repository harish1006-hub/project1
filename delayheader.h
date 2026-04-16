#include<LPC21xx.H>
void delay_second(unsigned int);
void delay_ms(unsigned int);
void delay_us(unsigned int);

void delay_second(unsigned int s)
{						  
T0PR=15000000-1;
T0TCR=0x01;
while(T0TC<s);
T0TCR=0x03;
T0TCR=0x00;
}


void delay_ms(unsigned int s)
{
T0PR=15000-1;
T0TCR=0X01;
while(T0TC<s);
T0TCR=0X03;
T0TCR=0X00;
}


void delay_us(unsigned int s)
{
T0PR=15-1;
T0TCR=0X01;
while(T0TC<s);
T0TCR=0X03;
T0TCR=0X00;
}

