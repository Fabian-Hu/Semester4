#include "Face.h"

Face::Face(){}

Face::Face(GLenum mode) : Model(mode) {}

Face::Face(GLenum mode, glm::vec3 position) : Model(mode, position) {}

Face::Face(std::vector<glm::vec3>& vertices, glm::vec3 &color) {
	setVertices(vertices);
	setColors(std::vector<glm::vec3>({ color, color, color }));
	setIndices(std::vector<GLushort>({ 0, 1, 2 }));
	origin = glm::vec3(0.0f);
	calculateNormals();
}

Face::Face(std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& colors) : Face(vertices, colors, std::vector<GLushort>({0, 1, 2})) {}

Face::Face(std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& colors, std::vector<GLushort>& indices) {
	setVertices(vertices);
	setColors(colors);
	setIndices(indices);
	origin = glm::vec3(0.0f);
	calculateNormals();
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
	calculateNormals();
}

void Face::calculateNormals() {
	normals.clear();
	glm::vec3 vec1 = vertices[1] - vertices[0];
	glm::vec3 vec2 = vertices[2] - vertices[0];
	
	/*glm::vec3 normal = glm::normalize(glm::cross(vec1, vec2));
	
	glm::vec3 center = vertices[0] + vec1 / 2.0f + vec2 / 2.0f;
	if (glm::distance(origin + normal, center) < glm::distance(origin - normal, center)) {
		normal *= -1.0f;
	}
	
	normals.push_back(normal);
	normals.push_back(normal);
	normals.push_back(normal);
	*/

	normals.push_back(glm::normalize(vertices[0] - origin));
	normals.push_back(glm::normalize(vertices[1] - origin));
	normals.push_back(glm::normalize(vertices[2] - origin));
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

std::vector<glm::vec3> Face::getNormals() {
	return normals;
}

void Face::setOrigin(glm::vec3 origin) {
	this->origin = origin;
}

glm::vec3 Face::splitEdge(glm::vec3 & vert1, glm::vec3 & vert2) {
	glm::vec3 middle;
	for (int i = 0; i < 3; i++) {
		middle[i] = (vert2[i] - vert1[i]) / 2 + vert1[i];
	}
	return middle;
}
