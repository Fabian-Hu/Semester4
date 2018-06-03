#include "Masterding.h"
#include "Himmelsding.h"
#include "Moons.h"
#include "Achse.h"

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
float zoomx = 0.0f;
float zoomy = 0.0f;
float zoomz = 40.0f;

Himmelsding sonne;
Achse allesDrehtSichUmMich(0.0f, 0.0f, 0.0f, 3.0f);

Himmelsding uranus(8.0f, 0.0f, 0.0f, 0.4f);
Achse urAchse(8.0f, 0.0f, 0.0f, 1.2f);
Moons uranusMoons(&uranus, 3);

Himmelsding pluto(-12.0f, 0.0f, 0.0f, 0.3f, 45.0f);
Achse pluse(-12.0f, 0.0f, 0.0f, 0.9f, 45.0f);
Moons plutoMoons(&pluto, 3, 4, 2, 4, 2.0f);

/*
 Initialization. Should return true if everything is ok and false if something went wrong.
 */
bool init()
{
	// OpenGL: Set "background" color and enable depth testing.
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	// Construct view matrix.
	glm::vec3 eye(zoomx, zoomy, zoomz);
	glm::vec3 center(0.0f, 0.0f, 0.0f);
	glm::vec3 up(0.0f, 0.10f, 0.0f);

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

	// Create all objects.
	// GLUT: create vertex-array-object for glut geometry, the "default"
	// must be bound before the glutWireSphere call
	sonne.init(program);
	uranus.init(program);
	pluto.init(program);

	uranusMoons.init(program);
	//plutoMoons.init(program);

	allesDrehtSichUmMich.init(program);
	urAchse.init(program);
	pluse.init(program);
	return true;
}

/*
 Release resources on termination.
 */
void release()
{
	// Shader program will be released upon program termination.

	sonne.releaseObject();
	uranus.releaseObject();
	pluto.releaseObject();

	uranusMoons.releaseObject();
	//plutoMoons.releaseObject();

	allesDrehtSichUmMich.releaseObject();
	urAchse.releaseObject();
	pluse.releaseObject();
}

/*
 Rendering.
 */
void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	sonne.render(program, view, projection);
	uranus.render(program, view, projection);
	pluto.render(program, view, projection);

	uranusMoons.render(program, view, projection);
	//plutoMoons.render(program, view, projection);

	allesDrehtSichUmMich.render(program, view, projection);
	urAchse.render(program, view, projection);
	pluse.render(program, view, projection);
}

void glutDisplay ()
{
   
   //uranus.rotateY(0.7f);
   //urAchse.rotateY(0.7f);
   //uranusMoons.rotateY(0.7f);
   //pluto.rotateY(0.5f);
   //pluse.rotateY(0.5f);
   //plutoMoons.rotateY(0.5f);
   
   //GLCODE(render());
	render();
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

void zoom() {
	glm::vec3 eye(zoomx, zoomy, zoomz);
	glm::vec3 center(0.0f, 0.0f, 0.0f);
	glm::vec3 up(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(eye, center, up);
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
	else if (button == 4) {
		if (zoomz < 60.0f) {
			zoomz += 1.0f;
			zoom();
		}
	}
	else if (button == 3) {
		if (zoomz > 12.0f) {
			zoomz -= 1.0f;
			zoom();
		}
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
	  
	case 't':
		
		break;
	case 'T':
		
		break;
	case 'x':
		// do something
		break;
	case 'y':
		if (zoomy > -30.0f) {
			zoomy -= 1.0f;
			zoom();
		}
		break;
	case 'Y':
		if (zoomy < 30.0f) {
			zoomy += 1.0f;
			zoom();
		}
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

	glutCreateWindow("Aufgabenblatt 04");
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
	glutIdleFunc   (glutDisplay); // redisplay when idle

	glutKeyboardFunc(glutKeyboard);
	glutMouseFunc(glutMouse);

	// init vertex-array-objects.
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

	// Cleanup everything on termination.
	release();

	return 0;
}