/*
 * LCD3X16.h
 *
 *  Created on: 25.10.2017
 *      Author: Johannes
 */
#include "Arduino.h"
#include "Wire.h"
//#include <ESP8266WiFi.h>


#ifndef LCD3X16_H_
#define LCD3X16_H_

class LCD3X16
{
public:
	
	LCD3X16();
	virtual ~LCD3X16();
	void init();
	void settext(int line,String text);
	void show();
	void clear();

private:
String firstline="                ";
String secondline="                ";
String thirdline="                ";


};

#endif /* LCD3X16 */
