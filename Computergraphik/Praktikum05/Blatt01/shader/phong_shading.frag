#version 330 core

flat in vec3 fragmentColor;
smooth in vec3 fragmentPosition;
smooth in vec3 fragmentNormal;

uniform mat4 mvp;  // model-view-projection
uniform mat4 model;  // model matrix
uniform mat3 nm;   // normal matrix
uniform vec4 light;
uniform vec3 viewpoint;
uniform vec3 material;
uniform int shininess;

out vec3 fragColor;

void main()
{
	vec3  n     = normalize(nm * fragmentNormal);
	vec3 lightDir;
	if (light.w == 0) {
		lightDir = normalize(light.xyz * -1);
	} else {
		lightDir = normalize(light.xyz - (model * vec4(fragmentPosition,  1.0)).xyz);
	}
	
	//Betrachtungsrichtung
	vec3 v;
	if (light.w == 0) {
		v = normalize(viewpoint - fragmentPosition);
	} else {
		v = normalize(viewpoint - (model * vec4(fragmentPosition,  1.0)).xyz);
	}
	vec3 r = reflect(lightDir, n) * -1;
	vec3 h = (lightDir + v)/length(lightDir + v);

	float id = material.x * dot(lightDir, n);
	float is = 0;
	if (light.w == 0) {
		//Licht ist unendlich weit weg
		is = pow(max(0.0f, dot(n, h)), shininess * 4);
	} else {
		is = pow(max(0.0f, dot(r, v)), shininess);
	}
	is *= material.y;
	float ia = material.z * 0.1f;

	//Lichtquelle und Umgebungslicht ist wei�
	fragColor[0] = max(0.0f, fragmentColor[0] * id + is + ia);
	fragColor[1] = max(0.0f, fragmentColor[1] * id + is + ia);
	fragColor[2] = max(0.0f, fragmentColor[2] * id + is + ia);
}

