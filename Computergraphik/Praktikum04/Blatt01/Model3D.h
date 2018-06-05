#pragma once
#include "Face.h"
#include "Model.h"

class Model3D : public Model {
public:
	Model3D(GLenum mode);
	Model3D(GLenum mode, glm::vec3 position);
	void addFace (Face &face);
	void init(cg::GLSLProgram & program);
	virtual void build();

private:
	friend class WireframeSphere;
	friend class Sphere;
	friend class Axis;
	std::vector<Face> faces;

	std::vector<glm::vec3> points;
	std::vector<int> points_vertices;

	void calculateModel ();
	int insertPoint(glm::vec3 &point);
	int containsVertexColor(int index, glm::vec3 &color);
};
