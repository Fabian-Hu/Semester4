#version 330 core

flat in vec3 surfKd; 
smooth in vec3 eyeNormal;
smooth in vec3 eyePosition;
smooth in vec2 fragTexCoord;

uniform sampler2D imgTexture;
uniform vec4  light;
uniform float lightI;           // Light intensity 
uniform vec3  surfKa;           // Ambient reflectivity
uniform vec3  surfKs;           // Specular reflectivity
uniform float surfShininess;    // Specular shininess factor
uniform bool textured;

out vec3 fragColor;

// moved from .vert to .frag
vec3 ads (vec4 Light, float LightI, vec3 Ka, vec3 Kd, vec3 Ks, float Shininess, vec3 Position, vec3 Normal ) {
    vec3 n = normalize(Normal);
    vec3 s = Light.xyz;
    if (Light.w == 1.0) { // positional light
       s = normalize(s - Position);
    } else { // directional light
       s = normalize(s);
    }
    vec3 v = normalize(vec3(-Position));
    vec3 r = reflect( -s, n );

    return LightI * (Ka +
           Kd * max( dot(s, n), 0.0 ) +
           Ks * pow( max( dot(r,v), 0.0 ), Shininess ));
}

void main() {
	if(!textured) {
  		fragColor = ads(light,  lightI, surfKa, surfKd, surfKs, surfShininess, eyePosition, eyeNormal);
	} else {
		fragColor = ads(light,  lightI, surfKa, texture(imgTexture, fragTexCoord).xyz, surfKs, surfShininess, eyePosition, eyeNormal);
	}
}

