#pragma once
#include "Model3D.h"
#include "HE_Datastructs.h"
#include <string>

class ModelHE : public Model {
public:
	ModelHE(GLenum mode, std::string modelPath, glm::vec3 color);
	ModelHE(GLenum mode, HE_Object &heObject, glm::vec3 color);
	ModelHE(GLenum mode, glm::vec3 position, HE_Object &heObject, glm::vec3 color);
	int insertVertex(glm::vec3 vec, glm::vec3 color, glm::vec3 normal);
	void build();
	void init(cg::GLSLProgram &program);

private:
	glm::vec3 origin;
	HE_Object obj;
};
