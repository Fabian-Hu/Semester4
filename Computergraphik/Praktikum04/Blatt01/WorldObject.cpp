#include "WorldObject.h"

WorldObject::WorldObject (Model3D *model, glm::vec3 axis, bool rotateWithParent) : model (model), axis (axis), rotateWithParent(rotateWithParent) { }

void WorldObject::setOrigin (glm::vec3 origin) {
	model->setOrigin (origin);
}

void WorldObject::addChild (WorldObject &child) {
	child.setOrigin (model->getPosition ());
	child.setParent (this);
	childs.push_back (&child);
}

void WorldObject::setParent (WorldObject *parent) {
	this->parent = parent;
}

void WorldObject::translate (glm::vec3 direction) {
	model->translate (direction);
	for each (WorldObject *childObj in childs) {
		childObj->translate (direction);
	}
}

//rotates without changing rotating the axis -> rotation axis of mars is always the same
void WorldObject::rotate (float a) {
	glm::vec3 axis;
	if (parent)
		axis = parent->axis;
	else
		axis = glm::vec3 (0, 1, 0);
	rotate (a, model->getOrigin (), axis);
}

void WorldObject::rotateWithAxis (float a, glm::vec3 direction) {
	model->rotateLocal (a, direction);
	glm::vec4 axisVec (axis[0], axis[1], axis[2], 1);
	axis = glm::rotate (glm::mat4 (1.0f), a, direction) * axisVec;

	for each (WorldObject *childObj in childs) {
		childObj->rotate (a, model->getPosition(), direction);
	}
}

void WorldObject::rotate (float a, glm::vec3 origin, glm::vec3 axis) {
	
	model->rotateAroundPoint (a, axis, origin);
	rotateChilds (a, origin, axis);
}

void WorldObject::rotateLocal (float a) {
	model->rotateLocal (a, axis);
	//rotateChilds (a, model->getPosition());
}

void WorldObject::rotateChilds (float a, glm::vec3 origin, glm::vec3 axis) {
	for each (WorldObject *childObj in childs) {
		if (childObj->rotateWithParent)
			childObj->rotate (a, origin, axis);
		else
			childObj->rotate (a, origin + childObj->model->getPosition () - model->getPosition (), axis);
	}
}

void WorldObject::build () {
	model->build ();
	for each (WorldObject *childObj in childs) {
		childObj->build ();
	}
}

void WorldObject::init (cg::GLSLProgram &program) {
	model->init (program);
	for each (WorldObject *childObj in childs) {
		childObj->init(program);
	}
}

void WorldObject::render (cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection) {
	model->render (program, view, projection);
	for each (WorldObject *childObj in childs) {
		childObj->render (program, view, projection);
	}
}

void WorldObject::release () {
	for each (WorldObject *childObj in childs) {
		childObj->release ();
	}
	model->releaseModel ();
}
