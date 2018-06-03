#include "MasterDing.h"

Masterding::Masterding()
{
}

void Masterding::render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection)
{
}

void Masterding::init(cg::GLSLProgram& program)
{
}

/*
Release object resources.
*/
void Masterding::releaseObject()
{
	glDeleteVertexArrays(1, &wireSphere.vao);
	glDeleteBuffers(1, &wireSphere.indexBuffer);
	glDeleteBuffers(1, &wireSphere.colorBuffer);
	glDeleteBuffers(1, &wireSphere.positionBuffer);
}

void Masterding::translate(float x, float y, float z) {
	wireSphere.model = glm::translate(glm::mat4x4(1.0f), glm::vec3(x, y, z)) * wireSphere.model;
}

void Masterding::translate(glm::vec3 position) {
	wireSphere.model = glm::translate(glm::mat4x4(1.0f), position) * wireSphere.model;
}

float Masterding::degreeToRadians(float angle) {
	return (angle * PI / 180);
}

void Masterding::rotateX(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 xRotatierMatrix;
	xRotatierMatrix[0] = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	xRotatierMatrix[1] = glm::vec4(0.0f, cos(-radians), -sin(-radians), 0.0f);
	xRotatierMatrix[2] = glm::vec4(0.0f, sin(-radians), cos(-radians), 0.0f);
	xRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = xRotatierMatrix * wireSphere.model;
}

void Masterding::rotateY(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 yRotatierMatrix;
	yRotatierMatrix[0] = glm::vec4(cos(-radians), 0.0f, sin(-radians), 0.0f);
	yRotatierMatrix[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	yRotatierMatrix[2] = glm::vec4(-sin(-radians), 0.0f, cos(-radians), 0.0f);
	yRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = yRotatierMatrix * wireSphere.model;
}

void Masterding::rotateZ(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 zRotatierMatrix;
	zRotatierMatrix[0] = glm::vec4(cos(-radians), -sin(-radians), 0.0f, 0.0f);
	zRotatierMatrix[1] = glm::vec4(sin(-radians), cos(-radians), 0.0f, 0.0f);
	zRotatierMatrix[2] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	zRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = zRotatierMatrix * wireSphere.model;
}