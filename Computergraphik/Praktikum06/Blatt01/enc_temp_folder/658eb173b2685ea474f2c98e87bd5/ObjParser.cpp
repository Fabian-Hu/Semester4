#include "ObjParser.h"
#include <ostream>
#include <sstream>

HE_face* ObjParser::parseObj(std::string &path, HE_Object &obj) {
	std::ifstream instream(path);
	std::cout << path << std::endl;
	if (!instream) {
		return NULL;
	}

	std::string face = readVerts(instream, obj);
	char line[lineLength];
	
	while (instream) {
		if (face[0] == 'f') {
			createFace(face, obj);
			instream.getline(line, lineLength);
			face.clear();
			face.shrink_to_fit();
			face.append(line);
		}
	}


	instream.close();
	return nullptr;
}

std::string ObjParser::readVerts(std::ifstream & instream, HE_Object &obj) {
	char line[lineLength];

	while (instream.getline(line, lineLength) && line[0] == 'v') {
		std::istringstream value(line + 2);
		std::string val;
		HE_vert *vert = new HE_vert;
			
		std::getline(value, val, ' ');
		vert->x = strtof(val.c_str(), 0);
		std::getline(value, val, ' ');
		vert->y = strtof(val.c_str(), 0);
		std::getline(value, val, ' ');
		vert->z = strtof(val.c_str(), 0);

		obj.verts.push_back(vert);
		edgesToVert.push_back(std::vector<HE_edge>());
	}
	return std::string(line);
}

void ObjParser::createFace(std::string &faceS, HE_Object &obj) {
	std::istringstream values(faceS.c_str() + 2);
	std::string val;
	std::getline(values, val, ' ');

	HE_face *face = new HE_face;

	int first = atoi(val.c_str());
	int second = -1;

	while (values) {
		HE_edge *edge = new HE_edge;

		if (second != -1) {
			edge->next = obj.edges.back();
		}

		std::getline(values, val, ' ');
		second = first;
		first = atoi(val.c_str());
		
		edge->face = face;
		edge->vert = obj.verts[second - 1];
		obj.edges.push_back(edge);
	}
	obj.face.push_back(face);
}
