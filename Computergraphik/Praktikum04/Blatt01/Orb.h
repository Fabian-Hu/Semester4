#pragma once
#include "Sphere.h"

class Orb : public Sphere {
public:
	Orb(glm::vec3 position, float radius, int numSplits, glm::vec3 color, GLenum mode);
	void addOrb(Orb &orb);
	void buildAll();
	void initAll(cg::GLSLProgram &program);
	void renderAll(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection);
	void releaseAllModels();

private:
	glm::vec3 rotationPoint;
	glm::vec3 rotationAxis;
	std::vector<Orb *> orbs;
};