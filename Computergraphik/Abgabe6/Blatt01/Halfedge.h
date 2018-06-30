#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

struct HE_edge;
struct HE_vert;
struct HE_face;

struct HE_edge {
	HE_vert* vert; // start-vertex of the half-edge
	HE_edge* pair; // oppositely oriented adjacent half-edge
	HE_face* face; // face the half-edge borders
	HE_edge* next; // next half-edge around the face
	bool paired = false;
};
struct HE_vert {
	float x;
	float y;
	float z;
	HE_edge* edge; // one of the half-edges emanating from the vertex
	std::vector<HE_edge*> pointingEdges;
};
struct HE_face {
	HE_edge* edge; // one of the half-edges bordering the face
};
struct HalfEdgeList {
	std::vector<HE_face*> fratzen;
	std::vector<HE_vert*> vertices;
	std::vector<HE_edge*> edges;


	bool pairTest();
	bool faceTest();
	bool vertTest();
};

