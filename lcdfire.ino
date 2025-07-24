#define fire A3
#include <LCD_I2C.h>
LCD_I2C lcd(0x27,16,2);
void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(fire,INPUT);
}
void loop() 
{
  int a=analogRead(fire);
  lcd.setCursor(0,0);
  lcd.print("fire value");
  lcd.setCursor(1,1);
  lcd.print(a);
delay(1000);
}