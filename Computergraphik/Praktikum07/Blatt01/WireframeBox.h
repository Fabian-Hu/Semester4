#pragma once
#include "Model.h"

class WireframeBox : public Model {
public:
	WireframeBox(glm::vec3 max, glm::vec3 min, glm::vec3 color);
	void build();
	void init(cg::GLSLProgram &program);

private:
	glm::vec3 max, min;
};