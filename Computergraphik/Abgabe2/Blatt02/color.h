#pragma once
struct RGB {
	float r;
	float g;
	float b;
};

struct CMY {
	float c;
	float m;
	float y;
};

struct HSV {
	float h;
	float s;
	float v;
};

CMY RGBtoCMY(RGB &rgb);

HSV RGBtoHSV(RGB &rgb);

RGB CMYtoRGB(CMY &cmy);

HSV CMYtoHSV(CMY &cmy);

RGB HSVtoRGB(HSV &hsv);

CMY HSVtoCMY(HSV &hsv);