#include "Orb.h"
#include "GLTools.h"
#include "glm/gtx/rotate_vector.hpp"

Orb::Orb (Model *model, glm::vec3 &axis) :
	WorldObject (model), axis(axis), rotationAngle(0.0f), rotationAngleLocal(0.0f) {
}

Orb::Orb (Model *model, glm::vec3 axis, float angle, float angleLocal, bool rotateWithParent) :
	WorldObject (model, rotateWithParent), axis(axis), rotationAngle(angle), rotationAngleLocal(angleLocal) {
}

void Orb::rotate () {
	glm::vec3 axis;
	if (parent)
		axis = ((Orb*)parent)->axis;
	else
		axis = glm::vec3(0, 1, 0);
	WorldObject::rotate(rotationAngle, origin, axis);
	WorldObject::rotateLocal (rotationAngleLocal, this->axis);
	for each (void(*f)(Orb *orb) in rotation) {
		f(this);
	}
	for each (Orb *childObj in WorldObject::childs) {
		childObj->setOrigin (WorldObject::model->getPosition());
		childObj->rotate();
	}
}


void Orb::rotate(float a, glm::vec3 axis) {
	model->rotate(a, axis, model->getPosition());
	rotateChilds(a, model->getPosition(), axis);
}


void Orb::multiplyRotationAngle (float num) {
	rotationAngle *= num;
	rotationAngleLocal *= num;
	for each (Orb *childObj in childs) {
		childObj->multiplyRotationAngle (num);
	}
}

void Orb::rotateWithAxis(float a, glm::vec3 direction) {
	WorldObject::rotate(a, model->getPosition(), direction, 2);

	glm::vec4 axisVec(axis[0], axis[1], axis[2], 1);
	axis = glm::rotate(glm::mat4(1.0f), a, direction) * axisVec;
}

float Orb::getRotationAngle(){
	return rotationAngle;
}

void Orb::setUp() {
	for each (void(*f)(Orb *orb) in setUpFunction) {
		f(this);
	}
	for each (Orb *childObj in childs) {
		childObj->setUp();
	}
}

void Orb::addSetUp(void(*f)(Orb *orb)) {
	setUpFunction.push_back(f);
}

void Orb::addRotation(void(*f)(Orb *orb)) {
	rotation.push_back(f);
}

