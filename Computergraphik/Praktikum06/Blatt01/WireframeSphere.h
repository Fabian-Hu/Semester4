#pragma once
#include "Sphere.h"

class WireframeSphere : public Sphere {
public:
	WireframeSphere(float radius, int numSplits, glm::vec3 color);
	WireframeSphere(glm::vec3 position, float radius, int numSplits, glm::vec3 color);
	void build();
};
