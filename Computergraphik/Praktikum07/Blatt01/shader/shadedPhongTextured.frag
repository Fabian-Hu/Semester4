#version 330 core
#define M_PI 3.1415926535897932384626433832795

flat in vec3 surfKd; 
smooth in vec3 eyeNormal;
smooth in vec3 eyePosition;
smooth in vec3 fragPosition;
smooth in vec2 fragTexCoord;

uniform sampler2D imgTexture;
uniform vec4  light;
uniform float lightI;           // Light intensity 
uniform vec3  surfKa;           // Ambient reflectivity
uniform vec3  surfKs;           // Specular reflectivity
uniform float surfShininess;    // Specular shininess factor
uniform bool textured;

uniform bool genTex;
uniform vec3 origin;
uniform vec3 centerAxis;

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
		if (genTex) {
			vec3 relPos = fragPosition - origin;
			vec2 texCoord;
			vec2 circle = normalize(vec2(relPos.x, relPos.z));

			relPos.y = clamp(abs(relPos.y) / abs(centerAxis.y), 0.0f, 1.0f);

			float angle1 = acos(dot(circle, vec2(1.0f, 0.0f)) / (length(circle) * length(vec2(1.0f, 0.0f))));
			float angle2 = acos(dot(circle, vec2(0.0f, 1.0f)) / (length(circle) * length(vec2(0.0f, 1.0f))));

			texCoord.y = relPos.y;

			if ((angle1 <= M_PI * 0.5f && angle2 > M_PI * 0.5f) || (angle1 > M_PI * 0.5f && angle2 > M_PI * 0.5f)) {
				texCoord.x = angle1 / (M_PI * 2.0f);
			} else {
				texCoord.x = (M_PI * 2.0f - angle1) / (M_PI * 2.0f);
			}
			fragColor = ads(light,  lightI, surfKa, texture(imgTexture, texCoord).xyz, surfKs, surfShininess, eyePosition, eyeNormal);
		} else {
			fragColor = ads(light,  lightI, surfKa, texture(imgTexture, fragTexCoord).xyz, surfKs, surfShininess, eyePosition, eyeNormal);
		}
	}
}

