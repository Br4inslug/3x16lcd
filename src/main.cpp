#include "Arduino.h"
#include <Wire.h>
#include <LCD3X16.h>

// Hinweis:   max. 32Byte, dann muss die Transmission beendet werden !!
int i = 0;
int y = 1;
LCD3X16 lcd;
unsigned long start = 0;

void LCD_Test1(String word)
{

  Wire.beginTransmission(0x3C);
  Wire.write(0x80);
  //Wire.write (0x85); //Zeile1
  Wire.write(0x90); //Zeile2
  //Wire.write(0xA2); //Zeile3
  Wire.write(0x60);

  Wire.write(word.c_str());

  Wire.endTransmission();
  unsigned long start = millis();
  while (millis() <= start + 30)
  {
  }
}

void setup()
{
  Serial.begin(115200);

  //delay(1000);

  lcd.init();

  //delay(1000);
  //LCD_Test1("Test123!");
}

void loop()
{

  if (millis() >= start + 400)
  {
    i++;
    
    if (i >= 13)
    {
      i = 0;
      y++;
      if (y >= 4)
      {
        y = 1;
      }
    }

    lcd.cleartext();
    lcd.settext(y, i, "test");
    start = millis();
  }

  //delay(100);
  //String is=String(i);
  lcd.show();
  //  delay(1000);
  //clear_display();
}
