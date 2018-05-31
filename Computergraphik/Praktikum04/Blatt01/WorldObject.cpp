#include "WorldObject.h"

WorldObject::WorldObject (Model3D *model, glm::vec3 axis) : model(model), axis(axis) { }

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

void WorldObject::rotate (float a) {
	glm::vec3 axis;
	if (parent)
		axis = parent->axis;
	else
		axis = glm::vec3 (0, 0, 0);
	model->rotate (a, axis);
	for each (WorldObject *childObj in childs) {
		childObj->rotate (a);
	}
}

void WorldObject::rotateLocal (float a) {
	model->rotateLocal (a, axis);
	for each (WorldObject *childObj in childs) {
		childObj->rotateLocal (a);
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
