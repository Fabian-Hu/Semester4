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
		}
		instream.getline(line, lineLength);
		face.clear();
		face.append(line);
	}

	instream.close();
	return nullptr;
}

std::string ObjParser::readVerts(std::ifstream & instream, HE_Object &obj) {
	char line[lineLength];

	while (instream.getline(line, lineLength) && line[0] != 'f') {
		if (line[0] == 'v') {
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
		}
	}
	return std::string(line);
}

void ObjParser::createFace(std::string &faceS, HE_Object &obj) {
	std::istringstream values(faceS.c_str() + 2);
	std::string val;
	while (val.length() == 0) {
		val.clear();
		std::getline(values, val, ' ');
	}

	HE_face *face = new HE_face;

	int one = atoi(val.c_str());
	int first = one;
	int second = -1;

	while (values) {
		HE_edge *edge = new HE_edge;

		if (second != -1) {
			obj.edges.back()->next = edge;
		} else {
			face->edge = edge;
		}
		val.clear();
		std::getline(values, val, ' ');
		second = first;
		first = atoi(val.c_str());
		if (first == second || first == 0) {
			first = one;
		}
		
		edge->face = face;
		edge->vert = obj.verts[second - 1];
		edge->vert->edge = edge;

		if (!setPair(edge, obj.verts[first - 1])) {
			obj.verts[first - 1]->pointingEdges.push_back(edge);
		}
		obj.edges.push_back(edge);
	}
	obj.edges.back()->next = face->edge;
	obj.face.push_back(face);
}

bool ObjParser::setPair(HE_edge *edge, HE_vert *vert) {
	int size = edge->vert->pointingEdges.size();
	for (int i = 0; i < size; i++) {
		if (edge->vert->pointingEdges[i]->vert == vert) {
			edge->vert->pointingEdges[i]->pair = edge;
			edge->pair = edge->vert->pointingEdges[i];
			edge->vert->pointingEdges.erase(edge->vert->pointingEdges.begin() + i);
			return true;
		}
	}
	return false;
}
