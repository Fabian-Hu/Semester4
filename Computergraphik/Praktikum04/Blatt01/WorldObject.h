#pragma once
#include "Model3D.h"
#include <vector>

class WorldObject {
public:
	WorldObject (Model3D *model, glm::vec3 axis, bool rotateWithParent = true);
	void setOrigin (glm::vec3 origin);
	void addChild (WorldObject &child);

	void translate (glm::vec3 direction);
	void rotate (float a);
	void rotateWithAxis (float a, glm::vec3 direction);
	void rotate (float a, glm::vec3 origin, glm::vec3 axis);
	void rotateLocal (float a);
	void rotateChilds (float a, glm::vec3 origin, glm::vec3 axis);

	void build ();
	void init (cg::GLSLProgram &program);
	void render(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection);
	void release ();

private:
	friend class Orb;
	Model3D *model;
	WorldObject *parent;
	std::vector<WorldObject *> childs;

	glm::vec3 axis;
	void setParent (WorldObject *parent);
	bool rotateWithParent;

};