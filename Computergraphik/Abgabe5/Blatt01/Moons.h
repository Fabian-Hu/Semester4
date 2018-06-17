#pragma once
#include "Himmelsding.h"

class Moons : Masterding {
public:
	Moons::Moons(Himmelsding *planet, int anzahlMonde, float r, float g, float b);
	Moons::Moons(Himmelsding *planet, int anzahlRinge, int anzahlMonde1, int anzahlMonde2, int anzahlMonde3, float abstand, float schiefigkeitigkeit, float r, float g, float b);

	void render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void init(cg::GLSLProgram& program);
	void releaseObject();

	void calculateMoons();
	void calculateMoreMoons();

	void translate(float x, float y, float z);
	void translate(glm::vec3 position);

	float degreeToRadians(float angle);

	void rotateY(float angle);
	void rotateWinkel(float angle);
	void rotateSchief(float angle, glm::vec3 axis);

	glm::vec3 getPosition();

private:
	Object wireSphere; // GLUT geometry
	Himmelsding *planet;
	std::vector<Himmelsding> monde;

	int anzahlRinge = 1;
	int anzahlMonde = 1;
	int anzahlMonde1;
	int anzahlMonde2;
	int anzahlMonde3;

	float abstand = 0.0f;
	float schiefigkeitigkeit = 0.0f;

	glm::vec3 position;
	glm::vec3 farbe;
};