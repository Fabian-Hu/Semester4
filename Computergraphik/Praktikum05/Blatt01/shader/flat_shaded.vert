#version 330 core

in vec3 position;
in vec3 color;
in vec3 normal;

uniform mat4 mvp;  // model-view-projection
uniform mat3 nm;   // normal matrix
uniform vec3 lightDirection;
uniform vec3 pointLight;
uniform int light;

//out vec3 fragmentColor;
//flat          out vec3 fragmentColor;
//noperspective out vec3 fragmentColor;
smooth        out vec3 fragmentColor;

void main()
{
	vec3  n     = normalize(nm * normal);
	vec3 lightDir;
	float fDiff = 0.0f;
	if (light == 0) {
		lightDir = -1 * lightDirection;
	} else {
		lightDir = normalize(pointLight - position);
	}
	fDiff = max(0.1f, dot(n, lightDir));
	
	//Betrachtungsrichtung
	vec3 v = vec3 (0.0f, 0.0f, 1.0f);
	//h, da Richtungslicht nahe unendlich
	vec3 r = lightDir - 2 * dot(n, lightDir) * n;
	vec3 h = (lightDir + v)/length(lightDir + v);

	float id = dot(n, lightDir);
	float is = 0;
	//if (light == 0) {
		//Licht ist unendlich weit weg
		is = pow(max(0.0f, dot(n, h)), 50);
	/*} else {
		is = pow(max(0.0f, dot(r, v)), 50);
	}*/
	float ia = 0.01f;

	//Lichtquelle und Umgebungslicht ist weiﬂ
	fragmentColor[0] = max(0.0f, color[0] * id + is + ia);
	fragmentColor[1] = max(0.0f, color[1] * id + is + ia);
	fragmentColor[2] = max(0.0f, color[2] * id + is + ia);

//    fragmentColor = color * fDiff;
	gl_Position  = mvp * vec4(position,  1.0);
}