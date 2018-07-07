#pragma once
#include "Sphere.h"

class SolidSphere : public Sphere {
public:
	SolidSphere(float radius, int numSplits, glm::vec3 color);
	SolidSphere(glm::vec3 position, float radius, int numSplits, glm::vec3 color);
	void build();
};