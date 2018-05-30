#include "Orb.h"

Orb::Orb(glm::vec3 position, float radius, int numSplits, glm::vec3 color, GLenum mode) : 
	Sphere(position, radius, numSplits, color, mode) {
}

void Orb::addOrb(Orb orb) {
	orbs.push_back(orb);
}
