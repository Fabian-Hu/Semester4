#pragma once
#include "ModelHE.h"

class BoundingBox {
public:
	BoundingBox();
	BoundingBox(ModelHE* modelHE);

	void render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void init(cg::GLSLProgram& program);
	void releaseObject();
	void rewrite(); 
	void build();

private:
	ObjectObject object;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLuint> indices;
	ModelHE* modelHE;
};