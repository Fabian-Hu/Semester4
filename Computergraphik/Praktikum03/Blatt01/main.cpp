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

// Standard window width
const int WINDOW_WIDTH  = 640;
// Standard window height
const int WINDOW_HEIGHT = 480;
// GLUT window id/handle
int glutID = 0;
float cameraZPos = 4.0f;

cg::GLSLProgram program;

glm::mat4x4 view;
glm::mat4x4 projection;

float zNear = 0.1f;
float zFar  = 100.0f;
Model3D cube;
Model3D coordinateAxes;

void createCoordinateAxes() {
	std::vector<glm::vec3> vertices;
	glm::vec3 color= { 1.0f, 1.0f, 1.0f };

	vertices = { { 0.01f, 0.0f, 0.0f },{ 0.01f, 2.0f, 0.0f },{ -0.01f, 0.0f, 0.0f } };
	coordinateAxes.addFace(Face(vertices, color));
	vertices = { { -0.01f, 0.0f, 0.0f },{ 0.01f, 2.0f, 0.0f },{ -0.01f, 2.0f, 0.0f } };
	coordinateAxes.addFace(Face(vertices, color));

	vertices = { { 0.0f, 0.01f, 0.0f },{ 2.0f, 0.01f, 0.0f },{ 0.0f, -0.01f, 0.0f } };
	coordinateAxes.addFace(Face(vertices, color));
	vertices = { { 0.0f, 0.01f, 0.0f },{ 2.01f, 0.01f, 0.0f },{ 2.0f, -0.01f, 0.0f } };
	coordinateAxes.addFace(Face(vertices, color));

	vertices = { { 0.0f, 0.01f, 0.0f },{ 0.0f, -0.01f, 0.0f },{ 0.0f, -0.01f, 2.0f } };
	coordinateAxes.addFace(Face(vertices, color));
	vertices = { { 0.0f, 0.01f, 0.0f },{ 0.0f, 0.01f, 2.0f },{ 0.0f, -0.01f, 2.0f } };
	coordinateAxes.addFace(Face(vertices, color));
}

void createCube() {
	std::vector<glm::vec3> vertices;
	glm::vec3 color;
	vertices = { { -1.0f, 1.0f, 1.0f },{ 1.0f, -1.0f, 1.0f },{ -1.0f, -1.0f, 1.0f } };
	color = { 0.39f, 0.58f, 0.93f };
	cube.addFace(Face(vertices, color));
	vertices = { {1.0f, 1.0f, 1.0f}, {1.0f, -1.0f, 1.0f}, {-1.0f, 1.0f, 1.0f} };
	cube.addFace(Face(vertices, color));

	color = { 0.56f, 0.74f, 0.56f };
	vertices = { { 1.0, 1.0, 1.0 },{ 1.0, -1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	cube.addFace(Face(vertices, color));
	vertices = { { 1.0, -1.0, -1.0 },{ 1.0, -1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	cube.addFace(Face(vertices, color));

	color = { 0.7f, 0.13f, 0.13f };
	vertices = { { 1.0, 1.0, 1.0 },{ -1.0, 1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	cube.addFace(Face(vertices, color));
	vertices = { { -1.0, 1.0, -1.0 },{ -1.0, 1.0, 1.0 },{ 1.0, 1.0, -1.0 } };
	cube.addFace(Face(vertices, color));

	color = { 0.68f, 1.0f, 0.18f };
	vertices = { { 1.0, 1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ 1.0, -1.0, -1.0 } };
	cube.addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ 1.0, -1.0, -1.0 } };
	cube.addFace(Face(vertices, color));

	color = { 0.94f, 0.5f, 0.5f };
	vertices = { { -1.0, 1.0, 1.0 },{ -1.0, 1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	cube.addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ -1.0, 1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	cube.addFace(Face(vertices, color));

	color = { 1.0f, 0.27f, 0.0f };
	vertices = { { 1.0, -1.0, 1.0 },{ 1.0, -1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	cube.addFace(Face(vertices, color));
	vertices = { { -1.0, -1.0, -1.0 },{ 1.0, -1.0, -1.0 },{ -1.0, -1.0, 1.0 } };
	cube.addFace(Face(vertices, color));
}

/*
 Initialization. Should return true if everything is ok and false if something went wrong.
 */
bool init() {
	// OpenGL: Set "background" color and enable depth testing.
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	// Construct view matrix.
	glm::vec3 eye(0.0f, 0.0f, cameraZPos);
	glm::vec3 center(0.0f, 0.0f, 0.0f);
	glm::vec3 up(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(eye, center, up);

	// Create a shader program and set light direction.
	if (!program.compileShaderFromFile("shader/simple.vert", cg::GLSLShader::VERTEX))
	{
		std::cerr << program.log();
		return false;
	}

	if (!program.compileShaderFromFile("shader/simple.frag", cg::GLSLShader::FRAGMENT))
	{
		std::cerr << program.log();
		return false;
	}
	
	if (!program.link())
	{
		std::cerr << program.log();
		return false;
	}

	cube.init(program);
	coordinateAxes.init(program);
	return true;
}

/*
 Release resources on termination.
 */
void release()
{
	// Shader program will be released upon program termination.
	cube.releaseModel();
}

/*
 Rendering.
 */
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cube.render(program, view, projection);
	coordinateAxes.render(program, view, projection);
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
	if ((cameraZPos > 2.0f || m > 0) && (cameraZPos < 15.0f || m < 0)) {
		cameraZPos += m;
		glm::vec3 eye(0.0f, 0.0f, cameraZPos);
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
	case '+':
		moveCamera(0.1f);
		break;
	case '-':
		// do something
		break;
	case 'x':
		cube.rotateX(0.1f);
		release();
		cube.init(program);
		break;
	case 'y':
		cube.rotateY(0.1f);
		release();
		cube.init(program);
		break;
	case 'z':
		cube.rotateZ(0.1f);
		release();
		cube.init(program);
		break;
	case 'a':
		moveCamera(-0.1f);
		break;
	case 's':
		moveCamera(0.1f);
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

	glutCreateWindow("Aufgabenblatt 03");
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
	//glutIdleFunc   (glutDisplay); // redisplay when idle

	glutKeyboardFunc(glutKeyboard);

	// Create objects.
	createCube();
	cube.build();
	createCoordinateAxes();
	coordinateAxes.build();

	// Init VAO.
	{
		GLCODE(bool result = init());
		if (!result) {
			release();
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
