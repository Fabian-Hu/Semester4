#include "ObjParser.h"
#include <ostream>
#include <sstream>

HE_face* ObjParser::parseObj(std::string &path, HE_Object &obj) {
	std::ifstream instream(path);
	std::cout << path << std::endl;
	if (!instream) {
		return NULL;
	}

	char line[lineLength];
	
	while (instream) {
		instream.getline(line, lineLength);
		if (line[0] == 'v' && line[1] == ' ')
			createVert(std::string(line), obj);
		else if (line[0] == 'v' && line[1] == 'n')
			createNormal(std::string(line), obj);
		else if (line[0] == 'v' && line[1] == 't')
			createTexCoord(std::string(line), obj);
		else if (line[0] == 'f')
			createFace(std::string(line), obj);
	}

	instream.close();
	return obj.face[0];
}

void ObjParser::createVert(std::string &line, HE_Object &obj) {
	std::istringstream values(line.c_str() + 2);
	std::string val;
	HE_vert *vert = new HE_vert;

	std::getline(values, val, ' ');
	vert->x = strtof(val.c_str(), 0);
	std::getline(values, val, ' ');
	vert->y = strtof(val.c_str(), 0);
	std::getline(values, val, ' ');
	vert->z = strtof(val.c_str(), 0);

	vert->approxNormal = nullptr;
	obj.verts.push_back(vert);
}

void ObjParser::createTexCoord(std::string &line, HE_Object &obj) {
	std::istringstream values(line.c_str() + 3);
	std::string val;
	HE_texCoord *texCoord = new HE_texCoord;

	std::getline(values, val, ' ');
	texCoord->x = strtof(val.c_str(), 0);
	std::getline(values, val, ' ');
	texCoord->y = strtof(val.c_str(), 0);

	obj.texCoords.push_back(texCoord);
}

void ObjParser::createNormal(std::string &line, HE_Object &obj) {
	std::istringstream values(line.c_str() + 3);
	std::string val;
	HE_normal *normal = new HE_normal;

	std::getline(values, val, ' ');
	normal->x = strtof(val.c_str(), 0);
	std::getline(values, val, ' ');
	normal->y = strtof(val.c_str(), 0);
	std::getline(values, val, ' ');
	normal->z = strtof(val.c_str(), 0);

	obj.normals.push_back(normal);
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

		std::string vtString;
		int vt = -1;
		int vtIndex = val.find_first_of('/', 0);
		if (vtIndex != -1) {
			vtString = val.substr(vtIndex + 1);
			vt = atoi(vtString.c_str());
		}
		std::string vnString;
		int vn = -1;
		int vnIndex = val.find_last_of('/', val.size());
		if (vnIndex != -1) {
			vnString = val.substr(vnIndex + 1);
			vn = atoi(vnString.c_str());
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
		if (vtIndex != -1)
			edge->texCoord = obj.texCoords[vt - 1];
		else
			edge->texCoord = nullptr;
		if (vnIndex != -1)
			edge->normal = obj.normals[vn - 1];
		else
			edge->normal = nullptr;

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
