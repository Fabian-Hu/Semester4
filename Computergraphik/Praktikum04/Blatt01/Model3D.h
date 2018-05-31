#pragma once

#include <vector>
#include "Face.h"
#include "GLSLProgram.h"
#include <iostream>

class Model3D {
public:
	Model3D();
	Model3D(GLenum mode);
	Model3D(glm::vec3 position, GLenum mode);
	void addFace (Face &face);
	virtual void init (cg::GLSLProgram &program);
	void render (cg::GLSLProgram &program, glm::mat4x4 view, glm::mat4x4 projection);
	virtual void build();
	int containsVertexColor(int index, glm::vec3 &color);
	void releaseModel();
	void rotate (float a, glm::vec3 direction);
	void rotateLocal (float a, glm::vec3 direction);
	void rotateAroundPoint (float a, glm::vec3 direction, glm::vec3 point);
	void translate (glm::vec3 direction);
	glm::vec3 getPosition();
	glm::vec3 getOrigin ();
	void setOrigin (glm::vec3 origin);

private:
	friend class Sphere;
	friend class Axis;
	std::vector<Face> faces;

	std::vector<glm::vec3> points;
	std::vector<int> points_vertices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices;
	
	GLuint vao;

	GLuint positionBuffer;
	GLuint colorBuffer;
	GLuint indexBuffer;

	glm::mat4x4 model;
	glm::vec3 position;
	glm::vec3 origin;

	GLenum mode;

	void calculateModel ();
	int insertPoint(glm::vec3 &point);
};