#pragma once
#include "Halfedge.h"


int readObject(std::string filename);
HE_face* createFace(std::string line);
HE_vert* createVert(std::string line);

