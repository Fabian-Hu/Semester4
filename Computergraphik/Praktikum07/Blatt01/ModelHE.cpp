#include "ModelHE.h"
#include "ObjParser.h"
#include <glm/gtc/matrix_inverse.hpp>
#include <limits>
#include <GL/glew.h>
#include "GLSLProgram.h"
#include "glm/gtx/rotate_vector.hpp"

ModelHE::ModelHE(GLenum mode, std::string modelPath, glm::vec3 color) :
	Model(mode), initPos(glm::vec3(0.0f)) {
	textured = true;
	ObjParser parser;
	parser.parseObj(modelPath, obj);
	obj.testAll();
	this->colors.push_back(color);
	size = obj.edges.size();
	maxVerts = glm::vec3(std::numeric_limits<float>::min());
	minVerts = glm::vec3(std::numeric_limits<float>::max());
}

ModelHE::ModelHE(GLenum mode, float shininess, std::string modelPath, glm::vec3 color) :
	Model(mode, glm::vec3(0.0f), shininess) {
	textured = true;
	ObjParser parser;
	parser.parseObj(modelPath, obj);
	obj.testAll();
	this->colors.push_back(color);
	size = obj.edges.size();
	maxVerts = glm::vec3(std::numeric_limits<float>::min());
	minVerts = glm::vec3(std::numeric_limits<float>::max());
}

ModelHE::ModelHE(GLenum mode, HE_Object &heObject, glm::vec3 color) :
	Model(mode), initPos(glm::vec3(0.0f)) {
	textured = true;
	this->obj = heObject;
	size = obj.edges.size();
	maxVerts = glm::vec3(std::numeric_limits<float>::min());
	minVerts = glm::vec3(std::numeric_limits<float>::max());
}

ModelHE::ModelHE(GLenum mode, glm::vec3 position, HE_Object &heObject, glm::vec3 color) :
	Model(mode), initPos(position) {
	textured = true;
	this->obj = heObject;
	size = obj.edges.size();
	maxVerts = glm::vec3(std::numeric_limits<float>::min());
	minVerts = glm::vec3(std::numeric_limits<float>::max());
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
	glm::vec3 color = colors[0];
	colors.clear();
	for (HE_face *face : obj.face) {
		HE_edge *startEdge = face->edge;
		HE_edge *next = startEdge;

		std::vector<int> faceIndices;
		do {
			maxVerts[0] = (next->vert->x > maxVerts[0]) ? next->vert->x : maxVerts[0];
			maxVerts[1] = (next->vert->y > maxVerts[1]) ? next->vert->y : maxVerts[1];
			maxVerts[2] = (next->vert->z > maxVerts[2]) ? next->vert->z : maxVerts[2];
			minVerts[0] = (next->vert->x < minVerts[0]) ? next->vert->x : minVerts[0];
			minVerts[1] = (next->vert->y < minVerts[1]) ? next->vert->y : minVerts[1];
			minVerts[2] = (next->vert->z < minVerts[2]) ? next->vert->z : minVerts[2];

			HE_texCoord *tex = nullptr;
			if (next->texCoord == nullptr) {
				if (next->vert->texCoords.size() > 0) {
					tex = next->vert->texCoords[0];
				}
			} else {
				tex = next->texCoord;
			}

			HE_normal *normal;
			if (next->normal == nullptr) {
				if (next->vert->approxNormal.size() == 0) {
					normal = calcNormal(next->vert);
				} else {
					normal = next->vert->approxNormal[0];
				}
			} else {
				normal = next->normal;
			}
			
			int found = -1;
			int length = 0;
			if (tex != nullptr) {
				length = (next->vert->approxNormal.size() < next->vert->texCoords.size()) ? next->vert->approxNormal.size() : next->vert->texCoords.size();
			} else {
				length = next->vert->approxNormal.size();
			}
			for (int i = 0; i < length; i++) {
				if (tex == nullptr && next->vert->approxNormal[i] == normal) {
					faceIndices.push_back(next->vert->pos[i]);
					i = next->vert->approxNormal.size();
					found = i;
				} else if (next->vert->approxNormal[i] == normal && next->vert->texCoords[i] == tex) {
					faceIndices.push_back(next->vert->pos[i]);
					i = next->vert->approxNormal.size();
					found = i;
				}
			}
			if (found == -1) {
				next->vert->pos.push_back(vertices.size());
				next->vert->approxNormal.push_back(normal);

				faceIndices.push_back(next->vert->pos.back());
				vertices.push_back(glm::vec3(next->vert->x, next->vert->y, next->vert->z));
				normals.push_back(normalize(glm::vec3(normal->x, normal->y, normal->z)));
				if (tex != nullptr) {
					next->vert->texCoords.push_back(tex);
					texCoords.push_back(glm::vec2(tex->x, tex->y));
				}

				/*NORMALS BERECHNEN!!!*/
				addVisibleNormal(next->vert, color);
			}
			
			colors.push_back(color);
			next = next->next;
		} while (next != startEdge);

		int first = 0;
		int second = 1;
		int third = faceIndices.size() - 1;
		for (int i = 0; i < faceIndices.size() - 2; i++) {
			if (size <= std::numeric_limits<GLushort>::max()) {
				indices.push_back(faceIndices[first]);
				indices.push_back(faceIndices[second]);
				indices.push_back(faceIndices[third]);
			}
			else {
				intIndices.push_back(faceIndices[first]);
				intIndices.push_back(faceIndices[second]);
				intIndices.push_back(faceIndices[third]);
			}
			first = second;
			second = third;
			if (first < second) {
				third = first + 1;
			} else {
				third = first - 1;
			}
		}
	}
	position = glm::vec3(minVerts + (maxVerts - minVerts) * 0.5f);
	textured = texCoords.size() != 0;
}

void ModelHE::init(cg::GLSLProgram & program) {
	glm::vec3 pos = position;
	position = glm::vec3(0.0f);
	Model::init(program);
	position = pos;
}

void ModelHE::initNormals(cg::GLSLProgram &program) {
	std::vector<GLushort> empty;
	defaultInit(program, vaoNormals, positionBufferNormals, colorBufferNormals, indexBufferNormals, normalBufferNormals, verticesNormals, colorNormals, normalNormals, empty, intIndicesNormals);
}

void ModelHE::initFaceNormals(cg::GLSLProgram & program) {
	std::vector<GLushort> indices;
	defaultInit(program, vaoFaceNormals, positionBufferFaceNormals, colorBufferFaceNormals, indexBufferFaceNormals, normalBufferFaceNormals, verticesFaceNormals, colorFaceNormals, normalFaceNormals, indices, intIndicesFaceNormals);
}

void ModelHE::render(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection) {
	if (active) {
		glm::mat4x4 mvp = projection * view * model;
		glm::mat4x4 modelView = view * model;

		// Create normal matrix (nm) from model matrix.
		glm::mat3 nm = glm::inverseTranspose(glm::mat3(model));

		// Bind texture object to unit GL_TEXTURE0
		texture.use();

		program.use();
		program.setUniform("modelviewMatrix", modelView);
		program.setUniform("projectionMatrix", projection);
		program.setUniform("normalMatrix", nm);
		program.setUniform("surfShininess", shininess);
		program.setUniform("textured", textured);

		glBindVertexArray(vao);
		if (indices.size() > 0) {
			glDrawElements(mode, indices.size(), GL_UNSIGNED_SHORT, 0);
		}
		else {
			glDrawElements(mode, intIndices.size(), GL_UNSIGNED_INT, 0);
		}
		glBindVertexArray(0);

		// Unbind texture object to unit GL_TEXTURE0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);

		if (showNormals) {
			glBindVertexArray(vaoNormals);
			glDrawElements(GL_LINES, vertices.size() * 2, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
		if (showFaceNormals && active) {
			glBindVertexArray(vaoFaceNormals);
			glDrawElements(GL_LINES, intIndicesFaceNormals.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	}
}

void ModelHE::setFaceNormals(bool show) {
	showFaceNormals = show;
}

bool ModelHE::getFaceNormalsStatus() {
	return showFaceNormals;
}

glm::vec3 ModelHE::getMax() { 
	return maxVerts;
}

glm::vec3 ModelHE::getMin() { 
	return minVerts; 
}

HE_normal *ModelHE::calcNormal(HE_vert *vert) {
	glm::vec3 vertVec(vert->x, vert->y, vert->z);
	std::vector<glm::vec3> faceVerts;
	std::vector<glm::vec3> faceNormals;
	HE_edge *startEdge = vert->edge;
	HE_edge *next = vert->edge;

	do {
		next = next->pair;
		faceVerts.push_back(glm::vec3(next->vert->x, next->vert->y, next->vert->z));
		next = next->next;
		if (faceVerts.size() > 1) {
			faceNormals.push_back(glm::cross(faceVerts.back() - vertVec, faceVerts[faceVerts.size() - 2] - vertVec));
		}
	} while (next != startEdge);
	faceNormals.push_back(glm::cross(faceVerts.front() - vertVec, faceVerts.back() - vertVec));

	glm::vec3 normal;
	for (glm::vec3 n : faceNormals) {
		normal += n;
	}
	normal *= (1.0f / (float)faceNormals.size());

	HE_normal *heNormal = new HE_normal;
	heNormal->x = normal.x;
	heNormal->y = normal.y;
	heNormal->z = normal.z;
	return heNormal;
}

void ModelHE::addVisibleNormal(HE_vert * vert, glm::vec3 & color) {
	intIndicesNormals.push_back(verticesNormals.size());
	verticesNormals.push_back(vertices.back());
	intIndicesNormals.push_back(verticesNormals.size());
	verticesNormals.push_back(vertices.back() + normals.back());
	colorNormals.push_back(glm::vec3(1.0f) - color);
	colorNormals.push_back(glm::vec3(1.0f) - color);
	normalNormals.push_back(normals.back());
	normalNormals.push_back(normals.back());

	HE_edge *startEdge = vert->edge;
	HE_edge *next = vert->edge;
	std::vector<glm::vec3> faceVerts;

	int firstVert = verticesFaceNormals.size();
	verticesFaceNormals.push_back(glm::vec3(vert->x, vert->y, vert->z));
	normalFaceNormals.push_back(normals.back());
	colorFaceNormals.push_back(glm::vec3(color.y, color.z, color.x));
	glm::vec3 vertVec(vert->x, vert->y, vert->z);

	do {
		next = next->pair;
		faceVerts.push_back(glm::vec3(next->vert->x, next->vert->y, next->vert->z));
		next = next->next;
		if (faceVerts.size() > 1) {
			intIndicesFaceNormals.push_back(firstVert);
			intIndicesFaceNormals.push_back(verticesFaceNormals.size());

			glm::vec3 faceNormal(normalize(cross(faceVerts.back() - vertVec, faceVerts[faceVerts.size() - 2] - vertVec)));
			verticesFaceNormals.push_back(vertVec + faceNormal);
			//verticesFaceNormals.push_back(glm::vec3(next->vert->x, next->vert->y, next->vert->z)); 
			normalFaceNormals.push_back(faceNormal);
			colorFaceNormals.push_back(glm::vec3(color.y, color.z, color.x));
		}
	} while (next != startEdge);
	intIndicesFaceNormals.push_back(firstVert);
	intIndicesFaceNormals.push_back(verticesFaceNormals.size());

	glm::vec3 faceNormal(normalize(cross(faceVerts.front() - vertVec, faceVerts.back() - vertVec)));
	verticesFaceNormals.push_back(vertVec + faceNormal);
	normalFaceNormals.push_back(faceNormal);
	colorFaceNormals.push_back(glm::vec3(color.y, color.z, color.x));
}
