#include "BoundingBox.h"

BoundingBox::BoundingBox(WorldObject * worldobject, glm::vec3 size) : 
	worldObject(worldObject), box(&WorldObject(&WireframeCube(glm::vec3(1.0f, 1.0f, 0.0f)))) {
	box->scale(size);
}

void BoundingBox::setActive(bool show) {
	box->setActive(show);
}

bool BoundingBox::isActive()
{
	return box->isActive();
}

void BoundingBox::fitObjToBb() {
	glm::vec3 maxVertPos = worldObject->getModel()->getMaxVertPosition();
	glm::vec3 minVertPos = worldObject->getModel()->getMinVertPosition();

}
