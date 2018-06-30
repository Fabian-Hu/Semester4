#include "Halfedge.h"

bool HalfEdgeList::pairTest() {
	int anzahl=edges.size();
	std::cout << "Anzahl Edges: " << anzahl << std::endl;
	for (int i = 0;i < anzahl;i++) {
		if (edges.at(i) != edges.at(i)->pair->pair) {
			return false;
		}
		if (edges.at(i)->pair->vert != edges.at(i)->next->vert) {
			return false;
		}
	}
	
	return true;
}

bool HalfEdgeList::faceTest() {
	return true;
}

bool HalfEdgeList::vertTest() {
	return true;
}