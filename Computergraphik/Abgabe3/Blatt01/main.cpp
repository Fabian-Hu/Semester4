#include <iostream>
#include <vector>

#include <GL/glew.h>
//#include <GL/gl.h> // OpenGL header not necessary, included by GLEW
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include "glm/gtx/rotate_vector.hpp"
#include "GLSLProgram.h"
#include "GLTools.h"

// Standard window width
const int WINDOW_WIDTH  = 640;
// Standard window height
const int WINDOW_HEIGHT = 480;
// GLUT window id/handle
int glutID = 0;

cg::GLSLProgram program;

glm::mat4x4 view;
glm::mat4x4 projection;

float zNear = 0.1f;
float zFar  = 100.0f;
float zoomy = 4.0f;

float xDreh = 1.0f;
float yDreh = 1.0f;
float zDreh = 1.0f;

std::vector<glm::vec3> vertices = {
	//front 0,1,2,3
{ -1.0,  1.0,  1.0 },//0
{ 1.0,  1.0,  1.0 },//1
{ 1.0, -1.0,  1.0 },//2
{ -1.0, -1.0,  1.0 },//3
					 //left 0,3,4,6
{ -1.0,  1.0,  1.0 },//4
{ -1.0, -1.0,  1.0 },//5
{ -1.0,  1.0, -1.0 },//6
{ -1.0, -1.0, -1.0 },//7
					//back 4,5,6,7
{ -1.0,  1.0, -1.0 },//8
{ 1.0,  1.0, -1.0 },//9
{ 1.0, -1.0, -1.0 },//10
{ -1.0, -1.0, -1.0 },//11
					 //right 1,2,5,7
{ 1.0,  1.0,  1.0 },//12
{ 1.0, -1.0,  1.0 },//13
{ 1.0,  1.0, -1.0 },//14
{ 1.0, -1.0, -1.0 },//15
					 //bot 2,3,6,7
{ 1.0, -1.0,  1.0 },//16
{ -1.0, -1.0,  1.0 },//17
{ 1.0, -1.0, -1.0 },//18
{ -1.0, -1.0, -1.0 },//19
					 //top 0,1,4,5
{ -1.0,  1.0,  1.0 },//20
{ 1.0,  1.0,  1.0 },//21
{ -1.0,  1.0, -1.0 },//22
{ 1.0,  1.0, -1.0 },//23

};

/*
Struct to hold data for object rendering.
*/
struct Object
{
	/* IDs for several buffers. */
	GLuint vao;

	GLuint positionBuffer;
	GLuint colorBuffer;

	GLuint indexBuffer;

	/* Model matrix */
	glm::mat4x4 model;
};

Object quad;
Object coordinates;

void renderQuad()
{
	// Create mvp.
	glm::mat4x4 mvp = projection * view * quad.model;

	// Bind the shader program and set uniform(s).
	program.use();
	program.setUniform("mvp", mvp);
	
	// Bind vertex array object so we can render the 2 triangles.
	glBindVertexArray(quad.vao);
	glDrawElements(GL_TRIANGLES, 6*6, GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
}

void renderCoordinates()
{
	// Create mvp.
	glm::mat4x4 mvp = projection * view * coordinates.model;

	// Bind the shader program and set uniform(s).
	program.use();
	program.setUniform("mvp", mvp);

	// Bind vertex array object so we can render the 2 triangles.
	glBindVertexArray(coordinates.vao);
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
}

void initCoordinates()
{
	// Construct triangle. These vectors can go out of scope after we have send all data to the graphics card.
	const std::vector<glm::vec3> vertices = { glm::vec3(-100.0f, 0.0f, 0.0f), glm::vec3(100.0f, 0.01f, 0.0f), glm::vec3(100.0f, 0.0f, 0.0f), 
		glm::vec3(0.01f, 100.0f, 0.0f), glm::vec3(0.0f, -100.0f, 0.0f), glm::vec3(0.0f, 100.0f, 0.0f),
		glm::vec3(0.001f, 0.001f, 100.0f), glm::vec3(0.0f, 0.0f, 100.0f), glm::vec3(0.001f, 0.0f, -100.0f) };
	const std::vector<glm::vec3> colors = { glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), 
		glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), 
		glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f) };
	const std::vector<GLushort> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8};

	GLuint programId = program.getHandle();
	GLuint pos;

	// Step 0: Create vertex array object.
	glGenVertexArrays(1, &coordinates.vao);
	glBindVertexArray(coordinates.vao);

	// Step 1: Create vertex buffer object for position attribute and bind it to the associated "shader attribute".
	glGenBuffers(1, &coordinates.positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, coordinates.positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	// Bind it to position.
	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 2: Create vertex buffer object for color attribute and bind it to...
	glGenBuffers(1, &coordinates.colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, coordinates.colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	// Bind it to color.
	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 3: Create vertex buffer object for indices. No binding needed here.
	glGenBuffers(1, &coordinates.indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, coordinates.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), indices.data(), GL_STATIC_DRAW);

	// Unbind vertex array object (back to default).
	glBindVertexArray(0);

	// Modify model matrix.
	coordinates.model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
}

void initQuad()
{
	const std::vector<glm::vec3> colors = {
	//front rot
	{ 1.0, 0.0, 0.0 },
	{ 1.0, 0.0, 0.0 },
	{ 1.0, 0.0, 0.0 },
	{ 1.0, 0.0, 0.0 },
	
	//left gelb
	{ 1.0, 1.0, 0.0 },
	{ 1.0, 1.0, 0.0 },
	{ 1.0, 1.0, 0.0 },
	{ 1.0, 1.0, 0.0 },
	
	//back magenta
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	
	//right grün
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	
	//bot blau
	{ 0.0, 0.0, 1.0 },
	{ 0.0, 0.0, 1.0 },
	{ 0.0, 0.0, 1.0 },
	{ 0.0, 0.0, 1.0 },
	
	//top cyan
	{ 0.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 },
	};
	
	const std::vector<GLushort> indices = {

		//front
		0, 1, 2,
		2, 3, 0,
		// right
		12, 13, 14,
		13, 14, 15,
		// back
		8, 9, 10,
		8, 10, 11,
		// left
		4, 5, 6,
		5, 6, 7,
		// bottom
		16, 17, 18,
		17, 18, 19,
		// top
		20, 21, 22,
		21, 22, 23
	};

	GLuint programId = program.getHandle();
	GLuint pos;

	// Step 0: Create vertex array object.
	glGenVertexArrays(1, &quad.vao);
	glBindVertexArray(quad.vao);

	// Step 1: Create vertex buffer object for position attribute and bind it to the associated "shader attribute".
	glGenBuffers(1, &quad.positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, quad.positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	// Bind it to position.
	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 2: Create vertex buffer object for color attribute and bind it to...
	glGenBuffers(1, &quad.colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, quad.colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	// Bind it to color.
	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 3: Create vertex buffer object for indices. No binding needed here.
	glGenBuffers(1, &quad.indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), indices.data(), GL_STATIC_DRAW);

	// Unbind vertex array object (back to default).
	glBindVertexArray(0);

	// Modify model matrix.
	quad.model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_TEST);
}

/*
 Initialization. Should return true if everything is ok and false if something went wrong.
 */
bool init()
{
	// OpenGL: Set "background" color and enable depth testing.
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

	// Construct view matrix.
	glm::vec3 eye(0.0f, 0.0f, zoomy);
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

	// Create objects.
	initQuad();
	initCoordinates();
	return true;
}

/*
 Release object resources.
*/
void releaseObject(Object& obj)
{
	glDeleteVertexArrays(1, &obj.vao);
	glDeleteBuffers(1, &obj.indexBuffer);
	glDeleteBuffers(1, &obj.colorBuffer);
	glDeleteBuffers(1, &obj.positionBuffer);
}

/*
 Release resources on termination.
 */
void release()
{
	// Shader program will be released upon program termination.
	releaseObject(quad);
	releaseObject(coordinates);
}

/*
 Rendering.
 */
void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	renderQuad();
	renderCoordinates();
}

void glutDisplay ()
{
   GLCODE(render());
   glutSwapBuffers();
}

/*
 Resize callback.
 */
void glutResize (int width, int height)
{
	// Division by zero is bad...
	height = height < 1 ? 1 : height;
	glViewport(0, 0, width, height);

	// Construct projection matrix.
	projection = glm::perspective(45.0f, (float) width / height, zNear, zFar);
}

/*
Callback for dings mit der Maus.
*/
void glutMouse(int button, int state, int x, int y)
{
	//weil ich zu faul bin meinen Finger bis zum Esc oder dem X oben rechts zu bewegen
	if (button == GLUT_RIGHT_BUTTON)
	{
		glutDestroyWindow(glutID);
	}
}

void zoom() {
	glm::vec3 eye(0.0f, 0.0f, zoomy);
	glm::vec3 center(0.0f, 0.0f, 0.0f);
	glm::vec3 up(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(eye, center, up);
}

void rotateX() {
	float winkel = 0.1f;
	for (int i = 0; i < vertices.size(); i++) {
		vertices[i] = glm::rotateX(vertices[i],winkel);
	}
}

void rotateY() {
	float winkel = 0.1f;
	for (int i = 0; i < vertices.size(); i++) {
		vertices[i] = glm::rotateY(vertices[i], winkel);
	}
}

void rotateZ() {
	float winkel = 0.1f;
	for (int i = 0; i < vertices.size(); i++) {
		vertices[i] = glm::rotateZ(vertices[i], winkel);
	}
}

/*
 Callback for char input.
 */
void glutKeyboard (unsigned char keycode, int x, int y)
{
	switch (keycode)
	{
	case 27: // ESC
	  glutDestroyWindow ( glutID );
	  return;
	  
	case 'a':
		if (zoomy < 10.0f) {
			zoomy += 0.1f;
			zoom();
		}
		break;
	case 's':
		if (zoomy > 3.0f) {
			zoomy -= 0.1f;
			zoom();
		}
		break;
	case 'x':
		rotateX();
		releaseObject(quad);
		glClear(GL_DEPTH_BUFFER_BIT);
		initQuad();
		break;
	case 'y':
		rotateY();
		releaseObject(quad);
		glClear(GL_DEPTH_BUFFER_BIT);
		initQuad();
		break;
	case 'z':
		rotateZ();
		releaseObject(quad);
		glClear(GL_DEPTH_BUFFER_BIT);
		initQuad();
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	// GLUT: Initialize freeglut library (window toolkit).
        glutInitWindowSize    (WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(40,40);
	glutInit(&argc, argv);

	// GLUT: Create a window and opengl context (version 4.3 core profile).
	glutInitContextVersion(4, 3);
	glutInitContextFlags  (GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);
	glutInitDisplayMode   (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("Aufgabenblatt 01");
	glutID = glutGetWindow();

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
	glutMouseFunc(glutMouse);

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
	glutMainLoop ();

	// Clean up everything on termination.
	release();

	return 0;
}
