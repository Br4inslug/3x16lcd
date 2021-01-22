#include "Arduino.h"
#include <Wire.h>
// Hinweis:   max. 32Byte, dann muss die Transmission beendet werden !!
int i=0;
void LCD_Init()
{

  Wire.begin();
  Wire.beginTransmission(0x3C);
  Wire.write(0x00);
  Wire.write(0x38);
  Wire.write(0x39);
  Wire.write(0x06);
  Wire.write(0x15); //15
  Wire.write(0x72); // contrast 72 dunkel  78 hell
  Wire.write(0x57); //56  5V   57  3.3V
  Wire.write(0x6C);
  Wire.write(0x0C);
  Wire.write(0x01);
  Wire.write(0x38);
  Wire.write(0x48);
  Wire.endTransmission();
  delay(10);
}

void clear_display()
{
  Wire.beginTransmission(0x3C);
  Wire.write(0x00); // Kontrollbyte senden C0=0, RS=0, R/W=0, x xxxx
  Wire.write(0x01); // Return Home:   0 0 0 0 - 0 0 1 0     => 0x02
  Wire.endTransmission();
}

void LCD_Test1(String word)
{

  Wire.beginTransmission(0x3C);
  Wire.write(0x80);
  //Wire.write (0x85); //Zeile1
  //Wire.write (0x90); //Zeile2
  Wire.write(0xA2); //Zeile3
  Wire.write(0x60);

  Wire.write(word.c_str());

  Wire.endTransmission();
  delay(10);
}

void setup()
{
  Serial.begin(115200);

  //delay(1000);

  LCD_Init();

  //delay(1000);
}

void loop()
{


  //delay(100);
  String is=String(i);
  LCD_Test1(is);
 //  delay(1000);
  //clear_display();
i++;
}
