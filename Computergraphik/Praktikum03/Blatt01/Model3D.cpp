#include "Model3D.h"

void Model3D::addFace (Face & face) {
	faces.push_back (face);
}

void Model3D::init (cg::GLSLProgram &program) {
	const std::vector<glm::vec3> vertices = { glm::vec3 (-1.0f, 1.0f, 0.0f), glm::vec3 (1.0f, -1.0f, 0.0f), glm::vec3 (1.0f, 1.0f, 0.0f) };
	const std::vector<glm::vec3> colors = { glm::vec3 (1.0f, 0.0f, 0.0f), glm::vec3 (0.0f, 1.0f, 0.0f), glm::vec3 (0.0f, 0.0f, 1.0f) };
	const std::vector<GLushort> indices = { 0, 1, 2 };

	GLuint programId = program.getHandle ();
	GLuint pos;

	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);

	glGenBuffers (1, &positionBuffer);
	glBindBuffer (GL_ARRAY_BUFFER, positionBuffer);
	glBufferData (GL_ARRAY_BUFFER, vertices.size () * sizeof (glm::vec3), vertices.data (), GL_STATIC_DRAW);

	pos = glGetAttribLocation (programId, "position");
	glEnableVertexAttribArray (pos);
	glVertexAttribPointer (pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers (1, &colorBuffer);
	glBindBuffer (GL_ARRAY_BUFFER, colorBuffer);
	glBufferData (GL_ARRAY_BUFFER, colors.size () * sizeof (glm::vec3), colors.data (), GL_STATIC_DRAW);

	pos = glGetAttribLocation (programId, "color");
	glEnableVertexAttribArray (pos);
	glVertexAttribPointer (pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers (1, &indexBuffer);
	glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData (GL_ELEMENT_ARRAY_BUFFER, indices.size () * sizeof (GLushort), indices.data (), GL_STATIC_DRAW);

	glBindVertexArray (0);

	model = glm::translate (glm::mat4 (1.0f), glm::vec3 (0.0f, 0.0f, 0.0f));

}

void Model3D::render (cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection) {
	glm::mat4x4 mvp = projection * view * model;

	program.use ();
	program.setUniform ("mvp", mvp);

	glBindVertexArray (vao);
	glDrawElements (GL_TRIANGLES, faces.size() * 3, GL_UNSIGNED_SHORT, 0);
	glBindVertexArray (0);
}

void Model3D::calculateModel () {
	GLushort i = 0;
	for (Face &face : faces) {
		std::vector<glm::vec3> faceVertices = face.getVertices ();
		vertices.insert (vertices.end (), faceVertices.begin (), faceVertices.end ());

		std::vector<glm::vec3> faceColors = face.getColors ();
		colors.insert (colors.end (), faceColors.begin (), faceColors.end ());

		for (GLushort index : face.getIndices ()) {
			indices.push_back ((GLushort)(i * 3 + index));
		}
		i++;
	}
}
