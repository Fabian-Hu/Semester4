#pragma once

#include <vector>
#include "GLSLProgram.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
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
	inline Object()
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

class Masterding {
public:
	Masterding();

	void render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void init(cg::GLSLProgram& program);
	void releaseObject();

	void translate(float x, float y, float z);
	void translate(glm::vec3 position);

	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

private:
	Object wireSphere; // GLUT geometry

	float schiefigkeitus = 0.0f;

	glm::vec3 position;

};
