#pragma once
#include "Halfedge.h"


HE_face* readObject(std::string filename, HalfEdgeList* halfEdgeList);
HE_face* createFace(std::string line, HalfEdgeList* halfEdgeList);
HE_vert* createVert(std::string line);
HE_normal* createNormals(std::string line);
HE_texture* createTexture(std::string line);

