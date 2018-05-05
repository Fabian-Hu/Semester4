#include "color.h"
#include <algorithm>
#include <math.h>

// RGB
// Quelle: https://www.sofatutor.com/naturwissenschaften-und-mathematik/videos/teil-19-subtraktive-farbmischung-3-umwandlung-rgb-cmy-cmyk
CMY RGBtoCMY(RGB &rgb) {
	CMY cmy{ 1.0f - rgb.r, 1.0f - rgb.g, 1.0f - rgb.b };
	return cmy;
}

// Quelle: https://wisotop.de/rgb-nach-hsv.php
HSV RGBtoHSV(RGB &rgb) {
	HSV hsv;
	float h, s, v;
	float max = std::max(rgb.r, std::max(rgb.g, rgb.b));
	float min = std::min(rgb.r, std::min(rgb.g, rgb.b));
	float mittel = max - min;

	hsv.v = max;
		if (max != 0) hsv.s = mittel / max;
		else {
			hsv.s = 0;
			hsv.h = -1;
			return hsv;
		}

		if (max == min) {
			hsv.s = 0;
			hsv.h = 0;
			return hsv;
		}

		if (rgb.r == max)
			hsv.h = (rgb.g - rgb.b) / mittel;
		else if (rgb.g == max)
			hsv.h = 2 + (rgb.b - rgb.r) / mittel;
		else {
			hsv.h = 4 + (rgb.r - rgb.g) / mittel;
			hsv.h *= 60;
		}

		if (hsv.h < 0)
			hsv.h += 360;

		return hsv;
}

// CMY
RGB CMYtoRGB(CMY &cmy) {
	RGB rgb{ 1.0f - cmy.c , 1.0f - cmy.m, 1.0f - cmy.y };
	return rgb;
}

HSV CMYtoHSV(CMY &cmy) {
	return RGBtoHSV(CMYtoRGB(cmy));
}

// HSV
CMY HSVtoCMY(HSV &hsv) {
	return RGBtoCMY(HSVtoRGB(hsv));
}

RGB HSVtoRGB(HSV &hsv) {
	RGB rgb;
	int i;
	float f, p, q, t;
	if (hsv.s == 0) {
		rgb.r = hsv.v;
		rgb.g = hsv.v;
		rgb.b = hsv.v;
		return rgb;
	}
	hsv.h /= 60;
	i = floor(hsv.h); // abrunden
	f = hsv.h - i;
	p = hsv.v * (1 - hsv.s);
	q = hsv.v * (1 - hsv.s * f);
	t = hsv.v * (1 - hsv.s * (1 - f));
	switch (i) {
	case 0:
		rgb.r = hsv.v;
		rgb.g = t;
		rgb.b = p;
		break;
	case 1:
		rgb.r = q;
		rgb.g = hsv.v;
		rgb.b = p;
		break;
	case 2:
		rgb.r = p;
		rgb.g = hsv.v;
		rgb.b = t;
		break;
	case 3:
		rgb.r = p;
		rgb.g = q;
		rgb.b = hsv.v;
		break;
	case 4:
		rgb.r = t;
		rgb.g = p;
		rgb.b = hsv.v;
		break;
	default:  // case 5:
		rgb.r = hsv.v;
		rgb.g = p;
		rgb.b = q;
		break;
	}


	return rgb;
}