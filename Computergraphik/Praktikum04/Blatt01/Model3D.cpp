#include "Model3D.h"
#include "glm/gtx/rotate_vector.hpp"
#include "GLTools.h"

Model3D::Model3D() :
	position(0.0f, 0.0f, 0.0f), origin (0.0f, 0.0f, 0.0f), mode(GL_TRIANGLES) {
}

Model3D::Model3D(GLenum mode) :
	position(0.0f, 0.0f, 0.0f), origin(0.0f, 0.0f, 0.0f), mode(mode) {
}

Model3D::Model3D(glm::vec3 position, GLenum mode) :
	position(position), origin(position), mode(mode) {
}

void Model3D::addChild (Model3D & model) {
	model.setOrigin (getPosition ());
	childs.push_back (&model);
}

void Model3D::addFace (Face & face) {
	faces.push_back (face);
}

void Model3D::init (cg::GLSLProgram &program) {
	calculateModel();
	GLuint programId = program.getHandle ();
	GLuint pos;

	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);

	glGenBuffers (1, &positionBuffer);
	glBindBuffer (GL_ARRAY_BUFFER, positionBuffer);
	glBufferData (GL_ARRAY_BUFFER, vertices.size () * sizeof (glm::vec3), vertices.data (), GL_STATIC_DRAW);

	pos = glGetAttribLocation (programId, "position");
	glEnableVertexAttribArray (pos);
	glVertexAttribPointer (pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers (1, &colorBuffer);
	glBindBuffer (GL_ARRAY_BUFFER, colorBuffer);
	glBufferData (GL_ARRAY_BUFFER, colors.size () * sizeof (glm::vec3), colors.data (), GL_STATIC_DRAW);

	pos = glGetAttribLocation (programId, "color");
	glEnableVertexAttribArray (pos);
	glVertexAttribPointer (pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers (1, &indexBuffer);
	glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData (GL_ELEMENT_ARRAY_BUFFER, indices.size () * sizeof (GLushort), indices.data (), GL_STATIC_DRAW);

	glBindVertexArray (0);

	model = glm::translate (glm::mat4 (1.0f), position);
}

void Model3D::render (cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection) {
	glm::mat4x4 mvp = projection * view * model;

	GLCODE(program.use ());
	GLCODE (program.setUniform ("mvp", mvp));

	GLCODE (glBindVertexArray(vao));
	GLCODE (glDrawElements(mode, faces.size() * 6, GL_UNSIGNED_SHORT, 0));
	GLCODE (glBindVertexArray(0));
}

void Model3D::build() {
	for (Face &face : faces) {
		std::vector<glm::vec3> faceVertices = face.getVertices();
		std::vector<glm::vec3> faceColors = face.getColors();
		std::vector<GLushort> faceIndices = face.getIndices();

		for (int i = 0; i < faceVertices.size(); i++) {
			int index = insertPoint(faceVertices[i]);
			int other = containsVertexColor(index, faceColors[i]);
			if (other != -1) {
				indices.push_back(other);
			} else {
				points_vertices.push_back(index);
				colors.push_back(faceColors[i]);
				indices.push_back((GLushort)points_vertices.size() - 1);
			}
		}
	}
}

int Model3D::containsVertexColor(int index, glm::vec3 & color) {
	for (int i = 0; i < points_vertices.size(); i++) {
		if (points_vertices[i] == index && colors[i] == color) {
			return i;
		}
	}
	return -1;
}

void Model3D::releaseModel(){
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &indexBuffer);
	glDeleteBuffers(1, &colorBuffer);
	glDeleteBuffers(1, &positionBuffer);
}

void Model3D::rotate(float angle, glm::vec3 direction) {
	model = glm::translate(glm::mat4(1.0f), origin) * glm::rotate(glm::mat4(1.0f), angle, direction) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-origin[0], -origin[1], -origin[2])) * model;
}

void Model3D::translate (glm::vec3 direction) {
	position += direction;
	origin += direction;
	model = glm::translate (glm::mat4 (1.0f), direction);
}

void Model3D::calculateModel () {
	vertices.clear();
	vertices.shrink_to_fit();
	for (int index: points_vertices) {
		vertices.push_back(points[index]);
	}
}

int Model3D::insertPoint(glm::vec3 &point) {
	int index = 0;
	for (glm::vec3 &vec : points) {
		if (vec[0] == point[0] && vec[1] == point[1] && vec[2] == point[2]) {
			return index;
		}
		index++;
	}
	points.push_back(point);
	return index;
}

glm::vec3 Model3D::getPosition() {
	return position;
}

void Model3D::setOrigin (glm::vec3 origin){
	this->origin = origin;
}
