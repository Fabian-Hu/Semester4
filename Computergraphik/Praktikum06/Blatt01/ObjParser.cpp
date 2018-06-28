#include "ObjParser.h"
#include <ostream>
#include <sstream>
#include <string>

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
		HE_vert vert;
			
		std::getline(value, val, ' ');
		vert.x = strtof(val.c_str(), 0);
		std::getline(value, val, ' ');
		vert.y = strtof(val.c_str(), 0);
		std::getline(value, val, ' ');
		vert.z = strtof(val.c_str(), 0);

		obj.verts.push_back(vert);
	}
	return std::string(line);
}

void ObjParser::createFace(std::string &face, HE_Object &obj) {
	std::istringstream values(face.c_str() + 2);
	std::string val;
	std::getline(values, val, ' ');

	int first;
	int second;
	while (values) {
		std::getline(values, val, ' ');
		
	}


	std::cout << face << std::endl;
}
