#include "ModelHE.h"
#include <time.h>

ModelHE::ModelHE()
{
}

ModelHE::ModelHE(HalfEdgeList *halfEdgeList) :
	halfEdgeList(halfEdgeList)
{
}

void ModelHE::render(cg::GLSLProgram & program, glm::mat4x4 view, glm::mat4x4 projection)
{
	// Create mvp.
	glm::mat4x4 mvp = projection * view * object.model;

	// Bind the shader program and set uniform(s).
	program.use();
	program.setUniform("mvp", mvp);

	// Bind vertex array object so we can render the 2 triangles.
	glBindVertexArray(object.vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void ModelHE::calculateMaxNums() {
	float xMax = vertices[0].x;
	float xMin = vertices[0].x;

	float yMax = vertices[0].y;
	float yMin = vertices[0].y;

	float zMax = vertices[0].z;
	float zMin = vertices[0].z;

	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].x > xMax) {
			xMax = vertices[i].x;
		}
		if (vertices[i].x < xMin) {
			xMin = vertices[i].x;
		}

		if (vertices[i].y > yMax) {
			yMax = vertices[i].y;
		}
		if (vertices[i].y < yMin) {
			yMin = vertices[i].y;
		}

		if (vertices[i].z > zMax) {
			zMax = vertices[i].z;
		}
		if (vertices[i].z < zMin) {
			zMin = vertices[i].z;
		}
	}

	ModelHE::maxNums.xMax = xMax;
	ModelHE::maxNums.xMin = xMin;
	std::cout << "max " << ModelHE::maxNums.xMax << std::endl;
	std::cout << "x " << ModelHE::maxNums.xMin << std::endl;

	ModelHE::maxNums.yMax = yMax;
	ModelHE::maxNums.yMin = yMin;
	std::cout << "x " << ModelHE::maxNums.yMax << std::endl;
	std::cout << "x " << ModelHE::maxNums.yMin << std::endl;

	ModelHE::maxNums.zMax = zMax;
	ModelHE::maxNums.zMin = zMin;
	std::cout << "x " << ModelHE::maxNums.zMax << std::endl;
	std::cout << "x " << ModelHE::maxNums.zMin << std::endl;

	ModelHE::maxNums.xMiddle = ((xMax + xMin) / 2);
	ModelHE::maxNums.xDiff = xMax - xMin;
	std::cout << "xMiddle " << ModelHE::maxNums.xMiddle << std::endl;
	std::cout << "x " << ModelHE::maxNums.xDiff << std::endl;

	ModelHE::maxNums.yMiddle = ((yMax + yMin) / 2);
	ModelHE::maxNums.yDiff = yMax - yMin;
	std::cout << "x " << ModelHE::maxNums.yMiddle << std::endl;
	std::cout << "x " << ModelHE::maxNums.yDiff << std::endl;

	ModelHE::maxNums.zMiddle = ((zMax + zMin) / 2);
	ModelHE::maxNums.zDiff = zMax - zMin;
	std::cout << "x " << ModelHE::maxNums.zMiddle << std::endl;
	std::cout << "x " << ModelHE::maxNums.zDiff << std::endl;
}

void ModelHE::calculate() {
	//facelist nehmen
	std::vector<HE_face*> facelist = halfEdgeList->fratzen;
	srand((unsigned)time(NULL));
	float r = (float)rand() / RAND_MAX;
	glm::vec3 farbe = glm::vec3(r, r, r);
	//glm::vec3 farbe = glm::vec3(0.9f, 0.9f, 0.9f);
	int counter = 0;
	int i = 0;
	//nacheinander jedes face nehmen
	for (i = 0; i < facelist.size(); i++) {// facelist.size()
		HE_face* face = facelist.at(i);
		HE_edge* nullterEdge = facelist.at(i)->edge;
		HE_edge* ersterEdge = facelist.at(i)->edge->next;
		HE_edge* zweiterEdge = facelist.at(i)->edge->next->next;

		r = (float)rand() / RAND_MAX;
		farbe = glm::vec3(r, r, r);
		

		while (zweiterEdge->vert != nullterEdge->vert) {
				//erster vertex ist grundlage für alle
				//mit dem nächsten und übernächsten ein Dreieck bilden und den zweiten danach eliminieren
			ModelHE::vertices.push_back(glm::vec3(nullterEdge->vert->x, nullterEdge->vert->y, nullterEdge->vert->z));
			ModelHE::vertices.push_back(glm::vec3(ersterEdge->vert->x, ersterEdge->vert->y, ersterEdge->vert->z));
			ModelHE::vertices.push_back(glm::vec3(zweiterEdge->vert->x, zweiterEdge->vert->y, zweiterEdge->vert->z));
			ModelHE::colors.push_back(farbe);
			ModelHE::colors.push_back(farbe);
			ModelHE::colors.push_back(farbe);
			ModelHE::indices.push_back(counter);
			ModelHE::indices.push_back(counter + 1);
			ModelHE::indices.push_back(counter + 2);

			ersterEdge = zweiterEdge;
			zweiterEdge = zweiterEdge->next;
			counter += 3;
		}

	}
	std::cout << "Anzahl Indices: " << counter << std::endl;
	calculateMaxNums();
}

void ModelHE::init(cg::GLSLProgram & program)
{
	// Construct triangle. These vectors can go out of scope after we have send all data to the graphics card.
	calculate();

	GLuint programId = program.getHandle();
	GLuint pos;

	// Step 0: Create vertex array object.
	glGenVertexArrays(1, &object.vao);
	glBindVertexArray(object.vao);

	// Step 1: Create vertex buffer object for position attribute and bind it to the associated "shader attribute".
	glGenBuffers(1, &object.positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, object.positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	// Bind it to position.
	pos = glGetAttribLocation(programId, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 2: Create vertex buffer object for color attribute and bind it to...
	glGenBuffers(1, &object.colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, object.colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);

	// Bind it to color.
	pos = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Step 3: Create vertex buffer object for indices. No binding needed here.
	glGenBuffers(1, &object.indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

	// Unbind vertex array object (back to default).
	glBindVertexArray(0);
	
	
	glm::vec3 position = glm::vec3((ModelHE::maxNums.xMiddle * -1), (ModelHE::maxNums.yMiddle * -1), (ModelHE::maxNums.zMiddle * -1));
	std::cout << "      " << position[0] << "      " << position[1] << "      " << position[2] << std::endl;
	object.model = glm::translate(glm::mat4x4(1.0f), position) * object.model;

	float greatness = maxDiff();
	std::cout << "great " << greatness << std::endl;
	object.model = glm::scale(glm::vec3((1/greatness)*4)) * object.model;


}

void ModelHE::releaseObject()
{
	glDeleteVertexArrays(1, &object.vao);
	glDeleteBuffers(1, &object.indexBuffer);
	glDeleteBuffers(1, &object.colorBuffer);
	glDeleteBuffers(1, &object.positionBuffer);
}

float ModelHE::maxDiff() {
	float biggest = ModelHE::maxNums.xDiff;
	std::cout << "great " << biggest << std::endl;
	if (biggest < ModelHE::maxNums.yDiff) {
		biggest = ModelHE::maxNums.yDiff;
	}
	std::cout << "great " << biggest << std::endl;
	if (biggest < ModelHE::maxNums.zDiff) {
		biggest = ModelHE::maxNums.zDiff;
	}
	std::cout << "great " << biggest << std::endl;
	return biggest;
}

float ModelHE::degreeToRadians(float angle) {
	return (angle * (float)PI / 180.0f);
}

void ModelHE::rotateX(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 xRotatierMatrix;
	xRotatierMatrix[0] = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	xRotatierMatrix[1] = glm::vec4(0.0f, cos(-radians), -sin(-radians), 0.0f);
	xRotatierMatrix[2] = glm::vec4(0.0f, sin(-radians), cos(-radians), 0.0f);
	xRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	object.model = xRotatierMatrix * object.model;
}

void ModelHE::rotateY(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 yRotatierMatrix;
	yRotatierMatrix[0] = glm::vec4(cos(-radians), 0.0f, sin(-radians), 0.0f);
	yRotatierMatrix[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	yRotatierMatrix[2] = glm::vec4(-sin(-radians), 0.0f, cos(-radians), 0.0f);
	yRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	object.model = yRotatierMatrix * object.model;
}

void ModelHE::rotateZ(float angle)
{
	float radians = degreeToRadians(angle);

	glm::mat4x4 zRotatierMatrix;
	zRotatierMatrix[0] = glm::vec4(cos(-radians), -sin(-radians), 0.0f, 0.0f);
	zRotatierMatrix[1] = glm::vec4(sin(-radians), cos(-radians), 0.0f, 0.0f);
	zRotatierMatrix[2] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	zRotatierMatrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	object.model = zRotatierMatrix * object.model;
}