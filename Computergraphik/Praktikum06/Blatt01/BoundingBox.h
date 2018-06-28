#pragma once
#include "WorldObject.h"

class BoudingBox : public WorldObject{
public:
	BoudingBox();
	void setWorldObject(WorldObject &object);

private:
	WorldObject &object;
};