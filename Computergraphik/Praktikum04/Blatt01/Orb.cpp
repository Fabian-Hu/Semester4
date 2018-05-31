#include "Orb.h"
#include "GLTools.h"

Orb::Orb(glm::vec3 position, float radius, int numSplits, glm::vec3 color, GLenum mode) : 
	Sphere(position, radius, numSplits, color, mode) {
}

void Orb::addOrb(Orb &orb) {
	orb.setOrigin (getPosition ());
	orbs.push_back(&orb);
}

void Orb::buildAll () {
	this->build ();
	for each (Orb *childOrb in orbs) {
		childOrb->buildAll ();
	}
}

void Orb::initAll (cg::GLSLProgram &program) {
	this->init (program);
	for each (Orb *childOrb in orbs) {
		childOrb->initAll (program);
	}
}

void Orb::renderAll (cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection) {
	this->render (program, view, projection);
	for each (Orb *childOrb in orbs) {
		childOrb->renderAll (program, view, projection);
	}
}

void Orb::releaseAllModels () {
	for each (Orb *childOrb in orbs) {
		childOrb->releaseAllModels ();
	}
	this->releaseModel ();
}
