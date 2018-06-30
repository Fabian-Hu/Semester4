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

class ModelHE {
public:
	ModelHE();
	ModelHE(HE_face);

	void render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void init(cg::GLSLProgram& program);
	void releaseObject();

private:
	ObjectObject object;
	HE_face startFace;
	HE_edge startEdge;
	HE_vert startVert;
};