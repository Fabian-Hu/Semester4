#include "ModelHE.h"
#include "ObjParser.h"
#include <limits>

ModelHE::ModelHE(GLenum mode, std::string modelPath, glm::vec3 color) :
	Model(mode) {
	ObjParser parser;
	parser.parseObj(modelPath, obj);
	obj.testAll();
	this->colors.push_back(color);
}

ModelHE::ModelHE(GLenum mode, HE_Object &heObject, glm::vec3 color) :
	Model(mode) {
	this->obj = heObject;
}

ModelHE::ModelHE(GLenum mode, glm::vec3 position, HE_Object &heObject, glm::vec3 color) :
	Model(mode, position) {
	this->obj = heObject;
}

int ModelHE::insertVertex(glm::vec3 vec, glm::vec3 color, glm::vec3 normal) {
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i] == vec && colors[i] == color && normals[i] == normal) {
			return i;
		}
	}
	vertices.push_back(vec);
	colors.push_back(color);
	normals.push_back(normal);
	return vertices.size() - 1;
}

void ModelHE::build() {
	float highestX = std::numeric_limits<float>::min();
	float lowestX = std::numeric_limits<float>::min();
	float highestY = std::numeric_limits<float>::min();
	float lowestY = std::numeric_limits<float>::max();
	float highestZ = std::numeric_limits<float>::max();
	float lowestZ = std::numeric_limits<float>::max();
	glm::vec3 color = colors[0];
	colors.clear();
	for (HE_face *face : obj.face) {
		HE_edge *startEdge = face->edge;
		HE_edge *next = startEdge;

		std::vector<int> faceIndices;
		do {
			highestX = (next->vert->x > highestX) ? next->vert->x : highestX;
			highestY = (next->vert->y > highestX) ? next->vert->y : highestX;
			highestZ = (next->vert->z > highestX) ? next->vert->z : highestX;
			lowestX = (next->vert->x < lowestX) ? next->vert->x : lowestX;
			lowestY = (next->vert->y < lowestY) ? next->vert->y : lowestY;
			lowestZ = (next->vert->z < lowestZ) ? next->vert->z : lowestZ;

			faceIndices.push_back(vertices.size());
			vertices.push_back(glm::vec3(next->vert->x, next->vert->y, next->vert->z));
			colors.push_back(color);
			next = next->next;
		} while (next != startEdge);

		int first = 0;
		int second = 1;
		int third = faceIndices.size() - 1;
		for (int i = 0; i < faceIndices.size() - 2; i++) {
			indices.push_back(faceIndices[first]);
			indices.push_back(faceIndices[second]);
			indices.push_back(faceIndices[third]);
			first = second;
			second = third;
			if (first < second) {
				third = first + 1;
			}
			else {
				third = first - 1;
			}
		}
	}
	origin = glm::vec3(lowestX + (highestX - lowestX) / 2,
		lowestY + (highestY - lowestY) / 2,
		lowestZ + (highestZ - lowestZ) / 2);

	for (int i = 0; i < vertices.size(); i++) {
		normals.push_back(normalize(vertices[i] - origin));
	}
}

void ModelHE::init(cg::GLSLProgram & program) {
	glm::vec3 pos = position;
	position = glm::vec3(0.0f);
	Model::init(program);

	this->translate(-origin);
	this->translate(pos);
	position = pos;
}
