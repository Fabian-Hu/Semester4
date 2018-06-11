#include "SolidSphere.h"

SolidSphere::SolidSphere(float radius, int numSplits, glm::vec3 color) : Sphere(GL_TRIANGLES, radius, numSplits, color) {}

SolidSphere::SolidSphere(glm::vec3 position, float radius, int numSplits, glm::vec3 color) :
	Sphere(GL_TRIANGLES, position, radius, numSplits, color) {}

void SolidSphere::build() {
	Model3D::build();
}
