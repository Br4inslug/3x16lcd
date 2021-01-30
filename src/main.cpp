#include "Arduino.h"
#include <Wire.h>
#include <LCD3X16.h>

LCD3X16 lcd;

void setup()
{
  Serial.begin(115200);

  lcd.init();
}

void loop()
{

  lcd.settext(2, 2, "Hello World!");

  lcd.show();
}
