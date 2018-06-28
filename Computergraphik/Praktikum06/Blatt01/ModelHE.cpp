#include "ModelHE.h"

ModelHE::ModelHE(GLenum mode, HE_Object *heObject) : 
	Model(mode), heObject(heObject) {
}

ModelHE::ModelHE(GLenum mode, glm::vec3 position, HE_Object *heObject) : 
	Model(mode, position), heObject(heObject) {
}

void ModelHE::build() {

}
