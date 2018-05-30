#include "Axis.h"

Axis::Axis(glm::vec3 position, float length, glm::vec3 color) :
	Model3D(position, GL_LINES), length(length), color(color) {}

void Axis::build() {
	points.push_back({ 0.0f, length / 2, 0.0f } );
	points.push_back({ 0.0f, -length / 2, 0.0f });
	points_vertices.push_back(0);
	points_vertices.push_back(1);
	colors.push_back(color);
	colors.push_back(color);
	indices.push_back(0);
	indices.push_back(1);
	addFace(Face());
}
