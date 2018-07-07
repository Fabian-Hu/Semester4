#pragma once
#include "Model.h"

class Axis : public Model {
public:
	Axis();
	Axis(glm::vec3 position, glm::vec3 point1, glm::vec3 point2);
	Axis(glm::vec3 position, float length);
	Axis(glm::vec3 position, float length, glm::vec3 color);
	void build();

private:
	float length;
};