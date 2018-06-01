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
	wireSphere.model = glm::translate(wireSphere.model, glm::vec3(x, y, z));
}

void Masterding::translate(glm::vec3 position) {
	wireSphere.model = glm::translate(wireSphere.model, position);
}

void Masterding::rotateX(float angle)
{
	glm::mat4x4 xRotatierMatrix;
	xRotatierMatrix[0] = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	xRotatierMatrix[1] = glm::vec4(0.0f, cos(-angle), -sin(-angle), 0.0f);
	xRotatierMatrix[2] = glm::vec4(0.0f, sin(-angle), cos(-angle), 0.0f);
	xRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = xRotatierMatrix * wireSphere.model;
}

void Masterding::rotateY(float angle)
{
	glm::mat4x4 yRotatierMatrix;
	yRotatierMatrix[0] = glm::vec4(cos(-angle), 0.0f, sin(-angle), 0.0f);
	yRotatierMatrix[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	yRotatierMatrix[2] = glm::vec4(-sin(-angle), 0.0f, cos(-angle), 0.0f);
	yRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = yRotatierMatrix * wireSphere.model;
}

void Masterding::rotateZ(float angle)
{
	glm::mat4x4 zRotatierMatrix;
	zRotatierMatrix[0] = glm::vec4(cos(-angle), -sin(-angle), 0.0f, 0.0f);
	zRotatierMatrix[1] = glm::vec4(sin(-angle), cos(-angle), 0.0f, 0.0f);
	zRotatierMatrix[2] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	zRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = zRotatierMatrix * wireSphere.model;
}