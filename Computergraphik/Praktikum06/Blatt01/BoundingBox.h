#pragma once
#include "WorldObject.h"

class BoundingBox : public WorldObject {
public:
	BoundingBox(const Model *womodel, Model *bbmodel);

private:
	void calculateBoundingBox(const Model *womodel, Model *bbmodel);
};