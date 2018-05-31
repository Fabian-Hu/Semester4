#pragma once
#include "Model3D.h"

class Sphere : public Model3D {
public: 
	Sphere(float radius, int numSplits, glm::vec3 color, GLenum mode);
	Sphere(glm::vec3 position, float radius, int numSplits, glm::vec3 color, GLenum mode);
	void build();

private:
	float radius;
	glm::vec3 color;
	void createSphere(glm::vec3 position, int numSplits);

};
