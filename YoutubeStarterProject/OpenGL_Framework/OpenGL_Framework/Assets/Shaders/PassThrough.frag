#version 420

layout (binding = 1)uniform sampler2D uTex;

out vec4 outColor;
in vec3 normal;
in vec2 texcoord;
void main()
{
	outColor = texture(uTex, texcoord);
}
