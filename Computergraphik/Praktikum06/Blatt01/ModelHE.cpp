#include "ModelHE.h"

ModelHE::ModelHE(GLenum mode, HE_Object *heObject, glm::vec3 color) :
	Model3D(mode) {
	calculateModel(heObject, color);
}

ModelHE::ModelHE(GLenum mode, glm::vec3 position, HE_Object *heObject, glm::vec3 color) :
	Model3D(mode, position) {
	calculateModel(heObject, color);
}

void ModelHE::calculateModel(HE_Object * heObject, glm::vec3 color) {
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices;

	for (HE_face *face : heObject->face) {
		HE_edge *startEdge = face->edge;
		HE_edge *currentEdge = startEdge;

		int id = 0;
		do {
			HE_vert *vert = currentEdge->vert;
			vertices.push_back(glm::vec3(vert->x, vert->y, vert->z));
			colors.push_back(color);
			indices.push_back(id++);
			currentEdge = currentEdge->next;
		} while (currentEdge != startEdge);

		addFace(Face(vertices, colors, indices));
	}
}