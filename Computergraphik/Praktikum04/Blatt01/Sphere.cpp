#include "Sphere.h"
#include <queue>
#include "math.h"

Sphere::Sphere(float radius, int numSplits, glm::vec3 color, GLenum mode) :
	Model3D(mode), radius(radius), color(color) {
	createSphere(glm::vec3(0.0f, 0.0f, 0.0f), numSplits);
}

Sphere::Sphere(glm::vec3 position, float radius, int numSplits, glm::vec3 color, GLenum mode) :
	Model3D(mode), radius(radius), color(color) {
	createSphere(position, numSplits);
}

void Sphere::createSphere(glm::vec3 position, int numSplits) {
	std::vector<Face> faces;
	for (int x = -1; x <= 1; x += 2) {
		for (int y = -1; y <= 1; y += 2) {
			for (int z = -1; z <= 1; z += 2) {
				std::vector<glm::vec3> vertices = { { 0.0f, 0.0f, radius * z},{ 0.0f, radius * y, 0.0f },{ radius * x, 0.0f, 0.0f } };
				Face triangle(vertices, color);
				faces.push_back(triangle);
			}
		}
	}

	for (int i = 0; i < numSplits; i++) {
		std::vector<Face> newFaces;
		for (int h = 0; h < faces.size(); h++) {
			Face splittedTriangle[4];
			faces[h].splitFace(splittedTriangle);
			for (int k = 0; k < 4; k++) {
				newFaces.push_back(splittedTriangle[k]);
			}
		}
		faces.clear();
		faces = newFaces;
	}

	while (!faces.empty()) {
		faces.back().normalize(getPosition(), radius);
		addFace(faces.back());
		faces.pop_back();
	}

	translate (position);
}

void Sphere::build() {
	for (Face &face : faces) {
		std::vector<glm::vec3> faceVertices = face.getVertices();
		std::vector<glm::vec3> faceColors = face.getColors();
		std::vector<GLushort> faceIndices = face.getIndices();

		GLushort indicesTriangle[3];

		for (int i = 0; i < faceVertices.size(); i++) {
			int index = insertPoint(faceVertices[i]);
			int other = containsVertexColor(index, faceColors[i]);
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
