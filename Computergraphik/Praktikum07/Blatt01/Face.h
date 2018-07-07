#pragma once
#include "Model.h"

class Face : public Model {
public:
	Face();
	Face(GLenum mode);
	Face(GLenum mode, glm::vec3 position);
	Face(std::vector<glm::vec3> &vertices, glm::vec3 &color);
	Face(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &colors);
	Face(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &colors, std::vector<GLushort> &indices);

	void splitFace(Face *faces);
	void normalize(glm::vec3 middle, float distance);
	void build() {};
	void calculateNormals();

	std::vector<glm::vec3> getVertices();
	std::vector<glm::vec3> getColors();
	std::vector<GLushort> getIndices();
	std::vector<glm::vec3> getNormals();
	void setOrigin(glm::vec3 origin);

private:
	glm::vec3 splitEdge(glm::vec3 &vert1, glm::vec3 &vert2);
	glm::vec3 origin;
};
