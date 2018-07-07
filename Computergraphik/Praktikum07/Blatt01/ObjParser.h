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
	void createVert(std::string &line, HE_Object &obj);
	void createTexCoord(std::string &line, HE_Object &obj);
	void createNormal(std::string &line, HE_Object &obj);
	void createFace(std::string &face, HE_Object &obj);
	bool setPair(HE_edge *edge, HE_vert *vert);
};
