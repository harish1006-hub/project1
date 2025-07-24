#define fire A4
#include <LCD_I2C.h>
LCD_I2C lcd(0x27,16,2);
void setup()
{
  Serial.begin(9600);
  pinMode(fire,INPUT);
  lcd.begin();
  lcd.backlight();

}
void loop()
{
  int a=analogRead(fire);
  lcd.setCursor(0,0);
  lcd.print("fire");
  lcd.setCursor(1,1);
  lcd.print(a);
  delay(1000);

}