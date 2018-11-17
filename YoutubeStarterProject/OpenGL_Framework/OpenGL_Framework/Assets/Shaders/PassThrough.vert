#version 420

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProj;

in vec3 in_vert;
in vec3 in_uv;
in vec3 in_normal;

void main()
{
	gl_Position = uProj * uView * uModel * vec4(in_vert,1.0);
}