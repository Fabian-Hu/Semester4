#include "Model3D.h"
#include "glm/gtx/rotate_vector.hpp"
#include "GLTools.h"

Model3D::Model3D(GLenum mode) : Model(mode) {}

Model3D::Model3D(GLenum mode, glm::vec3 position) : Model(mode, position) {}

void Model3D::addFace (Face & face) {
	faces.push_back (face);
}

void Model3D::init (cg::GLSLProgram &program) {
	calculateModel();
	Model::init(program);
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
