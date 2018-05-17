#pragma once

#include <vector>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

class Face {
public:
	Face(std::vector<glm::vec3> &vertices, glm::vec3 &color);
	Face(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &colors);

	std::vector<glm::vec3> getVertices();
	std::vector<glm::vec3> getColors();
	std::vector<GLushort> getIndices();

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices = { 0, 1, 2 };
};