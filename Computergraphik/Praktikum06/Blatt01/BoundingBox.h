#pragma once
#include "WorldObject.h"

class BoundingBox {
public:
	BoundingBox(WorldObject *worldobject, glm::vec3 size);
	void setActive(bool show = true);
	bool isActive();

	void fitBbToObj();
	void fitObjToBb();

private:
	WorldObject *worldObject;
	WorldObject *box;
};