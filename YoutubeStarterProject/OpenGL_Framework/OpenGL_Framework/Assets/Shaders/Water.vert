#version 420
#define M_PI 3.14159

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProj;
uniform float u_time;

in vec3 in_vert;
in vec2 in_uv;
in vec3 in_normal;

out vec2 texcoord;
out vec3 norm;
out vec3 pos;

void main()
{
	texcoord = in_uv;
	texcoord.y=1-texcoord.y;
	norm = mat3(uView) * mat3(uModel) * in_normal;
	vec3 vt = in_vert;

	vt.y = sin(vt.z*vt.x*20) * cos(u_time)*.5*(M_PI/50);
	pos = (uView*uModel*vec4(vt,1.0)).xyz;
	gl_Position = uProj * vec4(pos,1.0);	




}