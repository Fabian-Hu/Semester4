
#include "ObjectParser.h"

using namespace std;

int readObject(string filename)
{
	if (filename.substr(filename.size() - 4, 4) != ".obj")
		return false;

	fstream f;
	char cstring[256];
	vector<HE_face> fratze;
	vector<HE_vert> vert ;
	f.open(filename, ios::in);

	while (!f.eof()) {
		f.getline(cstring, sizeof(cstring));

		if (cstring[0] == 'v') {
			vert.push_back(createVert(cstring));
		}
		else if (cstring[0] == 'f') {
			fratze.push_back(createVert(cstring));
		}
		else {
			cout << "nicht gefunden" << endl;
		}
		//memset(cstring, 0, sizeof(cstring));

		char *begin = cstring;
		char *end = begin + sizeof(cstring);
		fill(begin, end, 0);
	}
	
	
	f.close();
}

HE_face createFace(string line) {

}

HE_vert createVert(string line) {
	HE_vert* vertex = new HE_vert;
	string xString = "";
	string yString = "";
	string zString = "";

	int i;
	for (i = 2; line[i] != ' '; i++) {		
		xString += line[i];
	}
	
	vertex->x = ::atof(xString.c_str());

	for (i = i + 1; line[i] != ' '; i++) {		
		yString += line[i];
	}
	
	vertex->y = ::atof(yString.c_str());

	for (i = i + 1; line[i] != '\0'; i++) {		
		zString += line[i];	
	}
	
	vertex->z = ::atof(zString.c_str());
	
	//cout << " X: " << vertex->x << " Y: " << vertex->y << " Z: " << vertex->z << endl;
	return *vertex;
}