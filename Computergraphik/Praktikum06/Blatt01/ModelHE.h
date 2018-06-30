#pragma once
#include "Model3D.h"
#include "HE_Datastructs.h"
#include <string>

class ModelHE : public Model {
public:
	ModelHE(GLenum mode, std::string modelPath, glm::vec3 color);
	ModelHE(GLenum mode, float shininess, std::string modelPath, glm::vec3 color);
	ModelHE(GLenum mode, HE_Object &heObject, glm::vec3 color);
	ModelHE(GLenum mode, glm::vec3 position, HE_Object &heObject, glm::vec3 color);
	int insertVertex(glm::vec3 vec, glm::vec3 color, glm::vec3 normal);
	void build();
	void init(cg::GLSLProgram &program);
	//void initNormals(cg::GLSLProgram &program);
	void render(cg::GLSLProgram &program, glm::mat4x4 view, glm::mat4x4 projection);

	glm::vec3 getMax();
	glm::vec3 getMin();
	HE_normal *calcNormal(HE_vert *vert);

private:
	HE_Object obj;
	glm::vec3 maxVerts;
	glm::vec3 minVerts;
	glm::vec3 initPos;
	void addVisibleNormal(HE_vert *vert, glm::vec3 &color);

	std::vector<glm::vec3> verticesNormals;
	std::vector<glm::vec3> colorNormals;
	std::vector<glm::vec3> normalNormals;
	std::vector<GLuint> intIndicesNormals;

	int size;
};
