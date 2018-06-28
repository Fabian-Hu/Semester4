#include "ObjParser.h"
#include <ostream>
#include <sstream>

HE_face* ObjParser::parseObj(std::string &path) {
	std::ifstream instream(path);
	std::cout << path << std::endl;
	if (!instream) {
		return NULL;
	}
	readVerts(instream);
	instream.close();
	return nullptr;
}

bool ObjParser::readVerts(std::ifstream & instream) {
	char line[lineLength];

	while (instream.getline(line, lineLength) && line[0] == 'v') {
		std::istringstream value(line + 2);
		std::string val;
		glm::vec3 vec;
			
		for (int i = 0; i < 3; i++) {
			std::getline(value, val, ' ');
			vec[i] = strtof(val.c_str(), 0);
		}
		verts.push_back(vec);
	}
	return false;
}
