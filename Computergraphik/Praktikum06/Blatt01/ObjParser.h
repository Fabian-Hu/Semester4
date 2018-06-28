#pragma once
#include "HE_Datastructs.h"
#include <vector>
#include "GLSLProgram.h"
#include <string>
#include <fstream>

const int lineLength = 256;

class ObjParser {
public:
	HE_face* parseObj(std::string &path, HE_Object &obj);

private:
	std::string readVerts(std::ifstream &instream, HE_Object &obj);
	void createFace(std::string &face, HE_Object &obj);
	bool setPair(HE_edge *edge, HE_vert *vert);
};
