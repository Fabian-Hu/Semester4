#pragma once
#include "MasterDing.h"
#include "Halfedge.h"

struct ObjectObject
{
	/* IDs for several buffers. */
	GLuint vao;

	GLuint positionBuffer;
	GLuint colorBuffer;

	GLuint indexBuffer;

	/* Model matrix */
	glm::mat4x4 model;
};

struct MaxiZahlen {
	float xMax;
	float xMin;

	float yMax;
	float yMin;

	float zMax;
	float zMin;

	float xMiddle;
	float xDiff;

	float yMiddle;
	float yDiff;

	float zMiddle;
	float zDiff;
};

class ModelHE {
public:
	ModelHE();
	ModelHE(HalfEdgeList *halfEdgeList);

	void render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void init(cg::GLSLProgram& program);
	void releaseObject();

	void calculate();
	void calculateMaxNums();
	float maxDiff();

	float degreeToRadians(float angle);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	MaxiZahlen getMaxiZahlen();

private:
	ObjectObject object;
	HE_face startFace;
	HE_edge startEdge;
	HE_vert startVert;
	HalfEdgeList *halfEdgeList;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLuint> indices;
	MaxiZahlen maxNums;
};