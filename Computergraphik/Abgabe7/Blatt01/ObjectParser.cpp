
#include "ObjectParser.h"

int counterE = 0;
HE_face* readObject(std::string filename, HalfEdgeList* halfEdgeList)
{
	std::cout << "ReadObjekt" << std::endl;
	if (filename.substr(filename.size() - 4, 4) != ".obj")
		return NULL;

	std::fstream f;
	char cstring[256];
	f.open(filename, std::ios::in);

	while (!f.eof()) {
		f.getline(cstring, sizeof(cstring));

		if (cstring[0] == 'v') {
			if (cstring[1] == 'n') {
				halfEdgeList->normals.push_back(createNormals(cstring));
			}
			else if (cstring[1] == 't') {
				halfEdgeList->textures.push_back(createTexture(cstring));
			}
			else if (cstring[1] == ' ') {
				halfEdgeList->vertices.push_back(createVert(cstring));

			}
		}
		else if (cstring[0] == 'f') {
			halfEdgeList->fratzen.push_back(createFace(cstring, halfEdgeList));

		}
		else {
			//std::cout << "nicht gefunden" << std::endl;
		}
		//memset(cstring, 0, sizeof(cstring));

		char *begin = cstring;
		char *end = begin + sizeof(cstring);
		std::fill(begin, end, 0);
	}


	f.close();
}

HE_normal* createNormals(std::string line) {
	//std::cout << "Create Normals" << std::endl;
	int i;
	HE_normal* normal = new HE_normal;
	std::vector<double> number;
	for (i = 2; i < line.length(); i++) {
		std::string vertString = "";
		if (line[i] != ' ') {
			for (int k = i; line[k] != ' ' && line[k] != '\0'; k++) {
				if (line[k] != '\0') {
					vertString += line[k];
					i++;
				}
			}

			number.push_back(::atof(vertString.c_str()));
		}
	}

	normal->x = number[0];
	normal->y = number[1];
	normal->z = number[2];

	//std::cout << "Normale X: " << normal->x << " Normale Y: " << normal->y << " Normale Z: " << normal->z << std::endl;
	return normal;
}

HE_texture* createTexture(std::string line) {
	int i;
	HE_texture* texture = new HE_texture;
	std::vector<float> number;
	for (i = 2; i < line.length(); i++) {
		std::string vertString = "";
		if (line[i] != ' ') {
			for (int k = i; line[k] != ' ' && line[k] != '\0'; k++) {
				if (line[k] != '\0') {
					vertString += line[k];
					i++;
				}
			}

			number.push_back(::atof(vertString.c_str()));
		}
	}

	texture->x = number[0];
	texture->y = number[1];
	//std::cout << "Create Texture" << std::endl;
	//std::cout << texture->x << texture->y << std::endl;
	return texture;
}

HE_face* createFace(std::string line, HalfEdgeList* halfEdgeList) {
	HE_face* face = new HE_face;
	HE_edge* edge = new HE_edge;
	HE_edge* lastEdge = new HE_edge;
	std::vector<std::string> verkettung;
	std::vector<int> number;
	std::vector<int> normals;
	std::vector<int> textures;
	int i, count = 0, endofline = 0;
	face->edge = edge;
	HE_edge* vorEdge = face->edge;

	for (i = 2; i < line.length(); i++) {
		std::string vertString = "";
		if (line[i] != ' ') {
			for (int k = i; line[k] != ' ' && line[k] != '\0'; k++) {
				if (line[k] != '\0') {
					vertString += line[k];
					i++;
				}
			}
			//std::cout << vertString.c_str() << std::endl;
			verkettung.push_back(vertString.c_str());
		}
	}

	for (i = 0; i < verkettung.size(); i++) {
		std::vector<int> temp;
		for (int j = 0; j < verkettung[i].length(); j++) {
			std::string vertString = "";
			if (verkettung[i][j] != '/') {
				for (int k = j; verkettung[i][k] != '/' && k < verkettung[i].length(); k++) {
					vertString += verkettung[i][k];
					j++;

				}

				temp.push_back(::atoi(vertString.c_str()));
			}

		}
		number.push_back(temp[0]);
		if (temp.size() > 1)
			textures.push_back(temp[1]);
		if (temp.size() > 2)
			normals.push_back(temp[2]);
	}


	for (i = 0; i < number.size(); i++) {
		//std::cout << "Face " << number.at(i) << std::endl;
		edge->vert = halfEdgeList->vertices.at(number.at(i) - 1);
		edge->face = face;
		edge->vert->edge = edge;
		edge->next = nullptr;
		if (normals.size()>0)
			edge->normal = halfEdgeList->normals.at(normals[i] - 1);
		if (textures.size()>0)
			edge->texture = halfEdgeList->textures.at(textures[i] - 1);

		if (count != 0) {
			vorEdge->next = edge;
			vorEdge = vorEdge->next;
		}
		count++;

		int nextNum = i + 1 >= number.size() ? 0 : i + 1;
		halfEdgeList->vertices[number[nextNum] - 1]->pointingEdges.push_back(edge);

		if (edge->paired == false) {
			for (int e = 0; e < edge->vert->pointingEdges.size(); e++) {
				if (halfEdgeList->vertices[number[nextNum] - 1] == edge->vert->pointingEdges[e]->vert) {
					edge->pair = edge->vert->pointingEdges.at(e);
					edge->pair->pair = edge;
					edge->paired = true;
					edge->pair->paired = true;
					edge->vert->pointingEdges.erase(edge->vert->pointingEdges.begin() + e);
				}
			}
		}

		lastEdge = edge;
		halfEdgeList->edges.push_back(edge);
		counterE++;
		edge = new HE_edge;


	}

	lastEdge->next = face->edge;
	//std::cout << "Last X: " <<lastEdge->vert->x<< " Last Y: " << lastEdge->vert->y << " Last Z: " << lastEdge->vert->z << std::endl;
	return face;
}


HE_vert* createVert(std::string line) {
	HE_vert* vertex = new HE_vert;
	std::string xString = "";
	std::string yString = "";
	std::string zString = "";

	int i;
	for (i = 2; line[i] != ' '; i++) {
		xString += line[i];
	}

	vertex->x = ::atof(xString.c_str());

	for (i = i + 1; line[i] != ' '; i++) {
		yString += line[i];
	}

	vertex->y = ::atof(yString.c_str());

	for (i = i + 1; line[i] != '\0'; i++) {
		zString += line[i];
	}

	vertex->z = ::atof(zString.c_str());

	//cout << " X: " << vertex->x << " Y: " << vertex->y << " Z: " << vertex->z << endl;
	return vertex;
}

