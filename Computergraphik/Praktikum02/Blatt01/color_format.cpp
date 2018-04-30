#include "color_format.h"
#include <algorithm>
#include <math.h>

void RGB::setRGB(float red, float green, float blue) {
	r = red;
	g = green;
	b = blue;
}

void CMY::setCMY(float cyan, float magenta, float yellow) {
	c = cyan;
	m = magenta;
	y = yellow;
}

CMY RGBtoCMY(const RGB &rgb) {
	CMY cmy{ 1.0f - rgb.r, 1.0f - rgb.g, 1.0f - rgb.b };
	return cmy;
}

HSV RGBtoHSV(const RGB &rgb) {
	HSV hsv;
	float max = std::max(rgb.r, std::max(rgb.g, rgb.b));
	float min = std::min(rgb.r, std::min(rgb.g, rgb.b));
	float delta = max - min;

	float d = (rgb.r == max) ? rgb.g - rgb.b : ((rgb.b == max) ? rgb.r - rgb.g : rgb.b - rgb.r);
	float h = (rgb.r == max) ? 0 : ((rgb.b == max) ? 4 : 2);

	hsv.v = max;
	if (delta == 0) {
		hsv.h = 0;
		hsv.s = 0;
		return hsv;
	}

	if (max != 0) {
		hsv.h = 60 * (h + d / delta);
		hsv.h = (hsv.h < 0) ? hsv.h + 360 : hsv.h;
		hsv.s = delta / max;
	}
	else {
		hsv.h = 0.0f;
		hsv.s = 0.0f;
	}
	return hsv;
}

RGB CMYtoRGB(const CMY &cmy) {
	RGB rgb{ 1.0f - cmy.c , 1.0f - cmy.m, 1.0f - cmy.y };
	return rgb;
}

HSV CMYtoHSV(const CMY &cmy) {
	return RGBtoHSV(CMYtoRGB(cmy));
}

RGB HSVtoRGB(const HSV &hsv) {
	RGB rgb;
	float c = hsv.s * hsv.v;
	float x = c * (1 - fabs(((hsv.h / 60) % 2) - 1));
	float m = hsv.v - c;

	if (hsv.h < 60) {
		rgb.setRGB(c, x, 0.0f);
	} else if (hsv.h < 120) {
		rgb.setRGB(x, c, 0.0f);
	} else if (hsv.h < 180) {
		rgb.setRGB(0.0f, c, x);
	} else if (hsv.h < 240) {
		rgb.setRGB(0.0f, x, c);
	} else if (hsv.h < 300) {
		rgb.setRGB(x, 0.0f, c);
	} else if (hsv.h < 360) {
		rgb.setRGB(c, 0.0f, x);
	}

	rgb.setRGB(rgb.r + m, rgb.g + m, rgb.b + m);
	return rgb;
}

CMY HSVtoCMY(const HSV &hsv) {
	return RGBtoCMY(HSVtoRGB(hsv));
}