#include "Halfedge.h"

bool HalfEdgeList::pairTest() {
	int anzahl = edges.size();

	std::cout << "Anzahl Edges: " << anzahl << std::endl;
	for (int i = 0; i < anzahl; i++) {
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
	int anzahl = fratzen.size();
	int valenz = 0;

	std::cout << "Anzahl Faces: " << anzahl << std::endl;
	for (int i = 0; i < anzahl; i++) {
		valenz = 0;
		HE_edge *edge = fratzen.at(i)->edge;
		do {
			if (edge->face != fratzen.at(i)) {
				return false;
			}
			edge = edge->next;
			valenz++;
		} while (edge != fratzen.at(i)->edge);
		//std::cout << "Face " << i + 1 << ": " << valenz << " Valenzen" << std::endl;
	}
	return true;
}

bool HalfEdgeList::vertTest() {
	int anzahl = vertices.size();
	int valenz = 0;

	std::cout << "Anzahl Vertices: " << anzahl << std::endl;
	for (int i = 0; i < anzahl; i++) {
		valenz = 0;
		HE_edge *edge = vertices.at(i)->edge;
		do {
			std::cout << "Vertice Next: " << edge->vert->x << " Vertice FIX: " << vertices.at(i)->x << std::endl;
			if (edge->vert != vertices.at(i)) {
				return false;
			}
			edge = edge->pair->next;
			valenz++;
		} while (edge != vertices.at(i)->edge);
		//std::cout << "Vertice " << i + 1 << ": " << valenz << " Valenzen" << std::endl;
	}
	return true;
}