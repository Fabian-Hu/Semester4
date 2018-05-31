#pragma once
#include "Sphere.h"
#include "WorldObject.h"

class Orb : public WorldObject {
public:
	Orb(Model3D *model, glm::vec3 axis);

private:
	glm::vec3 rotationPoint;
	glm::vec3 rotationAxis;
};