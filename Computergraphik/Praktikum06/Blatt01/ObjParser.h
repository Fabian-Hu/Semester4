#pragma once
#include "HE_Datastructs.h"
#include <vector>
#include "GLSLProgram.h"
#include <string>
#include <fstream>

const int lineLength = 256;

class ObjParser {
public:
	HE_face* parseObj(std::string &path);

private:
	bool readVerts(std::ifstream &instream);

	std::vector<glm::vec3> verts;
};
