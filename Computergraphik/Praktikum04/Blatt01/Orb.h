#pragma once
#include "Sphere.h"

class Orb : public Sphere {
public:
	Orb(glm::vec3 position, float radius, int numSplits, glm::vec3 color, GLenum mode);
	void addOrb(Orb orb);
	void buildAll();

private:
	glm::vec3 rotationPoint;
	glm::vec3 rotationAxis;
	std::vector<Orb> orbs;
};