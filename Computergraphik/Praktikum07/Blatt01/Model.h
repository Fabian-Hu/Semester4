#pragma once
#include <vector>
#include "GLSLProgram.h"
#include "TextureObject.h"

class Model {
public:
	Model();
	Model(GLenum mode);
	Model(GLenum mode, glm::vec3 position);
	Model(GLenum mode, glm::vec3 position, float shininess);
	Model(GLenum mode, glm::vec3 position, float shininess, std::string &path);

	virtual void init(cg::GLSLProgram &program);
	virtual void build() = 0;
	virtual void render(cg::GLSLProgram &program, glm::mat4x4 view, glm::mat4x4 projection);
	virtual void releaseModel();
	virtual void rotate(float a, glm::vec3 direction, glm::vec3 point);
	virtual void rotateCenter(float a, glm::vec3 direction);
	virtual void translate(glm::vec3 direction);
	virtual void scale(glm::vec3 direction, float value);
	virtual void scaleLocal(float value);
	virtual void initNormals(cg::GLSLProgram program);

	void setNormals(bool show);
	void setActive(bool active = true);
	bool isActive();

	void setVertices(std::vector<glm::vec3> &vertices);
	void setColors(std::vector<glm::vec3> &colors);
	void setIndices(std::vector<GLushort> &indices);
	void setPosition(glm::vec3 position);
	glm::vec3 getPosition();
	bool getNormalsStatus();

private:
	friend class Model3D;
	friend class ModelHE;
	friend class Sphere;
	friend class WireframeSphere;
	friend class Face;
	friend class Axis;
	friend class WireframeBox;
	friend class ModelHE;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices;
	std::vector<glm::vec3> normals;
	std::vector<GLuint> intIndices;
	std::vector<glm::vec2> texCoords;

	GLuint vao;

	GLuint positionBuffer;
	GLuint colorBuffer;
	GLuint indexBuffer;
	GLuint normalBuffer;

	bool showNormals;
	GLuint vaoNormals;

	GLuint positionBufferNormals;
	GLuint colorBufferNormals;
	GLuint indexBufferNormals;
	GLuint normalBufferNormals;

	glm::vec3 position;
	glm::mat4x4 model;

	GLenum mode;

	float shininess;
	TextureObject texture;

	void defaultInit(cg::GLSLProgram & program, GLuint & vao, GLuint & positionBuffer, GLuint & colorBuffer, GLuint & indexBuffer, GLuint & normalBuffer,
		std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& colors, std::vector<glm::vec3>& normals, std::vector<GLushort>& indices, std::vector<GLuint>& intIndices, std::vector<glm::vec2> &texCoords = std::vector<glm::vec2>(), bool textured = false);

	std::string imagePath;
	bool textured;
	bool genTexture;
	glm::vec3 texCenterAxis;
	glm::vec3 texOrigin;

	bool active;
};