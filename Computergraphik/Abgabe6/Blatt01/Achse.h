#pragma once
#include "Himmelsding.h"


class Achse : Masterding {
public:
	Achse();
	Achse(float x, float y, float z, float laenge);
	Achse(Himmelsding *planet, float x, float y, float z, float laenge, float schiefigkeit);

	void render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void init(cg::GLSLProgram& program);
	void releaseObject();

	void translate(float x, float y, float z);
	void translate(glm::vec3 position);

	float degreeToRadians(float angle);

	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	void rotateSelf(float angle);

	glm::vec3 getPosition();

private:
	Object wireSphere;
	Himmelsding *planet;
	glm::vec3 axis = { -1.0f, 1.0f, 0.0f };

	float schiefigkeitus = 0.0f;
	float laenge = 6.0f;

	glm::vec3 position;
};