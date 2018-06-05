#include "Cube.h"

Cube::Cube() : Model3D(GL_TRIANGLES) {
	createCube();
}

void Cube::createCube() {
	std::vector<glm::vec3> vertices;
	glm::vec3 color;
	vertices = { { -1.0f, 1.0f, 1.0f },{ 1.0f, -1.0f, 1.0f },{ -1.0f, -1.0f, 1.0f } };
	color = { 0.39f, 0.58f, 0.93f };
	addFace(Face(vertices, color));
	vertices = { { 1.0f, 1.0f, 1.0f },{ 1.0f, -1.0f, 1.0f },{ -1.0f, 1.0f, 1.0f } };
	addFace(Face(vertices, color));

	color = { 0.56f, 0.74f, 0.56f };
	vertices = { { 1.0, 1.0, 1.0 },{ 1.0, -1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	addFace(Face(vertices, color));
	vertices = { { 1.0, -1.0, -1.0 },{ 1.0, -1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	addFace(Face(vertices, color));

	color = { 0.7f, 0.13f, 0.13f };
	vertices = { { 1.0, 1.0, 1.0 },{ -1.0, 1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	addFace(Face(vertices, color));
	vertices = { { -1.0, 1.0, -1.0 },{ -1.0, 1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	addFace(Face(vertices, color));

	color = { 0.68f, 1.0f, 0.18f };
	vertices = { { 1.0, 1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ 1.0, -1.0, -1.0 } };
	addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ 1.0, -1.0, -1.0 } };
	addFace(Face(vertices, color));

	color = { 0.94f, 0.5f, 0.5f };
	vertices = { { -1.0, 1.0, 1.0 },{ -1.0, 1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	addFace(Face(vertices, color));

	color = { 1.0f, 0.27f, 0.0f };
	vertices = { { 1.0, -1.0, 1.0 },{ 1.0, -1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ 1.0, -1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	addFace(Face(vertices, color));
}
