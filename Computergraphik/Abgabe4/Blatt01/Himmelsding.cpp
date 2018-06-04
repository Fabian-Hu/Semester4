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

Himmelsding::Himmelsding(float x, float y, float z, float radio, float schiefigkeitigkeit, float offset, Himmelsding *planet) :
	position(x, y, z), radius(radio), schiefigkeitigkeit(schiefigkeitigkeit), offset(offset), planet(planet)
{
}

void Himmelsding::render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection)
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
	GLCODE(glutWireSphere(radius, 10, 10));

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
	glutSetVertexAttribNormal(glGetAttribLocation(programId, "color"));
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
		//rotateZ(schiefigkeitigkeit);
		//rotatePlutosOffsetDinger(schiefigkeitigkeit, offset, planet);
		translate(0.0f, offset, 0.0f);
		translate(position);
		rotateAroundAxis(planet, schiefigkeitigkeit, 0.0f, 0.0f, 1.0f);
		//weirdTranslate(position);
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
	//wireSphere.model = glm::translate(wireSphere.model, glm::vec3(x, y, z));
	wireSphere.model = glm::translate(glm::mat4x4(1.0f), glm::vec3(x, y, z)) * wireSphere.model;
}

void Himmelsding::translate(glm::vec3 position) {
	//wireSphere.model = glm::translate(wireSphere.model, position);
	wireSphere.model = glm::translate(glm::mat4x4(1.0f), position) * wireSphere.model;
}

void Himmelsding::weirdTranslate(glm::vec3 position) {
	wireSphere.model = glm::translate(wireSphere.model, position);
	//wireSphere.model = glm::translate(glm::mat4x4(1.0f), position) * wireSphere.model;
}

float Himmelsding::degreeToRadians(float angle) {
	return (angle * (float)PI / 180.0f);
}

glm::vec3 Himmelsding::substract(glm::vec3 eins, glm::vec3 zwei) {
	glm::vec3 result(eins[0] - zwei[0], eins[1] - zwei[1], eins[2] - zwei[2]);
	return result;
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

void Himmelsding::rotatePlutosOffsetDinger(float angle, float offset, Himmelsding *planet)
{////////////////////////////////////////////////////////
	float radians = degreeToRadians(angle);
	glm::vec3 position = planet->getPosition();
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(-1.0f, 1.0f, 0.0f)) *
			glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
				wireSphere.model;
}

void Himmelsding::rotateAroundAxis(Himmelsding *planet, float angle, float axis1, float axis2, float axis3) {

	float radians = degreeToRadians(angle);
	glm::vec3 position = planet->getPosition();
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(axis1, axis2, axis3)) *
		glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
		wireSphere.model;
}

void Himmelsding::rotateAroundAxis(Himmelsding *planet, float angle) {
	float radians = degreeToRadians(angle);
	glm::vec3 position = planet->getPosition();

	float axis1 = 0.0f;
	float axis2 = 1.0f;
	float axis3 = 0.0f;
	float weirdo = 0.0f;
	float posi1 = position[0];
	float posi2 = position[2];
	if (posi1 < 0) {
		posi1 = posi1 * -1;
	}
	if (posi2 < 0) {
		posi2 = posi2 * -1;
	}
	weirdo = posi1 + posi2;
	if (weirdo < 0) {
		weirdo = weirdo * -1;
	}
	if (position[0] != 0) {
		axis1 = position[0] / weirdo;
	}
	if (position[2] != 0) {
		axis3 = position[2] / weirdo;
	}
	std::cout << "Achsen" << axis1 << "," << axis2 << "," << axis3 << "," << std::endl;
	std::cout << "Position" << position[0] << "," << position[1] << "," << position[2] << "," << std::endl;
	wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
		glm::rotate(glm::mat4(1.0f), radians, glm::vec3(axis1, axis2, axis3)) *
			glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
				wireSphere.model;

	wireSphere.model = glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 1.0f, 0.0f)) * wireSphere.model;
}

void Himmelsding::rotateSelf(float angle) {
	float radians = degreeToRadians(angle);
	if (schiefigkeitus == 0) {
		wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
			glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 1.0f, 0.0f)) *
				glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
			 		wireSphere.model;
	} else {
		wireSphere.model = glm::translate(glm::mat4(1.0f), position) *
			glm::rotate(glm::mat4(1.0f), radians, glm::vec3(-1.0f, 1.0f, 0.0f)) *
				glm::translate(glm::mat4(1.0f), glm::vec3(-position[0], -position[1], -position[2])) *
					wireSphere.model;
	}

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
