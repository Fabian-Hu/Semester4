#include "WorldObject.h"

WorldObject::WorldObject (Model *model, bool rotateWithParent) : model (model), rotateWithParent(rotateWithParent), active(true) {
	origin = model->getPosition();
}

void WorldObject::setOrigin (glm::vec3 origin) {
	this->origin = origin;
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

void WorldObject::translateWithoutChilds(glm::vec3 direction){
	model->translate(direction);
}

void WorldObject::rotate(float a, glm::vec3 origin, glm::vec3 axis, int childs) {
	model->rotate (a, axis, origin);
	if (childs == 1) {
		rotateChilds(a, origin, axis);
	} else if (childs == 2) {
		rotateChilds(a, origin, axis, true);
	}
}

void WorldObject::rotate(float a, glm::vec3 axis, int childs) {
	model->rotate(a, axis, origin);
	if (childs == 1) {
		rotateChilds(a, origin, axis);
	} else if (childs == 2) {
		rotateChilds(a, origin, axis, true);
	}
}

void WorldObject::rotateChilds(float a, glm::vec3 origin, glm::vec3 axis, bool withAllChilds) {
	for each (WorldObject *childObj in childs) {
		if (childObj->rotateWithParent || withAllChilds)
			childObj->rotate(a, origin, axis, withAllChilds);
		else
			childObj->rotate(a, origin + childObj->model->getPosition() - model->getPosition(), axis, withAllChilds);
	}
}

void WorldObject::rotateLocal(float a, glm::vec3 axis, int childs) {
	model->rotateCenter (a, axis);
	if (childs == 1) {
		rotateChilds(a, model->getPosition(), axis);
	} else if (childs == 2) {
		rotateChilds(a, model->getPosition(), axis, true);
	}
}

void WorldObject::setActive(bool active) {
	this->model->setActive = active;
}

bool WorldObject::isActive() {
	return this->model->isActive();
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
	model->render(program, view, projection);
	for each (WorldObject *childObj in childs) {
		childObj->render(program, view, projection);
	}
}

void WorldObject::release () {
	for each (WorldObject *childObj in childs) {
		childObj->release ();
	}
	model->releaseModel ();
}

void WorldObject::showBoundingBox(bool show) {
	if (!boundingBox) {
		WireframeCube cube = WireframeCube(glm::vec3(0.0f, 0.0f, 1.0f));
		boundingBox = &BoundingBox(this->model, &cube);
	}
	
	boundingBox->setActive(show);
}
