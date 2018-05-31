#pragma once
#include "Sphere.h"
#include "WorldObject.h"

class Orb : public WorldObject {
public:
	Orb (Model3D *model, glm::vec3 axis);
	Orb (Model3D *model, glm::vec3 axis, float angle, float angleLocal, bool rotateWithParent = true);

	void rotate ();
	void multiplyRotationAngle (float num);

private:
	float rotationAngle;
	float rotationAngleLocal;
};