#ifndef COR_H
#define COR_H

class Color
{
public:
	Color();
	Color(int re, int gr, int bl, int wh);
	int r, g, b, w;
};

class ColorInterval
{
public:
	Color med, std;
	void set_med(Color m);
	void set_std(Color s);
	int distance(Color c);
};

class TCS
{
private:
	int S2, S3, OUT;
	int sensor_number; // This only will be used if we want to save the calibration on the EEPROM
	void setColorInterval(ColorInterval c, int position);
public:
	ColorInterval c[4]; // black, white, blue, green;
	int identify_color(Color color_read);
	Color read();
	// void setPins(const int S2, const int S3, const int OUT, const int sensor_number);
	void setPins(const int S2, const int S3, const int OUT);
	void calibrate(const int cor);
	void getFromEEPROM(const int start);
	void saveToEEPROM(const int start);
	int WhatIsTheColor();
};


#endif