#version 330 core

in vec3 position;
in vec3 color;
in vec3 normal;
in vec2 texCoord;

uniform mat4 modelviewMatrix;    // model-view matrix
uniform mat4 projectionMatrix;   // projection matrix
uniform mat3 normalMatrix;       // normal matrix

flat out vec3 surfKd;
smooth out vec3 fragPosition;
smooth out vec3 eyePosition;
smooth out vec3 eyeNormal;
smooth out vec2 fragTexCoord;

void main()
{
	surfKd = color;
    eyePosition = (modelviewMatrix * vec4(position, 1.0)).xyz; // eye-space position
	eyeNormal   = normalize(normalMatrix * normal);      // eye-space normal
	fragPosition = position;
	fragTexCoord = texCoord; // texCoords should be interpolated
    gl_Position = (projectionMatrix*modelviewMatrix) * vec4(position, 1.0); // projected position
}