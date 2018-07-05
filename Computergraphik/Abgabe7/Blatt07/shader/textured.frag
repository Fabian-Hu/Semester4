#version 330 core

in vec3 eyeNormal;
in vec3 eyePosition;
in vec2 fragTexCoord;

uniform sampler2D imgTexture;

out vec4 fragColor;

void main()
{
    fragColor = texture(imgTexture, fragTexCoord);
}
