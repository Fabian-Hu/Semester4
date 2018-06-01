#pragma once

#include <vector>
#include "GLSLProgram.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include "glm/gtx/rotate_vector.hpp"

#include "GLTools.h"

/*
Struct to hold data for object rendering.
*/
struct Object
{
	inline Object ()
		: vao(0),
		positionBuffer(0),
		colorBuffer(0),
		indexBuffer(0)
	{}

	/* IDs for several buffers. */
	GLuint vao;

	GLuint positionBuffer;
	GLuint colorBuffer;
	GLuint indexBuffer;

	/* Model matrix */
	glm::mat4x4 model;
};

class Himmelsding {
public:
	Himmelsding();
	Himmelsding::Himmelsding(float x, float y, float z, float radio);
	Himmelsding::Himmelsding(float x, float y, float z, float radio, float schiefigkeit);
	void renderWireSphere(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void translate(float x, float y, float z);
	void translate(glm::vec3 position);
	void initWireSphere(cg::GLSLProgram& program);
	void releaseObject();
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

private:
	glm::vec3 position;
	float radius = 1.0f;
	float schiefigkeitus = 0.0f;

	Object wireSphere; // GLUT geometry

};

