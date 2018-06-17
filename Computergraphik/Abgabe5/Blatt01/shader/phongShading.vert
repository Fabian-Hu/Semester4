#version 330 core

in vec3 position;
in vec3 normal;

uniform mat4 mvp;
uniform vec3 farbe;
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