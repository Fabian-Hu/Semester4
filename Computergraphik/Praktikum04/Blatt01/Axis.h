#pragma once
#include "Model3D.h"

class Axis : public Model3D {
public:
	Axis(glm::vec3 position, float length, glm::vec3 color);
	void build();

private:
	float length;
	glm::vec3 color;

};