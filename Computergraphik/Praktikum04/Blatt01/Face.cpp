#include "Face.h"

Face::Face(){
}

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

void Face::splitFace(Face *faces) {
	glm::vec3 halfEdges[3];
	for (int i = 0; i < 3; i++) {
		halfEdges[i] = splitEdge(vertices[i], vertices[(i + 1) % 3]);
	}

	for (int i = 0; i < 3; i++) {
		std::vector<glm::vec3> vec = { vertices[i], halfEdges[i], halfEdges[(i + 2) % 3] };
		faces[i] = Face(vec, colors);
	}
	std::vector<glm::vec3> vec = { halfEdges[0], halfEdges[1], halfEdges[2] };
	faces[3] = Face(vec, colors);
}

void Face::normalize(glm::vec3 middle, float distance) {
	for (int i = 0; i < 3; i++) {
		float dx = vertices[i][0] - middle[0];
		float dy = vertices[i][1] - middle[1];
		float dz = vertices[i][2] - middle[2];
		float length = sqrtf(dx * dx + dy * dy + dz * dz);

		float x = dx / length * distance + middle[0];
		float y = dy / length * distance + middle[1];
		float z = dz / length * distance + middle[2];
		length = sqrtf(x * x + y * y + z * z);

		vertices[i] = { x, y, z };
	}
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

glm::vec3 Face::splitEdge(glm::vec3 & vert1, glm::vec3 & vert2) {
	glm::vec3 middle;
	for (int i = 0; i < 3; i++) {
		middle[i] = (vert2[i] - vert1[i]) / 2 + vert1[i];
	}
	return middle;
}
