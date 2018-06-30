#include "WireframeBox.h"

WireframeBox::WireframeBox(glm::vec3 max, glm::vec3 min, glm::vec3 color) : Model(GL_LINES), max(max), min(min) {
	for (int i = 0; i < 8; i++) {
		colors.push_back(color);
	}
	position = min + (max - min) * 0.5f;
}

void WireframeBox::build() {
	vertices.push_back(min);
	
	vertices.push_back(glm::vec3(min[0], min[1], max[2]));
	vertices.push_back(glm::vec3(min[0], max[1], min[2]));
	vertices.push_back(glm::vec3(max[0], min[1], min[2]));

	vertices.push_back(glm::vec3(max[0], max[1], min[2]));
	vertices.push_back(glm::vec3(max[0], min[1], max[2]));
	vertices.push_back(glm::vec3(min[0], max[1], max[2]));
	
	vertices.push_back(max);

	indices = { 0, 3, 3, 5, 5, 1, 1, 0,
				7, 4, 4, 2, 2, 6, 6, 7,
				5, 7, 1, 6, 0, 2, 3, 4};

	for (int i = 0; i < vertices.size(); i++) {
		normals.push_back(vertices[i]);
	}
}

void WireframeBox::init(cg::GLSLProgram & program) {
	glm::vec3 pos = position;
	position = glm::vec3(0.0f);
	Model::init(program);
	position = pos;
}
