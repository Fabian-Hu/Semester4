#include "Moons.h"

Moons::Moons(Himmelsding *planet, int anzahlMonde, float r, float g, float b) :
	planet(planet),anzahlMonde(anzahlMonde), farbe(r, g, b)
{
	calculateMoons();
}

Moons::Moons(Himmelsding *planet, int anzahlRinge, int anzahlMonde1, int anzahlMonde2, int anzahlMonde3, float abstand, float schiefigkeitigkeit, float r, float g, float b) :
	planet(planet), anzahlMonde(anzahlMonde1 + anzahlMonde2 + anzahlMonde3), anzahlRinge(anzahlRinge), anzahlMonde1(anzahlMonde1), anzahlMonde2(anzahlMonde2), anzahlMonde3(anzahlMonde3), abstand(abstand), schiefigkeitigkeit(schiefigkeitigkeit), farbe(r, g, b)
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
		monde.push_back(Himmelsding(position3[0] + x, position3[1], position3[2] + z, 0.2f, farbe[0], farbe[1], farbe[2]));
	}
}

void Moons::calculateMoreMoons() {
	glm::vec3 position3 = planet->getPosition();

	for (int i = 0; i < anzahlMonde1; i++) {
		float angle = float(i) / float(anzahlMonde1) * 2.0f * 3.14f;

		float x = sinf(angle);
		float z = cosf(angle);
		//Himmelsding mond(position3[0] + x, position3[1], position3[2] + z, 0.2f);
		monde.push_back(Himmelsding(position3[0] + x, position3[1], position3[2] + z, 0.2f, schiefigkeitigkeit, 0.0f, planet, farbe[0], farbe[1], farbe[2]));
	}
	for (int i = 0; i < anzahlMonde2; i++) {
		float angle = float(i) / float(anzahlMonde2) * 2.0f * 3.14f;

		float x = sinf(angle);
		float z = cosf(angle);
		//Himmelsding mond(position3[0] + x, position3[1], position3[2] + z, 0.2f);
		monde.push_back(Himmelsding(position3[0] + x, position3[1], position3[2] + z, 0.2f, schiefigkeitigkeit, abstand, planet, farbe[0], farbe[1], farbe[2]));
	}
	for (int i = 0; i < anzahlMonde3; i++) {
		float angle = float(i) / float(anzahlMonde3) * 2.0f * 3.14f;

		float x = sinf(angle);
		float z = cosf(angle);
		//Himmelsding mond(position3[0] + x, position3[1], position3[2] + z, 0.2f);
		monde.push_back(Himmelsding(position3[0] + x, position3[1], position3[2] + z, 0.2f, schiefigkeitigkeit, -abstand, planet, farbe[0], farbe[1], farbe[2]));
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

void Moons::rotateY(float angle)
{
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].rotateMoonY(planet, angle);
	}
}

void Moons::rotateSchief(float angle, glm::vec3 axis)
{
	for (unsigned i = 0; i < monde.size(); i++) {
		monde[i].rotateSchief(planet, angle, axis);
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
