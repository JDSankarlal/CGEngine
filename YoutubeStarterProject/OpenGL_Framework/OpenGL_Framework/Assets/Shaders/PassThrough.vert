#version 420

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProj;

in vec3 in_vert;
in vec2 in_uv;
in vec3 in_normal;

out vec3 normal;
out vec2 texcoord;
void main()
{
	texcoord = in_uv;
	normal = in_normal;
	gl_Position = uProj * uView * uModel * vec4(in_vert,1.0);
}