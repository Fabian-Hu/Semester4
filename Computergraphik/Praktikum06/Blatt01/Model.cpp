#include "Model.h"
#include "GLTools.h"
#include "glm/gtx/rotate_vector.hpp"
#include <GL/glew.h>

#include <glm/gtc/matrix_inverse.hpp>

Model::Model() : Model(GL_LINES) {}

Model::Model(GLenum mode) : Model(mode, glm::vec3(0, 0, 0)){}

Model::Model(GLenum mode, glm::vec3 position) : mode(mode), position(position), active(true), showNormals(false) {
	material = glm::vec3(1.0f);
	shininess = 128;
}

void Model::init(cg::GLSLProgram & program) {
	GLuint programId = program.getHandle();
	GLuint pos;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//Position
	glGenBuffers(1, &positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//Color
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//Normal
	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), normals.data(), GL_STATIC_DRAW);

	pos = glGetAttribLocation(programId, "normal");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//Index
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	if (indices.size() > 0) {
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
	} else {
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, intIndices.size() * sizeof(GLuint), intIndices.data(), GL_STATIC_DRAW);
	}

	glBindVertexArray(0);

	model = glm::translate(glm::mat4(1.0f), position);
}

void Model::render(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection) {
	if (active) {
		glm::mat4x4 mvp = projection * view * model;

		// Create normal matrix (nm) from model matrix.
		glm::mat3 nm = glm::inverseTranspose(glm::mat3(model));

		program.use();
		program.setUniform("mvp", mvp);
		program.setUniform("nm", nm);
		/*program.setUniform("model", model);
		program.setUniform("material", material);
		program.setUniform("shininess", shininess);*/

		glBindVertexArray(vao);
		if (indices.size() > 0) {
			glDrawElements(mode, indices.size(), GL_UNSIGNED_SHORT, 0);
		}
		else {
			glDrawElements(mode, intIndices.size(), GL_UNSIGNED_INT, 0);
		}
		glBindVertexArray(0);
		if (showNormals) {
			glBindVertexArray(vaoNormals);
			if (vertices.size() * 2 <= std::numeric_limits<GLushort>::max()) {
				glDrawElements(GL_LINES, vertices.size() * 2, GL_UNSIGNED_SHORT, 0);
			}
			else {
				glDrawElements(GL_LINES, vertices.size() * 2, GL_UNSIGNED_INT, 0);
			}
			glBindVertexArray(0);
		}
	}
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

void Model::scale(glm::vec3 direction, float value = 1.0f) {
	model = glm::scale(glm::mat4(1.0f), glm::vec3(value)) * model;
}

void Model::scaleLocal(float value) {
	scale(position, value);
}

void Model::initNormals(cg::GLSLProgram program) {
	std::vector<glm::vec3> vertices = this->vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices;
	std::vector<GLuint> intIndices;
	for (int i = 0; i < this->vertices.size(); i++) {
		colors.push_back(glm::vec3(1.0f) - this->colors[0]);
		if (this->vertices.size() * 2 <= std::numeric_limits<GLushort>::max()) {
			indices.push_back(i);
			indices.push_back(vertices.size());
		} else {
			intIndices.push_back(i);
			intIndices.push_back(vertices.size());
		}
		vertices.push_back(vertices[i] + glm::normalize(this->normals[i]) * 1.0f);
	}
	std::vector<glm::vec3> normals = this->normals;
	for (glm::vec3 normal : normals) {
		colors.push_back(glm::vec3(1.0f) - this->colors[0]);
		normals.push_back(normal);
	}

	GLuint programId = program.getHandle();
	GLuint pos;

	glGenVertexArrays(1, &vaoNormals);
	glBindVertexArray(vaoNormals);

	//Position
	glGenBuffers(1, &positionBufferNormals);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferNormals);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//Color
	glGenBuffers(1, &colorBufferNormals);
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferNormals);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//Normal
	GLCODE(glGenBuffers(1, &normalBufferNormals));
	GLCODE(glBindBuffer(GL_ARRAY_BUFFER, normalBufferNormals));
	GLCODE(glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), normals.data(), GL_STATIC_DRAW));

	pos = glGetAttribLocation(programId, "normal");
	GLCODE(glEnableVertexAttribArray(pos));
	GLCODE(glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0));

	//Index
	glGenBuffers(1, &indexBufferNormals);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferNormals);
	if (vertices.size() <= std::numeric_limits<GLushort>::max()) {
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertices.size() * sizeof(GLushort), indices.data(), GL_STATIC_DRAW);
	} else {
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertices.size() * sizeof(GLuint), intIndices.data(), GL_STATIC_DRAW);
	}
	
	glBindVertexArray(0);
}

void Model::setNormals(bool show) {
	showNormals = show;
}

void Model::setActive(bool active) {
	this->active = active;
}

bool Model::isActive() {
	return this->active;
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

glm::vec3 Model::getMaxVertPosition()
{
	glm::vec3 maxVertPos(FLT_MIN);
	for (glm::vec3 curVert : vertices) {
		if (curVert.x > maxVertPos.x)
			maxVertPos.x = curVert.x;
		if (curVert.y > maxVertPos.y)
			maxVertPos.y = curVert.y;
		if (curVert.z > maxVertPos.z)
			maxVertPos.z = curVert.z;
	}
	return maxVertPos;
}

glm::vec3 Model::getMinVertPosition()
{
	glm::vec3 minVertPos(FLT_MAX);
	for (glm::vec3 curVert : vertices) {
		if (curVert.x < minVertPos.x)
			minVertPos.x = curVert.x;
		if (curVert.y < minVertPos.y)
			minVertPos.y = curVert.y;
		if (curVert.z < minVertPos.z)
			minVertPos.z = curVert.z;
	}
	return minVertPos;
}

bool Model::getNormalsStatus() {
	return showNormals;
}
