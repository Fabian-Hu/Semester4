#pragma once
#include <fstream>
#include <iostream>
#include "Halfedge.h"
#include <vector>
#include <string>

int readObject(std::string filename);
HE_face createFace(std::string line);
HE_vert createVert(std::string line);