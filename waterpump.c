#include<lpc21XX.h>
#include"delayheader.h"
#include"lcdstr_header.h"
#define sm_sensor 1<<11
#define sw 1<<12
#define dc_motor 1<<13
int main()
{
IODIR0=dc_motor;
lcd_init();
if(((IOPIN0>>sm_sensor)&1)==1)
{
lcd_command(0X80);
lcd_str("DRY");
lcd_command(0X80);
lcd_str("MOTOR ON");
IOSET0=dc_motor;
}
else
lcd_command(0X80);
lcd_str("WET");
lcd_command(0X80);
lcd_str("MOTOR OFF");
IOCLR0=dc_motor;
}

