#pragma once
#include <vector>

struct HE_edge;
struct HE_vert;
struct HE_face;

struct HE_normal {
	float x;
	float y;
	float z;
};

struct HE_texCoord {
	float x;
	float y;
};

struct HE_edge {
	HE_vert *vert;
	HE_normal *normal;
	HE_texCoord *texCoord;
	HE_edge *pair;
	HE_face *face;
	HE_edge *next;
};

struct HE_vert {
	float x;
	float y;
	float z;

	std::vector<int> pos;
	std::vector<HE_normal *>approxNormal;

	std::vector<HE_edge *> pointingEdges;
	HE_edge *edge;
};

struct HE_face {
	HE_edge *edge;
};

struct HE_Object {
	std::vector<HE_edge *> edges;
	std::vector<HE_vert *> verts;
	std::vector<HE_face *> face;
	std::vector<HE_normal *> normals;
	std::vector<HE_texCoord *> texCoords;

	bool testEdges();
	bool testFaces();
	bool testVertices();
	bool testAll();
};
