#version 330 core

in vec3 position;
in vec3 color;
in vec3 normal;

uniform mat4 mvp;  // model-view-projection
uniform mat4 model;  // model matrix
uniform mat3 nm;   // normal matrix
uniform vec4 light;
uniform vec3 viewpoint;
uniform vec3 material;
uniform int shininess;

smooth out vec3 fragmentColor;

void main()
{
	vec3  n     = normalize(nm * normal);
	vec3 lightDir;
	if (light.w == 0) {
		lightDir = normalize(light.xyz * -1);
	} else {
		lightDir = normalize(light.xyz - (model * vec4(position,  1.0)).xyz);
	}
	
	//Betrachtungsrichtung
	vec3 v;
	if (light.w == 0) {
		v = normalize(position - viewpoint);
	} else {
		v = normalize((model * vec4(position,  1.0)).xyz - viewpoint);
	}
	vec3 r = reflect(lightDir, n);
	vec3 h = (lightDir + v * -1)/length(lightDir + v * -1);

	float id = material.x * dot(lightDir, n);
	float is = 0;
	if (light.w == 0) {
		//Licht ist unendlich weit weg
		is = pow(max(0.0f, dot(n, h)), shininess);
	} else {
		is = pow(max(0.0f, dot(r, v)), shininess / 4);
	}
	is *= material.y;
	float ia = material.z * 0.1f;

	//Lichtquelle und Umgebungslicht ist weiﬂ
	fragmentColor[0] = max(0.0f, color[0] * id + is + ia);
	fragmentColor[1] = max(0.0f, color[1] * id + is + ia);
	fragmentColor[2] = max(0.0f, color[2] * id + is + ia);

	gl_Position  = mvp * vec4(position,  1.0);
}