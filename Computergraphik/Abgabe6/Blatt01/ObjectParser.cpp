
#include "ObjectParser.h"

using namespace std;

int readObject(string filename)
{
	if (filename.substr(filename.size() - 4, 4) != ".obj")
		return false;

	fstream f;
	char cstring[256];
	f.open(filename, ios::in);

	while (!f.eof()) {
		f.getline(cstring, sizeof(cstring));

		if (cstring[0] == 'v') {
			halfEdgeList->vertices.push_back(createVert(cstring));
		}
		else if (cstring[0] == 'f') {
			halfEdgeList->fratzen.push_back(createFace(cstring));
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

HE_face* createFace(string line) {
	HE_face* face = new HE_face;
	HE_edge* edge = new HE_edge;
	HE_edge* lastEdge = new HE_edge;
	int i, count=0;
	face->edge = edge;
	HE_edge* vorEdge = new HE_edge;
	vorEdge = face->edge;
	for (i = 2; line[i] != '\0'; i++) {
		if (line[i] != ' ') {
			edge->vert = halfEdgeList->vertices.at(i);
			edge->face = face;
			edge->vert->edge = edge;
			
			if (count != 0) {
				vorEdge->next = edge;
				vorEdge = vorEdge->next;
			}
			count++;
		}
		lastEdge = edge;
		edge = new HE_edge;
	}
	lastEdge->next = face->edge;

	HE_edge* testEdge = face->edge;
	do {
		testEdge = testEdge->next;
		cout << "Face x " <<face->edge->vert->x << endl;
	} while (testEdge != face->edge);

	return face;
}


HE_vert* createVert(string line) {
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
	return vertex;
}