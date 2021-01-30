/*
 * DinRailMeter.cpp
 *
 *  Created on: 25.10.2017
 *      Author: Johannes
 */

#include "LCD3X16.h"

LCD3X16::LCD3X16()
{
}

void LCD3X16::init()
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
	waitfordisplay();
}

LCD3X16::~LCD3X16()
{
	// TODO Auto-generated destructor stub
}

void LCD3X16::waitfordisplay()
{
	unsigned long start = millis();
	while (millis() <= start + 50)
	{
	}
}

void LCD3X16::settext(int line, int position, String text)
{

	if (line == 1)
	{
		//TODO hier gehts weiter nur bei änderungen schreiben
		if (text != firstline || positionfirstline != position)
		{
			firstline = text;
			positionfirstline = position;
			newtext = true;
		}
	}
	if (line == 2)
	{

		if (text != secondline || positionsecondline != position)
		{
			secondline = text;
			positionsecondline = position;
			newtext = true;
		}
	}
	if (line == 3)
	{
		if (text != thirdline || positionthirdline != position)
		{
			thirdline = text;
			positionthirdline = position;
			newtext = true;
		}
	}
}

void LCD3X16::show()
{
	if (newtext)
	{
		clear();

		Wire.beginTransmission(0x3C);
		Wire.write(0x80);
		Wire.write(0x80 + positionfirstline); //Zeile1
		Wire.write(0x60);
		Wire.write(firstline.c_str());
		Wire.endTransmission();
		waitfordisplay();

		Wire.beginTransmission(0x3C);
		Wire.write(0x80);
		Wire.write(0x90 + positionsecondline); //Zeile2
		Wire.write(0x60);
		Wire.write(secondline.c_str());
		Wire.endTransmission();
		waitfordisplay();

		Wire.beginTransmission(0x3C);
		Wire.write(0x80);
		Wire.write(0xA0 + positionthirdline);
		Wire.write(0x60);
		Wire.write(thirdline.c_str());
		Wire.endTransmission();
		waitfordisplay();

		newtext = false;
	}
}

void LCD3X16::clear()
{
	Wire.beginTransmission(0x3C);
	Wire.write(0x00); // Kontrollbyte senden C0=0, RS=0, R/W=0, x xxxx
	Wire.write(0x01); // Return Home:   0 0 0 0 - 0 0 1 0     => 0x02
	Wire.endTransmission();
	waitfordisplay();
}

void LCD3X16::cleartext()
{
	firstline = "";
	positionfirstline = 0;
	secondline = "";
	positionsecondline = 0;
	thirdline = "";
	positionthirdline = 0;
	newtext = true;
}