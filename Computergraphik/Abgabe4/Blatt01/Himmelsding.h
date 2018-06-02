#pragma once

#include "MasterDing.h"

class Himmelsding : Masterding {
public:
	Himmelsding();
	Himmelsding::Himmelsding(float x, float y, float z, float radio);
	Himmelsding::Himmelsding(float x, float y, float z, float radio, float schiefigkeit);

	void render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void init(cg::GLSLProgram& program);
	void releaseObject();

	void translate(float x, float y, float z);
	void translate(glm::vec3 position);

	float degreeToRadians(float angle);

	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

private:
	Object wireSphere; // GLUT geometry

	float radius = 1.0f;
	float schiefigkeitus = 0.0f;

	glm::vec3 position;

};

