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
#include "ModelHE.h"

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
float lightIntensity = 1.0f;

cg::GLSLProgram program;

glm::mat4x4 view;
glm::mat4x4 projection;

float zNear = 0.1f;
float zFar  = 100.0f;
glm::vec3 ambientLight = glm::vec3(0.1f);
glm::vec3 specularColor = glm::vec3(1.0f);

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
	if (!program.compileShaderFromFile("shader/shadedPhongTextured.vert", cg::GLSLShader::VERTEX))
	{
		std::cerr << program.log();
		return false;
	}

	if (!program.compileShaderFromFile("shader/shadedPhongTextured.frag", cg::GLSLShader::FRAGMENT))
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
	program.setUniform("lightI", lightIntensity);
	program.setUniform("surfKa", ambientLight);
	program.setUniform("surfKs", specularColor);
	program.setUniform("imgTexture", 0);

	//Init Models
	GLCODE(heObj.init(program));
	GLCODE(heCar.init(program));
	heCar.scale(glm::vec3(0.0f), 0.5f);
	heCar.translate(glm::vec3(-2.0f, 0.0f, 0.0f));
	GLCODE(sun.init (program));
	sun.setUp();
	//heModel.printTex();
	return true;
}

/*
 Release resources on termination.
 */
void release() {
	// Shader program will be released upon program termination.
	sun.release ();
	heObj.release();
	heCar.release();
}

/*
 Rendering.
 */
void render() {
	if (doRotate) {
		sun.rotate();
		heCar.rotate(carSpeed, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sun.render (program, view, projection);
	heObj.render(program, view, projection);
	heCar.render(program, view, projection);
}

void glutDisplay () {
	GLCODE(render());
	GLCODE(glutSwapBuffers());
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
		if (speed >= MIN_SPEED) {
			sun.multiplyRotationAngle(speedMultiplierDecreaseValue);
			speed--;
		}
		break;
	case 'W':
		if (speed <= MAX_SPEED) {
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
	case 'x':
		heObj.rotateLocal(0.1f, glm::vec3(1, 0, 0));
		break;
	case 'y':
		heObj.rotateLocal(0.1f, glm::vec3(0, 1, 0));
		break;
	case 'z':
		heObj.rotateLocal(0.1f, glm::vec3(0, 0, 1));
		break;
	case 'b':
		heObj.setActive(!heObj.isActive());
		heCar.setActive(!heCar.isActive());
		break;
	case 'm':
		if (carSpeed > MIN_CARSPEED) {
			carSpeed -= CARSPEED_CHANGEVALUE;
		}
		break;
	case 'M':
		if (carSpeed < MAX_CARSPEED) {
			carSpeed += CARSPEED_CHANGEVALUE;
		}
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
		break;
	case 'n':
		heObj.setNormals(!heObj.getNormalsStatus());
		heCar.setNormals(!heCar.getNormalsStatus());
		break;
	case 'h':
		heCar.setFaceNormals(!heCar.getFaceNormalsStatus());
		heObj.setFaceNormals(!heObj.getFaceNormalsStatus());
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {
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
	sunAxisObject.setActive(false);

	heObj.build();
	heObj.setActive(false);

	heCar.build();
	heCar.setActive(false);

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
