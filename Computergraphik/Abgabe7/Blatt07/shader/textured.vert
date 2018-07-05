#version 330 core
in vec3 position;
in vec3 normal;
in vec2 texCoord;

uniform mat4 mvp;
uniform mat4 modelviewMatrix;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;

out vec3 eyeNormal;
out vec3 eyePosition;
out vec2 fragTexCoord;

void main()
{
    gl_Position  = (projectionMatrix*modelviewMatrix) * vec4(position,  1.0);
    eyePosition  = (modelviewMatrix * vec4(position,  1.0)).xyz;
    eyeNormal    = normalMatrix * normal;
    fragTexCoord = texCoord; // texCoords should be interpolated
}
