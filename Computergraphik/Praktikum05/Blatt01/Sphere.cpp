#include "Sphere.h"
#include <queue>
#include "math.h"

Sphere::Sphere(GLenum mode, float radius, int numSplits, glm::vec3 color) :
	Model3D(mode), radius(radius), color(color) {
	createSphere(numSplits);

}

Sphere::Sphere(GLenum mode, glm::vec3 position, float radius, int numSplits, glm::vec3 color) :
	Model3D(mode, position), radius(radius), color(color) {
	createSphere(numSplits);
}

void Sphere::createSphere(int numSplits) {
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
		faces.back().normalize(glm::vec3(0), radius);
		addFace(faces.back());
		faces.pop_back();
	}
}
