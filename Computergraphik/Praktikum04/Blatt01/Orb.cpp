#include "Orb.h"
#include "GLTools.h"

Orb::Orb (Model3D *model, glm::vec3 axis) :
	WorldObject (model, axis), rotationAngle(0.0f), rotationAngleLocal(0.0f) {
}

Orb::Orb (Model3D *model, glm::vec3 axis, float angle, float angleLocal, bool rotateWithParent) :
	WorldObject (model, axis, rotateWithParent), rotationAngle(angle), rotationAngleLocal(angleLocal) {
}

void Orb::rotate () {
	WorldObject::rotate (rotationAngle);
	WorldObject::rotateLocal (rotationAngleLocal);
	for each (Orb *childObj in WorldObject::childs) {
		childObj->setOrigin (WorldObject::model->getPosition ());
		childObj->rotate();
	}
}

void Orb::multiplyRotationAngle (float num) {
	rotationAngle *= num;
	rotationAngleLocal *= num;
	for each (Orb *childObj in childs) {
		childObj->multiplyRotationAngle (num);
	}
}
