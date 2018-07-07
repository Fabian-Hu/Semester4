#include "WireframeSphere.h"

WireframeSphere::WireframeSphere(float radius, int numSplits, glm::vec3 color) : Sphere(GL_LINES, radius, numSplits, color) {}

WireframeSphere::WireframeSphere(glm::vec3 position, float radius, int numSplits, glm::vec3 color) : 
	Sphere(GL_LINES, position, radius, numSplits, color) {}

void WireframeSphere::build() {
	for (Face &face : faces) {
		std::vector<glm::vec3> faceVertices = face.getVertices();
		std::vector<glm::vec3> faceColors = face.getColors();
		std::vector<GLushort> faceIndices = face.getIndices();
		std::vector<glm::vec3> faceNormals = face.getNormals();

		GLushort indicesTriangle[3];

		for (int i = 0; i < faceVertices.size(); i++) {
			int index = insertPoint(faceVertices[i]);
			int other = containsVertexColor(index, faceColors[i], faceNormals[i]);
			if (other != -1) {
				indicesTriangle[i] = other;
			}
			else {
				points_vertices.push_back(index);
				colors.push_back(faceColors[i]);
				indicesTriangle[i] = points_vertices.size() - 1;
			}
		}

		indices.push_back(indicesTriangle[0]);
		indices.push_back(indicesTriangle[1]);
		indices.push_back(indicesTriangle[0]);
		indices.push_back(indicesTriangle[2]);
		indices.push_back(indicesTriangle[1]);
		indices.push_back(indicesTriangle[2]);
	}
}
