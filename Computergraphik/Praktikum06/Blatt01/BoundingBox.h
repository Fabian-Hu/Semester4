#pragma once
#include "WorldObject.h"
#include "ModelHE.h"

class BoundingBox : public WorldObject {
public:
	BoundingBox(ModelHE * model, glm::vec3 color);
	void init(cg::GLSLProgram &program);

	void build();
	void setNormals(bool show);
	bool getNormalsStatus(); 
	void setFaceNormals(bool show);
	bool getFaceNormalsStatus();

private:
	WorldObject childModel;
	ModelHE *heModel;
	glm::vec3 bbColor;
};