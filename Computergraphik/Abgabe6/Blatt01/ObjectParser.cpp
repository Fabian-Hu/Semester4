
#include "ObjectParser.h"

int counterE = 0;
HE_face* readObject(std::string filename, HalfEdgeList* halfEdgeList)
{
	if (filename.substr(filename.size() - 4, 4) != ".obj")
		return NULL;
	int counterV = 0, counterF = 0;
	std::fstream f;
	char cstring[256];
	f.open(filename, std::ios::in);

	while (!f.eof()) {
		f.getline(cstring, sizeof(cstring));

		if (cstring[0] == 'v') {
			halfEdgeList->vertices.push_back(createVert(cstring));
			counterV++;
		}
		else if (cstring[0] == 'f') {
			halfEdgeList->fratzen.push_back(createFace(cstring, halfEdgeList));
			counterF++;
		}
		else {
			//std::cout << "nicht gefunden" << std::endl;
		}
		//memset(cstring, 0, sizeof(cstring));

		char *begin = cstring;
		char *end = begin + sizeof(cstring);
		std::fill(begin, end, 0);
	}

	//std::cout << "Kein Test Anzahl Vertices: " << counterV << std::endl;
	//std::cout << "Kein Test Anzahl Faces: " << counterF << std::endl;
	//std::cout << "Kein Test Anzahl Edges: " << counterE << std::endl;
	f.close();
}

HE_face* createFace(std::string line, HalfEdgeList* halfEdgeList) {
	HE_face* face = new HE_face;
	HE_edge* edge = new HE_edge;
	HE_edge* lastEdge = new HE_edge;
	std::vector<int> number;
	int i, count = 0, endofline = 0;
	face->edge = edge;
	HE_edge* vorEdge = face->edge;

	for (i = 2; i < line.length(); i++) {
		std::string vertString = "";
		if (line[i] != ' ') {
			for (int k = i; line[k] != ' ' && line[k] != '\0'; k++) {
				if (line[k] != '\0') {
					vertString += line[k];
					i++;
				}
			}

			number.push_back(::atoi(vertString.c_str()));
		}
	}

	for (i = 0; i < number.size(); i++) {

		//std::cout << "Face " << number.at(i) << std::endl;
		edge->vert = halfEdgeList->vertices.at(number.at(i) - 1);
		edge->face = face;
		edge->vert->edge = edge;
		edge->next = nullptr;


		if (count != 0) {
			vorEdge->next = edge;
			vorEdge = vorEdge->next;
		}
		count++;

		int nextNum = i + 1 >= number.size() ? 0 : i + 1;
		halfEdgeList->vertices[number[nextNum] - 1]->pointingEdges.push_back(edge);

		if (edge->paired == false) {
			for (int e = 0; e < edge->vert->pointingEdges.size(); e++) {
				if (halfEdgeList->vertices[number[nextNum] - 1] == edge->vert->pointingEdges[e]->vert) {
					edge->pair = edge->vert->pointingEdges.at(e);
					edge->pair->pair = edge;
					edge->paired = true;
					edge->pair->paired = true;
					edge->vert->pointingEdges.erase(edge->vert->pointingEdges.begin() + e);
				}
			}
		}

		lastEdge = edge;
		halfEdgeList->edges.push_back(edge);
		counterE++;
		edge = new HE_edge;


	}

	lastEdge->next = face->edge;
	//std::cout << "Last X: " <<lastEdge->vert->x<< " Last Y: " << lastEdge->vert->y << " Last Z: " << lastEdge->vert->z << std::endl;
	return face;
}


HE_vert* createVert(std::string line) {
	HE_vert* vertex = new HE_vert;
	std::string xString = "";
	std::string yString = "";
	std::string zString = "";

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

