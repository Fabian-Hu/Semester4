#pragma once

#include <vector>
#include "Face.h"
#include "GLSLProgram.h"

class Model3D {
public:
	void addFace (Face &face);
	void init (cg::GLSLProgram &program);
	void render (cg::GLSLProgram &program, glm::mat4x4 view, glm::mat4x4 projection);

private:
	std::vector<Face> faces;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices;
	
	GLuint vao;

	GLuint positionBuffer;
	GLuint colorBuffer;
	GLuint indexBuffer;

	glm::mat4x4 model;

	void calculateModel ();
};