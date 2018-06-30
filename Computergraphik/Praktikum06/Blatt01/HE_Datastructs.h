#pragma once
#include <vector>

struct HE_edge;
struct HE_vert;
struct HE_face;

struct HE_edge {
	HE_vert *vert;
	HE_normal *normal;
	HE_edge *pair;
	HE_face *face;
	HE_edge *next;
};

struct HE_vert {
	float x;
	float y;
	float z;

	std::vector<HE_edge *> pointingEdges;
	HE_edge *edge;
	HE_normal *approxNormal;
};

struct HE_face {
	HE_edge *edge;
};

struct HE_normal{
	float x;
	float y;
	float z;
};

struct HE_Object {
	std::vector<HE_edge *> edges;
	std::vector<HE_vert *> verts;
	std::vector<HE_face *> face;
	std::vector<HE_normal *> normals;

	bool testEdges();
	bool testFaces();
	bool testVertices();
	bool testAll();
};
