#pragma once

struct HE_edge {
	HE_vert* vert; // start-vertex of the half-edge
	HE_edge* pair; // oppositely oriented adjacent half-edge
	HE_face* face; // face the half-edge borders
	HE_edge* next; // next half-edge around the face
};
struct HE_vert {
	float x;
	float y;
	float z;
	HE_edge* edge; // one of the half-edges emanating from the vertex
};
struct HE_face {
	HE_edge* edge; // one of the half-edges bordering the face
};