#include "Achse.h"

Achse::Achse() :
	position(0.0f, 0.0f, 0.0f)
{
}

Achse::Achse(float x, float y, float z, float laenge) :
	position(x, y, z), laenge(laenge)
{
}

Achse::Achse(float x, float y, float z, float laenge, float schiefigkeit) :
	position(x, y, z), laenge(laenge), schiefigkeitus(schiefigkeit)
{
}

void Achse::render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection)
{
	// Create mvp.
	glm::mat4x4 mvp = projection * view * wireSphere.model;

	// Bind the shader program and set uniform(s).
	program.use();
	program.setUniform("mvp", mvp);

	// Bind vertex array object so we can render the 2 triangles.
	glBindVertexArray(wireSphere.vao);
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
}

void Achse::init(cg::GLSLProgram& program)
{
	// Construct triangle. These vectors can go out of scope after we have send all data to the graphics card.
	const std::vector<glm::vec3> vertices = { glm::vec3(-0.05f, laenge, 0.0f), glm::vec3(-0.05f, -laenge, 0.0f), glm::vec3(0.05f, 0.0f, 0.0f) };
	const std::vector<glm::vec3> colors = { glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f) };
	const std::vector<GLushort> indices = { 0, 1, 2 };

	GLuint programId = program.getHandle();
	GLuint pos;

	// Step 0: Create vertex array object.
	glGenVertexArrays(1, &wireSphere.vao);
	glBindVertexArray(wireSphere.vao);

	// Step 1: Create vertex buffer object for position attribute and bind it to the associated "shader attribute".
	glGenBuffers(1, &wireSphere.positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, wireSphere.positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	// Bind it to position.
	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 2: Create vertex buffer object for color attribute and bind it to...
	glGenBuffers(1, &wireSphere.colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, wireSphere.colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	// Bind it to color.
	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 3: Create vertex buffer object for indices. No binding needed here.
	glGenBuffers(1, &wireSphere.indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, wireSphere.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), indices.data(), GL_STATIC_DRAW);

	// Unbind vertex array object (back to default).
	glBindVertexArray(0);

	// Modify model matrix.
	// zur richtigen Startposition
	wireSphere.model = glm::mat4(1.0f);

	if (schiefigkeitus != 0) {
		rotateZ(schiefigkeitus);
	}

	translate(position);
}

/*
Release object resources.
*/
void Achse::releaseObject()
{
	glDeleteVertexArrays(1, &wireSphere.vao);
	glDeleteBuffers(1, &wireSphere.indexBuffer);
	glDeleteBuffers(1, &wireSphere.colorBuffer);
	glDeleteBuffers(1, &wireSphere.positionBuffer);
}

void Achse::translate(float x, float y, float z) {
	wireSphere.model = glm::translate(glm::mat4x4(1.0f), glm::vec3(x, y, z)) * wireSphere.model;
}

void Achse::translate(glm::vec3 position) {
	wireSphere.model = glm::translate(glm::mat4x4(1.0f), position) * wireSphere.model;
}

float Achse::degreeToRadians(float angle) {
	return (angle * PI / 180);
}

void Achse::rotateX(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 xRotatierMatrix;
	xRotatierMatrix[0] = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	xRotatierMatrix[1] = glm::vec4(0.0f, cos(-radians), -sin(-radians), 0.0f);
	xRotatierMatrix[2] = glm::vec4(0.0f, sin(-radians), cos(-radians), 0.0f);
	xRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = xRotatierMatrix * wireSphere.model;
}

void Achse::rotateY(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 yRotatierMatrix;
	yRotatierMatrix[0] = glm::vec4(cos(-radians), 0.0f, sin(-radians), 0.0f);
	yRotatierMatrix[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	yRotatierMatrix[2] = glm::vec4(-sin(-radians), 0.0f, cos(-radians), 0.0f);
	yRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = yRotatierMatrix * wireSphere.model;
}

void Achse::rotateZ(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 zRotatierMatrix;
	zRotatierMatrix[0] = glm::vec4(cos(-radians), -sin(-radians), 0.0f, 0.0f);
	zRotatierMatrix[1] = glm::vec4(sin(-radians), cos(-radians), 0.0f, 0.0f);
	zRotatierMatrix[2] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	zRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = zRotatierMatrix * wireSphere.model;
}