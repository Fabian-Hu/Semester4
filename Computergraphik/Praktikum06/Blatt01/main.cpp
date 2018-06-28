#include <iostream>
#include <vector>

#include <GL/glew.h>
//#include <GL/gl.h> // OpenGL header not necessary, included by GLEW
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#include "GLSLProgram.h"
#include "GLTools.h"
#include "Model3D.h"
#include "Sphere.h"
#include "Axis.h"
#include "Orb.h"
#include "SunSystemData.h"
#include "ObjParser.h"

// Standard window width
const int WINDOW_WIDTH  = 640;
// Standard window height
const int WINDOW_HEIGHT = 480;
// GLUT window id/handle
int glutID = 0;
float cameraPos = 8.0f;

const glm::vec3 directionLight = glm::normalize(glm::vec3(0.0f, -1.0f, 0.0f));
const glm::vec3 pointLight = glm::vec3(0.0f, 0.0f, cameraPos);
int lightMode = 0;
glm::vec4 currentLight = glm::vec4(directionLight, lightMode);

cg::GLSLProgram program;

glm::mat4x4 view;
glm::mat4x4 projection;

float zNear = 0.1f;
float zFar  = 100.0f;

bool doRotate = true;

/*
 Initialization. Should return true if everything is ok and false if something went wrong.
 */
bool init() {
	// OpenGL: Set "background" color and enable depth testing.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Construct view matrix.
	glm::vec3 eye(0, 0, cameraPos);
	glm::vec3 center(0.0f, 0.0f, 0.0f);
	glm::vec3 up(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(eye, center, up);

	// Create a shader program and set light direction.
	if (!program.compileShaderFromFile("shader/phong_shading.vert", cg::GLSLShader::VERTEX))
	{
		std::cerr << program.log();
		return false;
	}

	if (!program.compileShaderFromFile("shader/phong_shading.frag", cg::GLSLShader::FRAGMENT))
	{
		std::cerr << program.log();
		return false;
	}
	
	if (!program.link())
	{
		std::cerr << program.log();
		return false;
	}
	program.use();
	program.setUniform("light", currentLight);
	program.setUniform("viewpoint", eye);

	//Init Models
	sun.init (program);
	sun.setUp();
	return true;
}

/*
 Release resources on termination.
 */
void release() {
	// Shader program will be released upon program termination.
	sun.release ();
}

/*
 Rendering.
 */
void render() {
	if (doRotate)
		sun.rotate();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sun.render (program, view, projection);
}

void glutDisplay () {
	GLCODE(render());
	glutSwapBuffers();
}

/*
 Resize callback.
 */
void glutResize (int width, int height) {
	// Division by zero is bad...
	height = height < 1 ? 1 : height;
	glViewport(0, 0, width, height);

	// Construct projection matrix.
	projection = glm::perspective(45.0f, (float) width / height, zNear, zFar);
}

void moveCamera(float m) {
	//glm::translate(view, glm::vec3(0.0f, 0.0f, m));
	if ((cameraPos > 2.0f || m > 0) && (cameraPos < 15.0f || m < 0)) {
		cameraPos += m;
		glm::vec3 eye(0, 0, cameraPos);
		glm::vec3 center(0.0f, 0.0f, 0.0f);
		glm::vec3 up(0.0f, 1.0f, 0.0f);

		view = glm::lookAt(eye, center, up);
		program.setUniform("viewpoint", eye);
	}
}

/*
 Callback for char input.
 */
void glutKeyboard (unsigned char keycode, int x, int y) {
	switch (keycode){
	case 27: // ESC
	  glutDestroyWindow ( glutID );
	  return;
	case 't':
		if (sunHeight > MIN_SUNHEIGHT) {
			sun.translate(glm::vec3(0.0f, -sunHeightSpeed, 0.0f));
			sunHeight--;
		}
		break;
	case 'T':
		if (sunHeight < MAX_SUNHEIGHT) {
			sun.translate(glm::vec3(0.0f, sunHeightSpeed, 0.0f));
			sunHeight++;
		}
		break;
	case 'l':
		if (earthHeight > MIN_EARTHHEIGHT) {
			earth.translate(glm::vec3(0, -earthHeightSpeed, 0));
			earthHeight--;
		}
		break;
	case 'L':
		if (earthHeight < MAX_EARTHHEIGHT) {
			earth.translate(glm::vec3(0, earthHeightSpeed, 0));
			earthHeight++;
		}
		break;
	case 'p':
		mars.rotateWithAxis(-marsRotSpeed, glm::vec3(0, 0, 1));
		break;
	case 'P':
		mars.rotateWithAxis(marsRotSpeed, glm::vec3(0, 0, 1));
		break;
	case 'w':
		if (speed > MIN_SPEED) {
			sun.multiplyRotationAngle(speedMultiplierDecreaseValue);
			speed--;
		}
		break;
	case 'W':
		if (speed < MAX_SPEED) {
			sun.multiplyRotationAngle(speedMultiplierIncreaseValue);
			speed++;
		}
		break;
	case 'a':
		moveCamera(-cameraMovementValue);
		break;
	case 's':
		moveCamera (cameraMovementValue);
		break;
	case '1':
		lightMode = (lightMode) ? 0 : 1;
		if (lightMode == 0) {
			currentLight = glm::vec4(directionLight, lightMode);
			std::cout << "Richtungslicht" << std::endl;
		}
		else {
			currentLight = glm::vec4(pointLight, lightMode);
			std::cout << "Punktlicht" << std::endl;
		}
		
		program.setUniform("light", currentLight);
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	ObjParser parser;
	HE_Object obj;
	parser.parseObj(std::string("C:/Users/malte/Documents/Uni/Semester4/_Repository/Semester4/Computergraphik/Praktikum06/A1_testcubeBig_trans.obj"), obj);

	// GLUT: Initialize freeglut library (window toolkit).
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(40,40);
	glutInit(&argc, argv);

	// GLUT: Create a window and opengl context (version 4.3 core profile).
	glutInitContextVersion(4, 3);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("Aufgabenblatt 04");
	glutID = glutGetWindow();

	glEnable(GL_DEPTH_TEST);
	  
	// GLEW: Load opengl extensions
	glewExperimental = GL_TRUE;
	GLenum result = glewInit();

	if (result != GLEW_OK) {
	   return -1;
	}

	// GLUT: Set callbacks for events.
	glutReshapeFunc(glutResize);
	glutDisplayFunc(glutDisplay);
	glutIdleFunc   (glutDisplay); // redisplay when idle

	glutKeyboardFunc(glutKeyboard);

	mars.addSetUp(rotateMarsSetUp);
	mars.addRotation(rotateMars);
	// Create objects.
	sun.addChild(earth);
	sun.addChild(mars);
	sun.addChild(sunAxisObject);
	earth.addChild(earthMoon1);
	earth.addChild(earthMoon2);
	earth.addChild(earthMoon3);
	earth.addChild(earthAxisObject);
	mars.addChild(marsMoon1);
	mars.addChild(marsMoon2);
	mars.addChild(marsMoon3);
	mars.addChild(marsMoon4);
	mars.addChild(marsMoon5);
	mars.addChild(marsMoon6);
	mars.addChild(marsMoon7);
	mars.addChild(marsMoon8);
	mars.addChild(marsMoon9);
	mars.addChild(marsMoon10);
	mars.addChild(marsAxisObject);
	sun.build();
	sun.setActive(false);

	// Init VAO.
	{
		GLCODE(bool result = init());
		if (!result) {
			release();
			while (true);
			return -2;
		}
	}

	// GLUT: Loop until the user closes the window
	// rendering & event handling
	glutMainLoop();

	// Clean up everything on termination.
	release();

	return 0;
}
