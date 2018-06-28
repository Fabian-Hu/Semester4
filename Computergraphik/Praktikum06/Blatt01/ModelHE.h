#pragma once
#include "Model.h"
#include "HE_Datastructs.h"

class ModelHE : public Model {
public:
	ModelHE(GLenum mode, HE_Object *heObject);
	ModelHE(GLenum mode, glm::vec3 position, HE_Object *heObject);

	virtual void build();

private:
	HE_Object *heObject;
};
