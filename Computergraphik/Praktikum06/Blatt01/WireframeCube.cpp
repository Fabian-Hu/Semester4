#include "WireframeCube.h"
#include <glm/glm.hpp>

WireframeCube::WireframeCube(glm::vec3 color) : Model3D(GL_LINES) {
	createWireframeCube(color);
}

void WireframeCube::createWireframeCube(glm::vec3 color) {
	std::vector<glm::vec3> vertices;

	vertices = { { -1.0f, 1.0f, 1.0f },{ 1.0f, -1.0f, 1.0f },{ -1.0f, -1.0f, 1.0f } };
	addFace(Face(vertices, color));
	vertices = { { 1.0f, 1.0f, 1.0f },{ 1.0f, -1.0f, 1.0f },{ -1.0f, 1.0f, 1.0f } };
	addFace(Face(vertices, color));

	vertices = { { 1.0, 1.0, 1.0 },{ 1.0, -1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	addFace(Face(vertices, color));
	vertices = { { 1.0, -1.0, -1.0 },{ 1.0, -1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	addFace(Face(vertices, color));

	vertices = { { 1.0, 1.0, 1.0 },{ -1.0, 1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	addFace(Face(vertices, color));
	vertices = { { -1.0, 1.0, -1.0 },{ -1.0, 1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	addFace(Face(vertices, color));

	vertices = { { 1.0, 1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ 1.0, -1.0, -1.0 } };
	addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ 1.0, -1.0, -1.0 } };
	addFace(Face(vertices, color));

	vertices = { { -1.0, 1.0, 1.0 },{ -1.0, 1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	addFace(Face(vertices, color));

	vertices = { { 1.0, -1.0, 1.0 },{ 1.0, -1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ 1.0, -1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	addFace(Face(vertices, color));
}
