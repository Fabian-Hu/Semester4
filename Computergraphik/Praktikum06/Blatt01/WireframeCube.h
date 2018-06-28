#pragma once
#include "Model3D.h"

class WireframeCube : public Model3D {
public:
	WireframeCube(glm::vec3 color);

private:
	void createWireframeCube(glm::vec3 color);
};