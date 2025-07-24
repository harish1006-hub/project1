#include <LCD_I2C.h>
LCD_I2C lcd(0x27,16,2);
void setup()
{
  lcd.begin();
  lcd.backlight();

}
void loop()
{
  lcd.setCursor(0,0);
  lcd.scrollDisplayLeft();
  delay(200);
  lcd.print("mano");
  lcd.setCursor(1,1);
  lcd.print("Is a good boy");
  lcd.scrollDisplayLeft();
  delay(200);
}