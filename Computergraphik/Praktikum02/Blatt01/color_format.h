
struct RGB {
	float r;
	float g;
	float b;
	void setRGB(float red, float green, float blue);
};

struct CMY {
	float c;
	float m;
	float y;
	void setCMY(float cyan, float magenta, float yellow);
};

struct HSV {
	int h;
	float s;
	float v;
};

CMY RGBtoCMY(const RGB &rgb);

HSV RGBtoHSV(const RGB &rgb);

RGB CMYtoRGB(const CMY &cmy);

HSV CMYtoHSV(const CMY &cmy);

RGB HSVtoRGB(const HSV &hsv);

CMY HSVtoCMY(const HSV &hsv);