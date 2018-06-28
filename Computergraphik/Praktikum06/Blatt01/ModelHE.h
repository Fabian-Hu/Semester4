#pragma once
#include "Model3D.h"
#include "HE_Datastructs.h"
#include <string>

class ModelHE : public Model3D {
public:
	ModelHE(GLenum mode, std::string modelPath, glm::vec3 color);
	ModelHE(GLenum mode, HE_Object *heObject, glm::vec3 color);
	ModelHE(GLenum mode, glm::vec3 position, HE_Object *heObject, glm::vec3 color);

private:
	void calculateModel(HE_Object *heObject, glm::vec3 color);
};
