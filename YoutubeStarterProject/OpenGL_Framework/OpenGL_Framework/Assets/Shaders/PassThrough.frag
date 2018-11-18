#version 420

uniform sampler2D uTex;
uniform sampler2D uTex2;

out vec4 outColor;
in vec3 normal;
in vec2 texcoord;
void main()
{
	outColor = texture(uTex, texcoord);
}
