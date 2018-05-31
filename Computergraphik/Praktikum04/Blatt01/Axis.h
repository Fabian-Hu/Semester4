#pragma once
#include "Model3D.h"

class Axis : public Model3D {
public:
	Axis(glm::vec3 position, float length, glm::vec3 color, float angle, glm::vec3 axis);
	void build();
	void init (cg::GLSLProgram &program);

private:
	float length;
	glm::vec3 color;

	float angle;
	glm::vec3 axis;
};