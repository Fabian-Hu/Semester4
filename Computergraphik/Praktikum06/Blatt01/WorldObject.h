#pragma once
#include "Model3D.h"
#include "WireframeCube.h"
#include <vector>

class WorldObject {
public:
	WorldObject (Model *model, bool rotateWithParent = true);
	void setOrigin (glm::vec3 origin);
	void addChild (WorldObject &child);

	void translate (glm::vec3 direction);
	void translateWithChilds(glm::vec3 direction);
	void translateWithoutChilds(glm::vec3 direction);

	void rotate (float a, glm::vec3 axis, int childs = 1);
	void rotate (float a, glm::vec3 axis, glm::vec3 point, int childs = 1);
	void rotateChilds(float a, glm::vec3 origin, glm::vec3 axis, bool withAllChilds= false);

	void rotateLocal(float a, glm::vec3 axis, int childs = 1);

	void scale(glm::vec3 direction, float value = 1.0f);

	void setActive(bool active = true);
	bool isActive();

	void build ();
	void init (cg::GLSLProgram &program);
	void render(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection);
	void release ();

	Model *getModel();

private:
	friend class Orb;
	friend class BoundingBox;
	Model *model;
	WorldObject *parent;
	std::vector<WorldObject *> childs;
	glm::vec3 origin;

	void setParent (WorldObject *parent);
	bool rotateWithParent;
};