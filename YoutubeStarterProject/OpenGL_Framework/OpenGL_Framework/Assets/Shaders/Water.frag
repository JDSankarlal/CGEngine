#version 420

layout (binding = 5)uniform sampler2D waterTex;

vec4 wTex;


out vec4 outColor;
in vec3 out_vert;
in vec3 normal;
in vec2 texcoord;

void main()
{
    wTex = texture(waterTex,texcoord);

    outColor=wTex;

}
