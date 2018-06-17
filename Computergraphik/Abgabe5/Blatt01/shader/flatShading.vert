
#version 330 core

in vec3 position;
in vec3 normal;

uniform vec3 farbe;
uniform mat4 mvp;
uniform mat4 model;
uniform mat3 normaleMatrix;
uniform vec4 light;
uniform vec3 viewpoint;
uniform vec3 material;
uniform int scheinHeiligKeit;

flat out vec3 fragmentColor;

void main()
{
	float is = 0;
	vec3 v;
	vec3 richtLichtung;
	vec3  n     = normalize(normaleMatrix * normal);

	if (light.w == 0) {
		richtLichtung = normalize(light.xyz * -1);
	} else {
		richtLichtung = normalize(light.xyz - (model * vec4(position,  1.0)).xyz);
	}
	
	if (light.w == 0) {
		v = normalize(position - viewpoint);
	} else {
		v = normalize((model * vec4(position,  1.0)).xyz - viewpoint);
	}

	if (light.w == 0) {
		is = pow(max(0.0f, dot(n, (richtLichtung + v * -1)/length(richtLichtung + v * -1))), scheinHeiligKeit *4);
	} else {
		is = pow(max(0.0f, dot(reflect(richtLichtung, n), v)), scheinHeiligKeit );
	}
	is *= material.y;
	
	float ia = material.z * 0.1f;
	float id = material.x * dot(richtLichtung, n);

	fragmentColor[0] = max(0.0f, farbe[0] * id + is + ia);
	fragmentColor[1] = max(0.0f, farbe[1] * id + is + ia);
	fragmentColor[2] = max(0.0f, farbe[2] * id + is + ia);

	gl_Position  = mvp * vec4(position,  1.0);
}