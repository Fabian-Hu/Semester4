#pragma once
#include "Sphere.h"
#include "Axis.h"
#include "Orb.h"
#include "WireframeSphere.h"
#include "SolidSphere.h"

const float sunHeightSpeed = 0.04f;
const float earthHeightSpeed = 0.04f;
const float marsRotSpeed = 0.01f;
const float speedMultiplierDecreaseValue = 0.99f;
const float speedMultiplierIncreaseValue = 1.01f;
const float cameraMovementValue = 0.1f;

int sunHeight = 0;
const int MAX_SUNHEIGHT = 128;
const int MIN_SUNHEIGHT = -128;

int earthHeight = 0;
const int MAX_EARTHHEIGHT = 64;
const int MIN_EARTHHEIGHT = -64;

int speed = 0;
const int MAX_SPEED = 256;
const int MIN_SPEED = -128;
const float marsRotation = 45.0f;

SolidSphere sphereSun (glm::vec3 (0, 0, 0), 1.0f, 3, glm::vec3 (1.0f, 0.78f, 0.0f));
SolidSphere sphereEarth (glm::vec3 (3.5f, 0, 0), 0.5f, 3, glm::vec3 (0.2f, 0.75f, 0.2f));
SolidSphere sphereMars (glm::vec3 (0, 0, 5.8f), 0.4f, 3, glm::vec3 (0.5f, 0.28f, 0.0f));

SolidSphere sphereEarthMoon1 (glm::vec3 (2.6f, 0, 0.0f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));
SolidSphere sphereEarthMoon2 (glm::vec3 (3.95f, 0, 0.9f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));
SolidSphere sphereEarthMoon3 (glm::vec3 (3.95f, 0, -0.9f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));

SolidSphere sphereMarsMoon1 (glm::vec3 (-0.8, 0.0, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));
SolidSphere sphereMarsMoon2 (glm::vec3 (0.8, 0.0, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));

SolidSphere sphereMarsMoon3 (glm::vec3 (-0.8, 1.8, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));
SolidSphere sphereMarsMoon4 (glm::vec3 (0.8, 1.8, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));
SolidSphere sphereMarsMoon5 (glm::vec3 (0.0, 1.8, 6.6f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));
SolidSphere sphereMarsMoon6 (glm::vec3 (0.0, 1.8, 5.0f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f));

SolidSphere sphereMarsMoon7(glm::vec3(-0.8, -1.8, 5.8f), 0.1f, 3, glm::vec3(0.4f, 0.4f, 0.4f));
SolidSphere sphereMarsMoon8(glm::vec3(0.8, -1.8, 5.8f), 0.1f, 3, glm::vec3(0.4f, 0.4f, 0.4f));
SolidSphere sphereMarsMoon9(glm::vec3(0.0, -1.8, 6.6f), 0.1f, 3, glm::vec3(0.4f, 0.4f, 0.4f));
SolidSphere sphereMarsMoon10(glm::vec3(0.0, -1.8, 5.0f), 0.1f, 3, glm::vec3(0.4f, 0.4f, 0.4f));

Axis sunAxis ({ 0.0f,0.0f,0.0f }, 6, { 1.0f, 1.0f, 0.0f });
Axis earthAxis ({ 3.5f,0.0f,0.0f }, 4, { 1.0f, 0.6f, 0.0f });
Axis marsAxis ({ 0, 0, 5.8f }, 4, { 1.0f, 0.6f, 0.0f });

Orb sun (&sphereSun, glm::vec3 (0, 1, 0));
Orb earth (&sphereEarth, glm::vec3 (0, 1, 0), 0.001f, 0.002f);
Orb mars (&sphereMars, glm::vec3 (0, 1, 0), 0.002f, 0.004f);
Orb earthMoon1 (&sphereEarthMoon1, glm::vec3 (0, 1, 0), -0.005f, -0.01f, false);
Orb earthMoon2 (&sphereEarthMoon2, glm::vec3 (0, 1, 0), -0.005f, -0.01f, false);
Orb earthMoon3 (&sphereEarthMoon3, glm::vec3 (0, 1, 0), -0.005f, -0.01f, false);
Orb marsMoon1 (&sphereMarsMoon1, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon2 (&sphereMarsMoon2, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon3 (&sphereMarsMoon3, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon4 (&sphereMarsMoon4, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon5 (&sphereMarsMoon5, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon6 (&sphereMarsMoon6, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon7 (&sphereMarsMoon7, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon8 (&sphereMarsMoon8, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon9 (&sphereMarsMoon9, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb marsMoon10 (&sphereMarsMoon10, glm::vec3 (0, 1, 1), -0.01f, 0.0f, false);
Orb sunAxisObject (&sunAxis, glm::vec3 (0, 1, 0));
Orb earthAxisObject (&earthAxis, glm::vec3 (0, 1, 0));
Orb marsAxisObject (&marsAxis, glm::vec3 (0, 1, 0), 0.0f, -0.000f);

void rotateMarsSetUp(Orb *orb) {
	orb->rotateWithAxis(glm::radians(marsRotation), glm::vec3(0, 0, 1));
}

void rotateMars(Orb *orb) {
	orb->rotateLocal(orb->getRotationAngle() * -1, glm::vec3(0, 1, 0));
}
