#pragma once
#include <windows.h>
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Texture.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Timer.h"

#define WINDOW_WIDTH			800
#define WINDOW_HEIGHT			600
#define FRAMES_PER_SECOND		60
class Game
{
public:
	Game();
	~Game();

	void initializeGame();
	void update();
	void draw(Mesh* meshToDraw);
	void postProcessing();
	/* input callback functions */
	void keyboardDown(unsigned char key, int mouseX, int mouseY);
	void keyboardUp(unsigned char key, int mouseX, int mouseY);
	void mouseClicked(int button, int state, int x, int y);
	void mouseMoved(int x, int y);

	/* Data Members */
	Timer *updateTimer	= nullptr;
	float TotalGameTime = 0.0f;
	Mesh gameMesh;
	Mesh waterMesh;
	ShaderProgram PassThrough;
	ShaderProgram waterShader;
	Texture grassTexture;
	Texture sandTexture;
	Texture rockTexture;
	Texture waterTexture;
	Texture heightMap;
	mat4 CameraTransform;
	mat4 CameraProjection;
	mat4 planeTransform;
	mat4 waterTransform;


private:

};
