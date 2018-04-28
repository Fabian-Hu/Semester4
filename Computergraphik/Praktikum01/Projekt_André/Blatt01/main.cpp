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

#include <stdlib.h>

// Standard window width
const int WINDOW_WIDTH  = 640;
// Standard window height
const int WINDOW_HEIGHT = 480;
// GLUT window id/handle
int glutID = 0;

cg::GLSLProgram program;

glm::mat4x4 view;
glm::mat4x4 projection;

glm::vec3 center(0.0f, 0.0f, 0.0f);
glm::vec3 startpoint(0.0f, 1.0f, 0.0f);

glm::vec3 colorBlue(0.0f, 0.6f, 1.0f);

const int MIN_EDGES = 3;
const int MAX_EDGES = 30;
int edges = 5;

const float MIN_CIRCLESIZE = 0.2f;
const float MAX_CIRCLESIZE = 2.0f;
float size = 1.0f;

float zNear = 0.1f;
float zFar  = 100.0f;

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

Object circle;

float calculateAngle(int edges)
{
	return 360.0f / edges;
}

void calculateNextPos(double angle, glm::vec3 *newpos)
{
	newpos->x = size * glm::cos(glm::radians(angle + 90));
	newpos->y = size * glm::cos(glm::radians(angle));
}

void renderCircle()
{
	// Create mvp.
	glm::mat4x4 mvp = projection * view * circle.model;

	// Bind the shader program and set uniform(s).
	program.use();
	program.setUniform("mvp", mvp);

	// Bind vertex array object so we can render the 1 triangle.
	glBindVertexArray(circle.vao);
	glDrawElements(GL_TRIANGLES, edges *3, GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
}

void initCircle(std::vector<glm::vec3> vertices, std::vector<glm::vec3> colors, std::vector<GLushort> indices)
{

	GLuint programId = program.getHandle();
	GLuint pos;

	// Step 0: Create vertex array object.
	glGenVertexArrays(1, &circle.vao);
	glBindVertexArray(circle.vao);

	// Step 1: Create vertex buffer object for position attribute and bind it to the associated "shader attribute".
	glGenBuffers(1, &circle.positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, circle.positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	// Bind it to position.
	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 2: Create vertex buffer object for color attribute and bind it to...
	glGenBuffers(1, &circle.colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, circle.colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	// Bind it to color.
	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 3: Create vertex buffer object for indices. No binding needed here.
	glGenBuffers(1, &circle.indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, circle.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), indices.data(), GL_STATIC_DRAW);

	// Unbind vertex array object (back to default).
	glBindVertexArray(0);

	// Modify model matrix.
	circle.model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
}

void calculateCircle()
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices;
	float angle = calculateAngle(edges);
	vertices.push_back(center);
	colors.push_back(colorBlue);

	for (int i = 0; i < edges; i++)
	{
		glm::vec3 singleVert;
		calculateNextPos(i * angle, &singleVert);
		vertices.push_back(singleVert);

		colors.push_back(colorBlue);
		if (i == edges - 1)
		{
			indices.push_back(0);
			indices.push_back(1);
			indices.push_back(i + 1);
		}
		else
		{
			indices.push_back(0);
			indices.push_back(i + 1);
			indices.push_back(i + 2);
		}
	}
	initCircle(vertices, colors, indices);
}

void calculateMulticolorCircle()
{
	srand(3141592);
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLushort> indices;
	float angle = calculateAngle(edges);

	for (int i = 0; i < edges; i++)
	{
		glm::vec3 randCol((double) rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
		glm::vec3 firstVert;
		glm::vec3 secondVert;
		calculateNextPos(i * angle, &firstVert);
		if (i+1 >= edges)
			calculateNextPos(0, &secondVert);
		else
			calculateNextPos((i + 1) * angle, &secondVert);
		vertices.push_back(firstVert);
		vertices.push_back(secondVert);
		vertices.push_back(center);

		colors.push_back(randCol);
		colors.push_back(randCol);
		colors.push_back(randCol);

		indices.push_back(i * 3);
		indices.push_back(i * 3 + 1);
		indices.push_back(i * 3 + 2);
	}
	std::cout << std::endl;
	std::cout << angle << std::endl;
	initCircle(vertices, colors, indices);
}

/*
 Initialization. Should return true if everything is ok and false if something went wrong.
 */
bool init()
{
	// OpenGL: Set "background" color and enable depth testing.
	glClearColor(1.0f, 0.9f, 0.0f, 1.0f);

	// Construct view matrix.
	glm::vec3 eye(0.0f, 0.0f, 4.0f);
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
	calculateMulticolorCircle();

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
	releaseObject(circle);
}

/*
 Rendering.
 */
void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	renderCircle();
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
 Callback for char input.
 */
void glutKeyboard (unsigned char keycode, int x, int y)
{
	switch (keycode)
	{
	case 27: // ESC
	  glutDestroyWindow ( glutID );
	  return;
	  
	case '+':
		// do something
		if (edges < MAX_EDGES)
			edges++;
		break;
	case '-':
		// do something
		if (edges > MIN_EDGES)
			edges--;
		break;
	case 'q':
		// do something
		if (size < MAX_CIRCLESIZE)
			size += 0.05f;
		break;
	case 'w':
		// do something
		if (size > MIN_CIRCLESIZE)
			size -= 0.05f;
		break;
	}
	calculateMulticolorCircle();
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
