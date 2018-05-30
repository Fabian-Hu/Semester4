#pragma once

#include <vector>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

class Face {
public:
	Face();
	Face(std::vector<glm::vec3> &vertices, glm::vec3 &color);
	Face(std::vector<glm::vec3> &vertices, glm::vec3 &color, std::vector<GLushort> &indices);
	Face(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &colors);

	void splitFace(Face *faces);
	void normalize(glm::vec3 middle, float distance);

	std::vector<glm::vec3> getVertices();
	std::vector<glm::vec3> getColors();
	std::vector<GLushort> getIndices();

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices = { 0, 1, 2 };
	glm::vec3 splitEdge(glm::vec3 &vert1, glm::vec3 &vert2);
};
