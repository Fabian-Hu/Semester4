#pragma once
#include "Sphere.h"
#include "WorldObject.h"

class Orb : public WorldObject {
public:
	Orb (Model *model, glm::vec3 &axis);
	Orb (Model *model, glm::vec3 axis, float angle, float angleLocal, bool rotateWithParent = true);

	void rotate ();
	void rotate(float a, glm::vec3 axis);
	void multiplyRotationAngle (float num);
	void rotateWithAxis(float a, glm::vec3 direction);
	void rotateWithAxis(float a, glm::vec3 direction, glm::vec3 point);

	float getRotationAngle();
	void setUp();
	void addSetUp(void(*f)(Orb *orb));
	void addRotation(void (*f)(Orb *orb));

private:
	glm::vec3 axis;
	float rotationAngle;
	float rotationAngleLocal;
	std::vector<void (*)(Orb *orb)> rotation;
	std::vector<void(*)(Orb *orb)> setUpFunction;
};