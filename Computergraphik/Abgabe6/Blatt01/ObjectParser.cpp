
#include "ObjectParser.h"


HE_face* readObject(std::string filename, HalfEdgeList* halfEdgeList)
{
	if (filename.substr(filename.size() - 4, 4) != ".obj")
		return NULL;

	std::fstream f;
	char cstring[256];
	f.open(filename, std::ios::in);

	while (!f.eof()) {
		f.getline(cstring, sizeof(cstring));

		if (cstring[0] == 'v') {
			halfEdgeList->vertices.push_back(createVert(cstring));
		}
		else if (cstring[0] == 'f') {
			halfEdgeList->fratzen.push_back(createFace(cstring, halfEdgeList));
		}
		else {
			std::cout << "nicht gefunden" << std::endl;
		}
		//memset(cstring, 0, sizeof(cstring));

		char *begin = cstring;
		char *end = begin + sizeof(cstring);
		std::fill(begin, end, 0);
	}
	
	
	f.close();
}

HE_face* createFace(std::string line, HalfEdgeList* halfEdgeList) {
	HE_face* face = new HE_face;
	HE_edge* edge = new HE_edge;
	HE_edge* lastEdge = new HE_edge;
	int i, count=0, number, endofline=0;
	face->edge = edge;
	HE_edge* vorEdge = new HE_edge;
	vorEdge = face->edge;
	for (i = 2; i < line.length(); i++) {
		std::string vertString = "";
		if (line[i] != ' ') {
			for (int k = i; line[k] != ' ' && line[k] != '\0'; k++) {
				if (line[k] != '\0') {
					vertString += line[k];
					i++;
				}
			}

			number = ::atoi(vertString.c_str());
			std::cout << "Face " << number << std::endl;
			edge->vert = halfEdgeList->vertices.at(number - 1);
			edge->face = face;
			edge->vert->edge = edge;

			if (edge->paired == false) {
				for (int e = 0; e < edge->vert->pointingEdges.size(); e++) {
					std::cout << "Suche Pair"  << std::endl;
					if (edge->vert->x == edge->vert->pointingEdges.at(e)->next->vert->x &&
							edge->vert->y == edge->vert->pointingEdges.at(e)->next->vert->y &&
								edge->vert->z == edge->vert->pointingEdges.at(e)->next->vert->z) {
						std::cout << "Pair gefunden" << std::endl;
						edge->pair = edge->vert->pointingEdges.at(e);
						edge->vert->pointingEdges.at(e)->pair = edge;
						edge->paired = true;
						edge->vert->pointingEdges.at(e)->paired = true;
						edge->vert->pointingEdges.erase(edge->vert->pointingEdges.begin()+e);
					}
				}
			}

			if (count != 0) {
				vorEdge->next = edge;				
				vorEdge = vorEdge->next;	

				edge->vert->pointingEdges.push_back(lastEdge);
			}
			count++;

			lastEdge = edge;
			halfEdgeList->edges.push_back(edge);
			edge = new HE_edge;
		}
		
	}
	lastEdge->next = face->edge;
	face->edge->vert->pointingEdges.push_back(lastEdge);
	//std::cout << face->edge->vert->pointingEdges.size() << std::endl;
	for (int j = 0; j < face->edge->vert->pointingEdges.size(); j++) {
		std::cout << "dbhrthedghergh" << face->edge->vert->pointingEdges.at(j)->vert->x << std::endl;
	}

	HE_edge* testEdge = face->edge;
	do {
		std::cout << "Face x " << testEdge->vert->x << std::endl;
		testEdge = testEdge->next;
		
	} while (testEdge != face->edge);
	halfEdgeList->fratzen.push_back(face);
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

