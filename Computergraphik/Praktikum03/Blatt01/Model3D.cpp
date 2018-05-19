#include "Model3D.h"
#include "glm/gtx/rotate_vector.hpp"

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

	model = glm::translate (glm::mat4 (1.0f), glm::vec3 (0.0f, 0.0f, 0.0f));
}

void Model3D::render (cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection) {
	glm::mat4x4 mvp = projection * view * model;

	program.use ();
	program.setUniform ("mvp", mvp);

	glBindVertexArray (vao);
	glDrawElements (GL_TRIANGLES, faces.size() * 3, GL_UNSIGNED_SHORT, 0);
	glBindVertexArray (0);
}

void Model3D::build() {
	GLushort i = 0;
	for (Face &face : faces) {
		std::vector<glm::vec3> faceVertices = face.getVertices();
		for (glm::vec3 &vec : faceVertices) {
			int index = insertPoint(vec);
			points_vertices.push_back(index);
		}

		std::vector<glm::vec3> faceColors = face.getColors();
		colors.insert(colors.end(), faceColors.begin(), faceColors.end());

		for (GLushort index : face.getIndices()) {
			indices.push_back((GLushort)(i * 3 + index));
		}
		i++;
	}
}

void Model3D::releaseModel(){
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &indexBuffer);
	glDeleteBuffers(1, &colorBuffer);
	glDeleteBuffers(1, &positionBuffer);
}

void Model3D::rotateX(float a) {
	for (int i = 0; i < points.size(); i++ ) {
		points[i] = glm::rotateX(points[i], a);
	}
}

void Model3D::rotateY(float a) {
	for (int i = 0; i < points.size(); i++) {
		points[i] = glm::rotateY(points[i], a);
	}
}

void Model3D::rotateZ(float a) {
	for (int i = 0; i < points.size(); i++) {
		points[i] = glm::rotateZ(points[i], a);
	}
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
