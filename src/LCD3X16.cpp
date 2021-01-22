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
	// lcd_init()

	delay(100);
	Wire.beginTransmission(0x3C);
	Wire.write(0x00);
	Wire.write(0x38);

	Wire.write(0x00);
	Wire.write(0x39);
	Wire.write(0x00);

	Wire.write(0x06);
	Wire.write(0x00);

	Wire.write(0x15); //15
	Wire.write(0x00);

	Wire.write(0x72);
	Wire.write(0x00);

	Wire.write(0x56);
	Wire.write(0x00);

	Wire.write(0x6C);
	Wire.write(0x00);

	Wire.write(0x0C);
	Wire.write(0x00);

	Wire.write(0x01);
	Wire.write(0x00);

	Wire.write(0x38);
	Wire.write(0x00);

	Wire.write(0x48);
	Wire.write(0x00);

	Wire.endTransmission();

delay(100);

}

LCD3X16::~LCD3X16()
{
	// TODO Auto-generated destructor stub
}

void LCD3X16::settext(int line, String text)
{
	if (line == 1)
	{
		firstline = text;
		for (int i = 0; i < 16 - text.length(); i++)
		{
			firstline += " ";
		}
	}
	if (line == 2)
	{
		secondline = text;
		for (int i = 0; i < 16 - text.length(); i++)
		{
			secondline += " ";
		}
	}
	if (line == 3)
	{
		thirdline = text;
		for (int i = 0; i < 16 - text.length(); i++)
		{
			thirdline += " ";
		}
	}
}

void LCD3X16::show()
{
	Wire.beginTransmission(0x3C);
	Wire.write(0x40);
	const char *first = firstline.c_str();
	Wire.write(first);

	Wire.endTransmission();

	Wire.beginTransmission(0x3C);
	Wire.write(0x40);
	const char *second = secondline.c_str();
	Wire.write(second);

	Wire.endTransmission();

	Wire.beginTransmission(0x3C);
	Wire.write(0x40);
	const char *third = thirdline.c_str();
	Wire.write(third);

	Wire.endTransmission();
}

void LCD3X16::clear()
{
	Wire.beginTransmission(0x3C);
	Wire.write(0x01);
	
	Wire.endTransmission();
	/*
	Wire.beginTransmission(0x3C);
	Wire.write(0x40);
	Wire.write("                ");
	Wire.endTransmission();

	Wire.beginTransmission(0x3C);
	Wire.write(0x40);
	Wire.write("                ");
	Wire.endTransmission();

	Wire.beginTransmission(0x3C);
	Wire.write(0x40);
	Wire.write("                ");
	Wire.endTransmission();
*/
}
