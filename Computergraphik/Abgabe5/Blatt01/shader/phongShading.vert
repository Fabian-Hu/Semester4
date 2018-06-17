#version 330 core

in vec3 position;
in vec3 normal;

uniform vec3 farbe;
uniform mat4 mvp;  // model-view-projection
uniform mat3 nm;   // normal matrix

smooth out vec3 fragmentNormal;
smooth out vec3 fragmentPosition;
flat out vec3 fragmentColor;

void main()
{
	fragmentNormal = normal;
	fragmentColor = farbe;
	fragmentPosition = position;
	gl_Position  = mvp * vec4(position,  1.0);
}