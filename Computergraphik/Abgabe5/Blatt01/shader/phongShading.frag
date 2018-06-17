#version 330 core

flat in vec3 fragmentColor;
smooth in vec3 fragmentPosition;
smooth in vec3 fragmentNormal;

uniform mat4 mvp; 
uniform mat4 model;
uniform mat3 normaleMatrix;
uniform vec4 light;
uniform vec3 viewpoint;
uniform vec3 material;
uniform int scheinHeiligKeit;

out vec3 fragColor;

void main()
{
	float is = 0;
	vec3 v;
	vec3 richtLichtung;
	vec3  n     = normalize(normaleMatrix * fragmentNormal);

	if (light.w == 0) {
		richtLichtung = normalize(light.xyz * -1);
	} else {
		richtLichtung = normalize(light.xyz - (model * vec4(fragmentPosition,  1.0)).xyz);
	}
	
	if (light.w == 0) {
		v = normalize(fragmentPosition - viewpoint);
	} else {
		v = normalize((model * vec4(fragmentPosition,  1.0)).xyz - viewpoint);
	}

	if (light.w == 0) {
		is = pow(max(0.0f, dot(n, (richtLichtung + v * -1)/length(richtLichtung + v * -1))), scheinHeiligKeit *4);
	} else {
		is = pow(max(0.0f, dot(reflect(richtLichtung, n), v)), scheinHeiligKeit );
	}
	is *= material.y;
	
	float ia = material.z * 0.1f;
	float id = material.x * dot(richtLichtung, n);

	fragColor[0] = max(0.0f, fragmentColor[0] * id + is + ia);
	fragColor[1] = max(0.0f, fragmentColor[1] * id + is + ia);
	fragColor[2] = max(0.0f, fragmentColor[2] * id + is + ia);
}