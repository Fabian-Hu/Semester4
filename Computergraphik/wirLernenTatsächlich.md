## 0 - Intro

sehr uninteressant, bis auf das Bild von Patrick

## 1 - Einführung

### Was ist dieses Computergrafik, von dem alle reden?

Computergrafik beschäftigt sich mit mathematischen und algorithmischen Ansätzen, die der Erzeugung von Bildern am Rechner dienen. 

Low-level Software-Zugang:

* Moderne Software-Schichten kapseln in Form von APIs, wie z. B. OpenGL oder Direct3D, zunehmend höhere Funktionalitäten
* Zugang eines breiten Kreises von Anwendungsprogrammierern zu Computergrafik-Möglichkeiten

High-level Software-Zugang:

* Moderne Werkzeuge, wie z. B. 3D Studio Max oder Maya ermöglichen den komfortablen Umgang mit Computergrafiktechniken für eine breite Anwenderschicht 

![pipelini](D:\Studium\Semester4\Semester4\Computergraphik\Bilder\pipelini.PNG)

## 2 - OpenGL 

![Shader](D:\Studium\Semester4\Semester4\Computergraphik\Bilder\Shader.PNG)



```c++
#include <vector>
#include "GLSLProgram.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include "glm/gtx/rotate_vector.hpp"
#include "GLTools.h"

void render(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection)
{
    // Create mvp.
    glm::mat4x4 mvp = projection * view * object.model;

    // Bind the shader program and set uniform(s).
    program.use();
    program.setUniform("mvp", mvp);

    // Bind vertex array object so we can render
    glBindVertexArray(coordinates.vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
}

void initQuad()
{
    // Construct quad. These vectors can go out of scope after we have send all data to the graphics card.
    const std::vector<glm::vec3> vertices = { { -1.0f, 1.0f, 0.0f }, { -1.0, -1.0, 0.0 }, { 1.0f, -1.0f, 0.0f }, { 1.0f, 1.0f, 0.0f } };
    const std::vector<glm::vec3> colors = { { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } };
    const std::vector<GLushort> indices = { 0, 1, 2, 0, 2, 3 };

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
    quad.model = glm::translate(glm::mat4(1.0f), glm::vec3(1.25f, 0.0f, 0.0f));
}

void releaseObject()
{
	glDeleteVertexArrays(1, &object.vao);
	glDeleteBuffers(1, &object.indexBuffer);
	glDeleteBuffers(1, &object.colorBuffer);
	glDeleteBuffers(1, &object.positionBuffer);
}

bool init()
{
    // OpenGL: Set "background" color and enable depth testing.
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

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
    initQuad();

    return true;
}

void glutKeyboard (unsigned char keycode, int x, int y)
{
	switch (keycode)
	{
	case 27: // ESC
	  glutDestroyWindow ( glutID );
	  return;
	case '+':
		// do something
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
    // GLUT: Initialize freeglut library (window toolkit).
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
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

```





## 3 - Grundbegriffe

