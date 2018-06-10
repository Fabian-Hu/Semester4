#include "Axis.h"


Axis::Axis() : Model(GL_LINES, glm::vec3(0, 0, 0)) {}

Axis::Axis(glm::vec3 position, glm::vec3 point1, glm::vec3 point2) : Model(GL_LINES, position) {
	vertices.push_back(point1);
	vertices.push_back(point2);
	indices = { 0, 1 };
}

Axis::Axis(glm::vec3 position, float length) : Model(GL_LINES, position) {
	vertices.push_back(glm::vec3(0, length/2.0f, 0));
	vertices.push_back(glm::vec3(0, length / -2.0f, 0));
	indices = { 0, 1 };
}

Axis::Axis(glm::vec3 position, float length, glm::vec3 color) : Axis(position, length) {
	colors.push_back(color);
	colors.push_back(color);
}

void Axis::build(){}
