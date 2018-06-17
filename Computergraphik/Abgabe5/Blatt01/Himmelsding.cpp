#include "Himmelsding.h"

Himmelsding::Himmelsding() :
	position(0.0f, 0.0f, 0.0f)
{
}

Himmelsding::Himmelsding(float x, float y, float z, float radio, float r, float g, float b) :
	position(x, y, z), radius(radio), farbe(r, g, b)
{
}

Himmelsding::Himmelsding(float x, float y, float z, float radio, float schiefigkeit, float r, float g, float b) :
	position(x, y, z), radius(radio), schiefigkeitus(schiefigkeit), farbe(r, g, b)
{
}

Himmelsding::Himmelsding(float x, float y, float z, float radio, float schiefigkeitigkeit, float offset, Himmelsding *planet, float r, float g, float b) :
	position(x, y, z), radius(radio), schiefigkeitigkeit(schiefigkeitigkeit), offset(offset), planet(planet), farbe(r, g, b)
{
}

void Himmelsding::render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection)
{	
	// Create mvp.
	glm::mat4x4 mvp = projection * view * wireSphere.model;
	glm::mat3 normaleMatrix = glm::inverseTranspose(glm::mat3(wireSphere.model));

	// Bind the shader program and set uniform(s).
	program.use();
	program.setUniform("mvp", mvp);
	program.setUniform("normaleMatrix", normaleMatrix);
	program.setUniform("model", wireSphere.model);
	program.setUniform("material", material);
	program.setUniform("scheinHeiligKeit", scheinHeiligKeit);
	program.setUniform("farbe", farbe);

	// GLUT: bind vertex-array-object
	// this vertex-array-object must be bound before the glutWireSphere call
	glBindVertexArray(wireSphere.vao);
	
    //glLineWidth(1.0f);
	glutSolidSphere(radius, 20, 20);

	// GLUT: unbind vertex-array-object
	glBindVertexArray(0);
}

void Himmelsding::init(cg::GLSLProgram& program)
{
	// set attribute locations (of shader) for GLUT
	GLuint programId = program.getHandle();
	// position attribute to variable "position"
	glutSetVertexAttribCoord3(glGetAttribLocation(programId, "position"));
	// normal attribute to variable "color"
	// this creates a colorful sphere :-)
	//glutSetVertexAttribNormal(glGetAttribLocation(programId, "color"));
	glutSetVertexAttribNormal(glGetAttribLocation(programId, "normal"));
	// create a vertex-array-object for GLUT geometry
	glGenVertexArrays(1, &wireSphere.vao);

	// Modify model matrix.
	// zur richtigen Startposition

	wireSphere.model = glm::mat4(1.0f);
	rotateX(90);

	if (schiefigkeitus != 0) {
		rotateZ(schiefigkeitus);
	}
	if (schiefigkeitigkeit != 0) {
		translate(0.0f, offset, 0.0f);
		translate(position[0], position[1], position[2]);
		rotateAroundAxis(planet, schiefigkeitigkeit, 0.0f, 0.0f, 1.0f);
	}
	else {
		translate(position);
	}
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
	wireSphere.model = glm::translate(glm::mat4x4(1.0f), glm::vec3(x, y, z)) * wireSphere.model;
	position[0] = position[0] + x;
	position[1] = position[1] + y;
	position[2] = position[2] + z;
}

void Himmelsding::translate(glm::vec3 position2) {
	wireSphere.model = glm::translate(glm::mat4x4(1.0f), position2) * wireSphere.model;
}

void Himmelsding::weirdTranslate(glm::vec3 position) {
	wireSphere.model = glm::translate(wireSphere.model, position);
}

float Himmelsding::degreeToRadians(float angle) {
	return (angle * (float)PI / 180.0f);
}

void Himmelsding::rotateX(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 xRotatierMatrix;
	xRotatierMatrix[0] = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	xRotatierMatrix[1] = glm::vec4(0.0f, cos(-radians), -sin(-radians), 0.0f);
	xRotatierMatrix[2] = glm::vec4(0.0f, sin(-radians), cos(-radians), 0.0f);
	xRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = xRotatierMatrix * wireSphere.model;
}

void Himmelsding::rotateY(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 yRotatierMatrix;
	yRotatierMatrix[0] = glm::vec4(cos(-radians), 0.0f, sin(-radians), 0.0f);
	yRotatierMatrix[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	yRotatierMatrix[2] = glm::vec4(-sin(-radians), 0.0f, cos(-radians), 0.0f);
	yRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

		wireSphere.model = yRotatierMatrix * wireSphere.model;

	glm::vec4 posi(position[0], position[1], position[2], 1);
	posi = yRotatierMatrix * posi;
	position[0] = posi[0];
	position[1] = posi[1];
	position[2] = posi[2];
}

void Himmelsding::rotateZ(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 zRotatierMatrix;
	zRotatierMatrix[0] = glm::vec4(cos(-radians), -sin(-radians), 0.0f, 0.0f);
	zRotatierMatrix[1] = glm::vec4(sin(-radians), cos(-radians), 0.0f, 0.0f);
	zRotatierMatrix[2] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	zRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = zRotatierMatrix * wireSphere.model;
}

void Himmelsding::rotateAroundAxis(Himmelsding *planet, float angle, float axis1, float axis2, float axis3) {

	float radians = degreeToRadians(angle);
	glm::vec3 position = planet->getPosition();
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(axis1, axis2, axis3)) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
		wireSphere.model;
}

void Himmelsding::rotateAroundAxis(float angle) {

	float radians = degreeToRadians(angle);
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(axis[0], axis[1], axis[2])) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
		wireSphere.model;
}

void Himmelsding::rotateAroundAxis(float angle, Himmelsding *planet) {

	float radians = degreeToRadians(angle);
	glm::vec3 position = planet->getPosition();
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 0.0f, 1.0f)) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
		wireSphere.model;
}

void Himmelsding::rotateSchief(Himmelsding *planet, float angle, glm::vec3 axis) {
	float radians = degreeToRadians(angle);
	glm::vec3 position = planet->getPosition();

	wireSphere.model = glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 1.0f, 0.0f)) * wireSphere.model;
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, -glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), radians, axis) *
			glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
				wireSphere.model;

}

void Himmelsding::rotateSelf(float angle) {
	float radians = degreeToRadians(angle);
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
		wireSphere.model;
}

void Himmelsding::rotateSelf(float angle, glm::vec3 axis) {
	float radians = degreeToRadians(angle);
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), radians, axis) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
		wireSphere.model;
}



void Himmelsding::rotateSelfZ(float angle)
{
	float radians = degreeToRadians(angle);

	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 0.0f, 1.0f)) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
		wireSphere.model;
}

void Himmelsding::rotateMoonY(Himmelsding *planet, float angle)
{
	float radians = degreeToRadians(angle);
	glm::vec3 position = planet->getPosition();
	wireSphere.model = glm::translate(glm::mat4 (1.0f), position) * 
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 1.0f, 0.0f)) * 
			glm::translate(glm::mat4(1.0f),glm::vec3 (-position[0], -position[1], -position[2])) * 
				wireSphere.model;
	wireSphere.model = glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f,1.0f,0.0f)) * wireSphere.model;
}

glm::vec3 Himmelsding::getPosition()
{
	return position;
}
