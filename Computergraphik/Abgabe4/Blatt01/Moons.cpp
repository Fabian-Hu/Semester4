#include "Moons.h"

Moons::Moons(Himmelsding *planet, int anzahlMonde) :
	planet(planet),anzahlMonde(anzahlMonde)
{
	calculateMoons();
}

Moons::Moons(Himmelsding *planet, int anzahlRinge, int anzahlMonde1, int anzahlMonde2, int anzahlMonde3, float abstand, float schiefigkeitigkeit) :
	planet(planet), anzahlMonde(anzahlMonde1 + anzahlMonde2 + anzahlMonde3), anzahlRinge(anzahlRinge), anzahlMonde1(anzahlMonde1), anzahlMonde2(anzahlMonde2), anzahlMonde3(anzahlMonde3), abstand(abstand), schiefigkeitigkeit(schiefigkeitigkeit)
{
	calculateMoreMoons();
}

void Moons::render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection)
{
	// alle Monde rendern, also alle Himmelskörper aufrufen
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].render(program, view, projection);
	}
}

void Moons::init(cg::GLSLProgram& program)
{
	// mit allen Himmelskörpern init aufrufen
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].init(program);
	}
}

/*
Release object resources.
*/
void Moons::releaseObject()
{
	// mit allen aufrufen
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].releaseObject();
	}
}

void Moons::calculateMoons() {
	glm::vec3 position3 = planet->getPosition();

	for (int i = 0; i < anzahlMonde; i++) {
		float angle = float(i) / float(anzahlMonde) * 2.0f * 3.14f;

		float x = sinf(angle);
		float z = cosf(angle);
		//Himmelsding mond(position3[0] + x, position3[1], position3[2] + z, 0.2f);
		monde.push_back(Himmelsding(position3[0] + x, position3[1], position3[2] + z, 0.2f));
	}
}

void Moons::calculateMoreMoons() {
	glm::vec3 position3 = planet->getPosition();

	for (int i = 0; i < anzahlMonde1; i++) {
		float angle = float(i) / float(anzahlMonde1) * 2.0f * 3.14f;

		float x = sinf(angle);
		float z = cosf(angle);
		//Himmelsding mond(position3[0] + x, position3[1], position3[2] + z, 0.2f);
		monde.push_back(Himmelsding(position3[0] + x, position3[1], position3[2] + z, 0.2f, schiefigkeitigkeit, 0.0f, planet));
	}
	for (int i = 0; i < anzahlMonde2; i++) {
		float angle = float(i) / float(anzahlMonde2) * 2.0f * 3.14f;

		float x = sinf(angle);
		float z = cosf(angle);
		//Himmelsding mond(position3[0] + x, position3[1], position3[2] + z, 0.2f);
		monde.push_back(Himmelsding(position3[0] + x, position3[1], position3[2] + z, 0.2f, schiefigkeitigkeit, abstand, planet));
	}
	for (int i = 0; i < anzahlMonde3; i++) {
		float angle = float(i) / float(anzahlMonde3) * 2.0f * 3.14f;

		float x = sinf(angle);
		float z = cosf(angle);
		//Himmelsding mond(position3[0] + x, position3[1], position3[2] + z, 0.2f);
		monde.push_back(Himmelsding(position3[0] + x, position3[1], position3[2] + z, 0.2f, schiefigkeitigkeit, -abstand, planet));
	}
}




void Moons::translate(float x, float y, float z) {
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].translate(x, y, z);
	}
}

void Moons::translate(glm::vec3 position) {
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].translate(position);
	}
}

float Moons::degreeToRadians(float angle) {
	return (angle * (float)PI / 180.0f);
}

void Moons::rotateX(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 xRotatierMatrix;
	xRotatierMatrix[0] = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	xRotatierMatrix[1] = glm::vec4(0.0f, cos(-radians), -sin(-radians), 0.0f);
	xRotatierMatrix[2] = glm::vec4(0.0f, sin(-radians), cos(-radians), 0.0f);
	xRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = xRotatierMatrix * wireSphere.model;
}

void Moons::rotateY(float angle)
{
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].rotateMoonY(planet, angle);
		//monde[i].rotateY(angle);
	}
}

void Moons::rotateZ(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 zRotatierMatrix;
	zRotatierMatrix[0] = glm::vec4(cos(-radians), -sin(-radians), 0.0f, 0.0f);
	zRotatierMatrix[1] = glm::vec4(sin(-radians), cos(-radians), 0.0f, 0.0f);
	zRotatierMatrix[2] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	zRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	wireSphere.model = zRotatierMatrix * wireSphere.model;
}

void Moons::rotateSchief(float angle, float axis1, float axis2, float axis3)
{
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].rotateAroundAxis(planet, angle);
		//monde[i].rotateAroundAxis(planet, angle, axis1, axis2, axis3);
		//monde[i].rotateY(angle);
	}
}

void Moons::rotateWinkel(float angle)
{
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].rotateAroundAxis(angle, planet);
	}
}

glm::vec3 Moons::getPosition()
{
	return position;
}
