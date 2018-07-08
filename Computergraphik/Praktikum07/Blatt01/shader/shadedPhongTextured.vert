#version 330 core

in vec3 position;
in vec3 color;
in vec3 normal;
in vec2 texCoord;


uniform mat4 modelviewMatrix;    // model-view matrix
uniform mat4 projectionMatrix;   // projection matrix
uniform mat3 normalMatrix;       // normal matrix

uniform bool genTex;
uniform vec3 origin;
uniform vec3 centerAxis;

flat out vec3 surfKd;
smooth out vec3 eyePosition;
smooth out vec3 eyeNormal;
smooth out vec2 fragTexCoord;

void main()
{
	surfKd = color;
    eyePosition = (modelviewMatrix * vec4(position, 1.0)).xyz; // eye-space position
	eyeNormal   = normalize(normalMatrix * normal);      // eye-space normal
	if (genTex) {
		vec3 relPos = position - origin;

	relPos.x = clamp(relPos.x / abs(centerAxis.x), -1.0f, 1.0f);
	relPos.y = clamp(relPos.y / abs(centerAxis.y), -1.0f, 1.0f);
	relPos.z = clamp(relPos.z / abs(centerAxis.z), -1.0f, 1.0f);

		fragTexCoord.y = relPos.y;
		if (relPos.x >= 0) {
			if (relPos.z <= 0) {
				fragTexCoord.x = relPos.x * 0.25f;
			} else {
				fragTexCoord.x = 0.25f + relPos.z * 0.25f * -1.0f;
			}
		} else {
			if (relPos.z <= 0) {
				fragTexCoord.x = 0.75f + relPos.z * 0.25f;
			} else {
				fragTexCoord.x = 0.5f + relPos.x * 0.25f * -1.0f;
			}
		}
	} else {
		fragTexCoord = texCoord; // texCoords should be interpolated
	}
    gl_Position = (projectionMatrix*modelviewMatrix) * vec4(position, 1.0); // projected position
}