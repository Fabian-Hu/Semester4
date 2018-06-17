#version 330 core

in vec3 position;
uniform vec3 farbe;

uniform mat4 mvp;

out vec3 fragmentColor;

void main()
{
	fragmentColor = farbe;
	gl_Position   = mvp * vec4(position,  1.0);
}