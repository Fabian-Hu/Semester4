#include "BoundingBox.h"

BoundingBox::BoundingBox(const Model *womodel, Model *bbmodel) :
	WorldObject(bbmodel) {
	calculateBoundingBox(womodel, bbmodel);
}

void BoundingBox::calculateBoundingBox(const Model *womodel, Model *bbmodel) {

}
