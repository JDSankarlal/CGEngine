#version 420

layout (binding = 1)uniform sampler2D grassTex;
layout (binding = 2)uniform sampler2D rockTex;
layout (binding = 4)uniform sampler2D sandTex;

vec4 texel0,texel1,texel2,texel3;


out vec4 outColor;
in vec3 out_vert;
in vec3 normal;
in vec2 texcoord;

void main()
{

	texel0 = texture(sandTex, texcoord);
	texel1 = texture(grassTex, texcoord);
	texel2 = texture(rockTex, texcoord);

	if (out_vert.y <= .345)
	{
		outColor=texel0;
	}
	
	else if (out_vert.y <= .32)
	{
		outColor=mix(texel0,texel1,1);
	}

	else if (out_vert.y >= .35 && out_vert.y <=.45)
	{
		outColor=texel1;
	}

	else if (out_vert.y >= .50)
	{
		outColor=texel2;
	}

	else
	{
		outColor = texel1;
	}

}
