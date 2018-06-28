#include "HE_Datastructs.h"
#include <iostream>
#include <map>

bool HE_Object::testEdges() {
	int num = 0;
	for (HE_edge *edge : edges) {
		if (edge != edge->pair->pair) {
			return false;
		}
		if (edge->pair->vert != edge->next->vert) {
			return false;
		}
		num++;
	}
	std::cout << "Edges: " << num << std::endl;
	return true;
}

bool HE_Object::testFaces() {
	int num = 0;
	std::map<int, int> valenz;
	for (HE_face *face : HE_Object::face) {
		HE_edge *startEdge = face->edge;
		HE_edge *next = startEdge;

		int faceValenz = 0;
		do {
			if (next->face != face) {
				return false;
			}
			next = next->next;
			faceValenz++;
		} while (next != startEdge);

		num++;
		if (valenz.find(faceValenz) != valenz.end()) {
			valenz[faceValenz]++;
		}
		else {
			valenz.insert(std::pair<int, int>(faceValenz, 1));
		}
	}

	std::cout << "Faces: " << num << std::endl;
	std::cout << "Valenzen: " << std::endl;
	for (std::map<int, int>::iterator it = valenz.begin(); it != valenz.end(); it++) {
		std::cout << "\tValenz: " << it->first << "\tAnzahl: " << it->second << std::endl;
	}
	return true;
}

bool HE_Object::testVertices() {
	int num = 0;
	std::map<int, int> valenz;
	for (HE_vert *vert : verts) {
		HE_edge *startEdge = vert->edge;
		HE_edge *next = vert->edge;

		int vertValenz = 0;
		do {
			if (next->vert != vert) {
				return false;
			}
			next = next->pair;
			next = next->next;
			vertValenz++;
		} while (next != startEdge);
		num++;
		if (valenz.find(vertValenz) != valenz.end()) {
			valenz[vertValenz]++;
		}
		else {
			valenz.insert(std::pair<int, int>(vertValenz, 1));
		}
	}

	std::cout << "Vertices: " << num << std::endl;
	std::cout << "Valenzen: " << std::endl;
	for (std::map<int, int>::iterator it = valenz.begin(); it != valenz.end(); it++) {
		std::cout << "\tValenz: " << it->first << "\tAnzahl: " << it->second << std::endl;
	}
	return true;
}

bool HE_Object::testAll() {
	bool edges = testEdges();
	std::cout << "Edgetest: " << edges << std::endl << std::endl;

	bool faces = testFaces();
	std::cout << "Facetest: " << faces << std::endl << std::endl;

	bool verts = testVertices();
	std::cout << "Vertextest: " << verts << std::endl << std::endl;

	std::cout << "Gesamtergebniss: " << (edges && faces && verts) << std::endl;
	return edges && faces && verts;
}
