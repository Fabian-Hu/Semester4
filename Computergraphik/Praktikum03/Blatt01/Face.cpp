#include "Face.h"

Face::Face(std::vector<glm::vec3> &vertices, glm::vec3 &color) {
	this->vertices = vertices;
	for (int i = 0; i < vertices.size(); i++) {
		colors.push_back(color);
	}
}

Face::Face(std::vector<glm::vec3> &vertices, glm::vec3 &color, std::vector<GLushort> &indices) {
	this->vertices = vertices;
	for (int i = 0; i < vertices.size(); i++) {
		colors.push_back(color);
	}
	this->indices = indices;
}

Face::Face(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &colors) {
	this->vertices = vertices;
	this->colors = colors;
}

std::vector<glm::vec3> Face::getVertices() {
	return vertices;
}

std::vector<glm::vec3> Face::getColors() {
	return colors;
}

std::vector<GLushort> Face::getIndices() {
	return indices;
}
