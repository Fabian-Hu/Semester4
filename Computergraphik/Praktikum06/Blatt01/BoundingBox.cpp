#include "BoundingBox.h"
#include "WireframeBox.h"

BoundingBox::BoundingBox(ModelHE *model, glm::vec3 color) : heModel(model), bbColor(color) {
	childModel = WorldObject(model);
	childs.push_back(&childModel);
}

void BoundingBox::init(cg::GLSLProgram &program) {
	model->init(program);
	for each (WorldObject *childObj in childs) {
		childObj->init(program);
	}
	heModel->initNormals(program);
	heModel->initFaceNormals(program);
	translate(-model->getPosition());
	glm::vec3 size = heModel->getMax() - heModel->getMin();
	float avgSize = (size[0] + size[1] + size[2]) / 3;
	scaleLocal(1 / avgSize);
}

void BoundingBox::build() {
	for each (WorldObject *childObj in childs) {
		childObj->build();
	}
	this->model = new WireframeBox(heModel->getMax(), heModel->getMin(), bbColor);
	model->build();
}

void BoundingBox::setNormals(bool show) {
	heModel->setNormals(show);
}

bool BoundingBox::getNormalsStatus() {
	return heModel->getNormalsStatus();
}

void BoundingBox::setFaceNormals(bool show) {
	heModel->setFaceNormals(show);
}

bool BoundingBox::getFaceNormalsStatus() {
	return heModel->getFaceNormalsStatus();
}
