// Basic (passthrough) vertex shader.
// We must always specify the GLSL version first.
#version 420

// 'in' inside a vertex shader means this is coming from the mesh data.
// The layout associates the variable with a stream in our mesh.
layout(location = 0) in vec3 mesh_position;
layout(location = 1) in vec3 mesh_color;

// 'uniform's are values sent from the CPU.
// They are called uniform because they cannot change between vertices.
uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProj;
uniform float u_time;

// 'out' variables will be sent forward in the pipeline to the fragment shader.
out vec3 color;

void main()
{
	// Transform as far as world-space. It is more intuitive to work there.
	vec4 world_space_pos = uModel * vec4(mesh_position, 1.0);
	
	// Calculate some offset based on the z and x positions in the world.
	// The real game-time is used to give motion and life to the effect.
	float delta = sin((world_space_pos.z + world_space_pos.x + u_time) / 8.0f);// * 2.5f;
	
	// Apply the delta to just the y coordinate.
	world_space_pos.y += delta;
	
	// Complete the transformations on our modified position.
	gl_Position = uProj * uView * world_space_pos;
	
	// Pass the color forward without changes.
	color = mesh_color;
}
