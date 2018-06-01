#include "Himmelsding.h"

Himmelsding::Himmelsding() :
	position(0.0f, 0.0f, 0.0f)
{
}

Himmelsding::Himmelsding(float x, float y, float z, float radio) :
	position(x, y, z), radius(radio)
{
}

Himmelsding::Himmelsding(float x, float y, float z, float radio, float schiefigkeit) :
	position(x, y, z), radius(radio), schiefigkeitus(schiefigkeit)
{
}

void Himmelsding::renderWireSphere(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection)
{
	// Create mvp.
	glm::mat4x4 mvp = projection * view * wireSphere.model;

	// Bind the shader program and set uniform(s).
	program.use();
	program.setUniform("mvp", mvp);

	// GLUT: bind vertex-array-object
	// this vertex-array-object must be bound before the glutWireSphere call
	glBindVertexArray(wireSphere.vao);

    //glLineWidth(1.0f);
	glutWireSphere(radius, 20, 20);

	// GLUT: unbind vertex-array-object
	glBindVertexArray(0);
}

void Himmelsding::initWireSphere(cg::GLSLProgram& program)
{
	// set attribute locations (of shader) for GLUT
	GLuint programId = program.getHandle();
	// position attribute to variable "position"
	glutSetVertexAttribCoord3(glGetAttribLocation(programId, "position"));
	// normal attribute to variable "color"
	// this creates a colorful sphere :-)
	glutSetVertexAttribNormal(glGetAttribLocation(programId, "color"));
	// create a vertex-array-object for GLUT geometry
	glGenVertexArrays(1, &wireSphere.vao);

	// Modify model matrix.
	// zur richtigen Startposition
	wireSphere.model = glm::mat4(1.0f);
	rotateX(360);
	rotateZ(-schiefigkeitus);

	translate(position);
}


/*
 Release object resources.
*/
void Himmelsding::releaseObject()
{
	glDeleteVertexArrays(1, &wireSphere.vao);
	glDeleteBuffers(1, &wireSphere.indexBuffer);
	glDeleteBuffers(1, &wireSphere.colorBuffer);
	glDeleteBuffers(1, &wireSphere.positionBuffer);
}

void Himmelsding::translate(float x, float y, float z) {
	wireSphere.model = glm::translate(wireSphere.model, glm::vec3(x, y, z));
}

void Himmelsding::translate(glm::vec3 position) {
	wireSphere.model = glm::translate(wireSphere.model, position);
}

void Himmelsding::rotateX(float angle)
{
	glm::mat4x4 xRotatierMatrix;
	xRotatierMatrix[0] = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	xRotatierMatrix[1] = glm::vec4(0.0f, cos(-angle), -sin(-angle), 0.0f);
	xRotatierMatrix[2] = glm::vec4(0.0f, sin(-angle), cos(-angle), 0.0f);
	xRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = xRotatierMatrix * wireSphere.model;
}
	
void Himmelsding::rotateY(float angle)
{
	glm::mat4x4 yRotatierMatrix;
	yRotatierMatrix[0] = glm::vec4(cos(-angle), 0.0f, sin(-angle), 0.0f);
	yRotatierMatrix[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	yRotatierMatrix[2] = glm::vec4(-sin(-angle), 0.0f, cos(-angle), 0.0f);
	yRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = yRotatierMatrix * wireSphere.model;
}

void Himmelsding::rotateZ(float angle)
{
	glm::mat4x4 zRotatierMatrix;
	zRotatierMatrix[0] = glm::vec4(cos(-angle), -sin(-angle), 0.0f, 0.0f);
	zRotatierMatrix[1] = glm::vec4(sin(-angle), cos(-angle), 0.0f, 0.0f);
	zRotatierMatrix[2] = glm::vec4(0.0f, 0.0f, 1.0f , 0.0f);
	zRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = zRotatierMatrix * wireSphere.model;
}