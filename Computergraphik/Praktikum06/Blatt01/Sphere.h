#pragma once
#include "Model3D.h"

class Sphere : public Model3D {
public: 
	Sphere(GLenum mode, float radius, int numSplits, glm::vec3 color);
	Sphere(GLenum mode, glm::vec3 position, float radius, int numSplits, glm::vec3 color);
	virtual void build() = 0;

private:
	float radius;
	glm::vec3 color;
	void createSphere(int numSplits);

};
