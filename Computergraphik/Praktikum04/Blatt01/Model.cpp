#include "Model.h"
#include "GLTools.h"
#include "glm/gtx/rotate_vector.hpp"

Model::Model() : Model(GL_LINES) {}

Model::Model(GLenum mode) : Model(mode, glm::vec3(0, 0, 0)){}

Model::Model(GLenum mode, glm::vec3 position) : mode(mode), position(position) {}

void Model::init(cg::GLSLProgram & program) {
	GLuint programId = program.getHandle();
	GLuint pos;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), indices.data(), GL_STATIC_DRAW);

	glBindVertexArray(0);

	model = glm::translate(glm::mat4(1.0f), position);
}

void Model::render(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection) {
	glm::mat4x4 mvp = projection * view * model;

	program.use();
	program.setUniform("mvp", mvp);

	glBindVertexArray(vao);
	glDrawElements(mode, indices.size(), GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
}

void Model::releaseModel() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &indexBuffer);
	glDeleteBuffers(1, &colorBuffer);
	glDeleteBuffers(1, &positionBuffer);
}

void Model::rotate(float a, glm::vec3 direction, glm::vec3 point) {
	glm::vec4 positionPoint(position[0], position[1], position[2], 1);
	model = glm::translate(glm::mat4(1.0f), point) * glm::rotate(glm::mat4(1.0f), a, direction) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-point[0], -point[1], -point[2])) * model;
	//Try to get position out of the model
	position = glm::translate(glm::mat4(1.0f), point) * glm::rotate(glm::mat4(1.0f), a, direction) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-point[0], -point[1], -point[2])) * positionPoint;
}

void Model::rotateCenter(float a, glm::vec3 direction) {
	rotate(a, direction, position);
}

void Model::translate(glm::vec3 direction) {
	//Try to get Position out of model
	position += direction;
	model = glm::translate(glm::mat4(1.0f), direction) * model;
}

void Model::setVertices(std::vector<glm::vec3> &vertices) {
	this->vertices = vertices;
}

void Model::setColors(std::vector<glm::vec3>& colors) {
	this->colors = colors;
}

void Model::setIndices(std::vector<GLushort>& indices) {
	this->indices = indices;
}

void Model::setPosition(glm::vec3 position) {
	this->position = position;
}

glm::vec3 Model::getPosition() {
	return position;
}
