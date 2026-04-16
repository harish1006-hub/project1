#include<LPC21xx.h>
#include"header.h"
#define LCD 0xff<0
#define RS 1<<8
#define E 1<<9
void lcd_init(void);
void lcd_command(unsigned char);
void lcd_data(unsigned char);

void lcd_init(void)
{
	IODIR0=LCD|RS|E;
	lcd_command(0x01);
	lcd_command(0x02);
	lcd_command(0x0c);
    lcd_command(0x038);
}
void lcd_command(unsigned char s)
{
    IOCLR0=LCD;
	IOSET0=s;
	IOCLR0=RS;
    IOSET0=E;
    delay_ms(2);
    IOCLR0=E;
}
void lcd_data(unsigned char dat)
{
IOCLR0=LCD;
IOSET0=dat;
IOSET0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;
}
