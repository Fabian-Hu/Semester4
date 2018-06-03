#pragma once
#include "Himmelsding.h"

class Moons : Masterding {
public:
	Moons::Moons(Himmelsding *planet, int anzahlMonde);
	Moons::Moons(Himmelsding *planet, int anzahlRinge, int anzahlMonde1, int anzahlMonde2, int anzahlMonde3, float abstand, float schiefigkeitigkeit);

	void render(cg::GLSLProgram& program, glm::mat4x4 view, glm::mat4x4 projection);
	void init(cg::GLSLProgram& program);
	void releaseObject();

	void calculateMoons();
	void calculateMoreMoons();

	void translate(float x, float y, float z);
	void translate(glm::vec3 position);

	float degreeToRadians(float angle);

	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
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
};