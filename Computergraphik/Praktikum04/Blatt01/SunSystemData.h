#pragma once
#include "Sphere.h"
#include "Axis.h"
#include "Orb.h"
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

Sphere sphereSun (glm::vec3 (0, 0, 0), 1.0f, 3, glm::vec3 (1.0f, 0.78f, 0.0f), GL_LINES);
Sphere sphereEarth (glm::vec3 (3.5f, 0, 0), 0.5f, 3, glm::vec3 (0.2f, 0.75f, 0.2f), GL_LINES);
Sphere sphereMars (glm::vec3 (0, 0, 5.8f), 0.4f, 3, glm::vec3 (0.5f, 0.28f, 0.0f), GL_LINES);

Sphere sphereEarthMoon1 (glm::vec3 (2.6f, 0, 0.0f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereEarthMoon2 (glm::vec3 (3.95f, 0, 0.9f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereEarthMoon3 (glm::vec3 (3.95f, 0, -0.9f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);

Sphere sphereMarsMoon1 (glm::vec3 (-0.6, -0.6, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereMarsMoon2 (glm::vec3 (0.6, 0.6, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);

Sphere sphereMarsMoon3 (glm::vec3 (-1.8, 0.6, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereMarsMoon4 (glm::vec3 (-0.6, 1.8, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereMarsMoon5 (glm::vec3 (-1.2, 1.2, 6.64853f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereMarsMoon6 (glm::vec3 (-1.2, 1.2, 4.95147f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);

Sphere sphereMarsMoon7 (glm::vec3 (1.8, -0.6, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereMarsMoon8 (glm::vec3 (0.6, -1.8, 5.8f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereMarsMoon9 (glm::vec3 (1.2, -1.2, 6.64853f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);
Sphere sphereMarsMoon10 (glm::vec3 (1.2, -1.2, 4.95147f), 0.1f, 3, glm::vec3 (0.4f, 0.4f, 0.4f), GL_LINES);

Axis sunAxis ({ 0.0f,0.0f,0.0f }, 6, { 1.0f, 1.0f, 0.0f }, 0, glm::vec3 (0, 1, 0));
Axis earthAxis ({ 3.5f,0.0f,0.0f }, 4, { 1.0f, 0.6f, 0.0f }, 0, glm::vec3 (0, 1, 0));
Axis marsAxis ({ 0, 0, 5.8f }, 4, { 1.0f, 0.6f, 0.0f }, 0.785398, glm::vec3 (0, 0, 1));

Orb sun (&sphereSun, glm::vec3 (0, 1, 0));
Orb earth (&sphereEarth, glm::vec3 (0, 1, 0), 0.001f, 0.002f);
Orb mars (&sphereMars, glm::vec3 (-1, 1, 0), 0.002f, 0.004f);
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
