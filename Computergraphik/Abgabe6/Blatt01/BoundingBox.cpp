#include "BoundingBox.h"

BoundingBox::BoundingBox()
{
}

BoundingBox::BoundingBox(ModelHE* modelHE) :
	modelHE(modelHE)
{
}

void BoundingBox::render(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection)
{
	// Create mvp.
	glm::mat4x4 mvp = projection * view * object.model;

	// Bind the shader program and set uniform(s).
	program.use();
	program.setUniform("mvp", mvp);

	// Bind vertex array object so we can render the 2 triangles.
	glBindVertexArray(object.vao);
	glDrawElements(GL_LINES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void BoundingBox::init(cg::GLSLProgram & program)
{
	build();

	GLuint programId = program.getHandle();
	GLuint pos;

	// Step 0: Create vertex array object.
	glGenVertexArrays(1, &object.vao);
	glBindVertexArray(object.vao);

	// Step 1: Create vertex buffer object for position attribute and bind it to the associated "shader attribute".
	glGenBuffers(1, &object.positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, object.positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	// Bind it to position.
	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 2: Create vertex buffer object for color attribute and bind it to...
	glGenBuffers(1, &object.colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, object.colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	// Bind it to color.
	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 3: Create vertex buffer object for indices. No binding needed here.
	glGenBuffers(1, &object.indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

	// Unbind vertex array object (back to default).
	glBindVertexArray(0);
}

void BoundingBox::releaseObject()
{
	glDeleteVertexArrays(1, &object.vao);
	glDeleteBuffers(1, &object.indexBuffer);
	glDeleteBuffers(1, &object.colorBuffer);
	glDeleteBuffers(1, &object.positionBuffer);
}

void BoundingBox::rewrite()
{

}

void BoundingBox::build()
{
	glm::vec3 farbe = glm::vec3(0.9f, 0.1f, 0.1f);
	BoundingBox::vertices.push_back(glm::vec3(0.0f));
	BoundingBox::vertices.push_back(glm::vec3(10.0f, 0.0f, 0.0f));
	BoundingBox::vertices.push_back(glm::vec3(0.0f, 10.0f, 0.0f));
	BoundingBox::vertices.push_back(glm::vec3(-20.0f, 0.0f, 0.0f));
	BoundingBox::colors.push_back(farbe);
	BoundingBox::colors.push_back(farbe);
	BoundingBox::colors.push_back(farbe);
	BoundingBox::colors.push_back(farbe);
	BoundingBox::indices.push_back(0);
	BoundingBox::indices.push_back(1);
	BoundingBox::indices.push_back(0);
	BoundingBox::indices.push_back(2);
}
