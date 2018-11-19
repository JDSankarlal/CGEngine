#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	delete updateTimer;


	PassThrough.UnLoad();
	gameMesh.Unload();
	grassTexture.Unload();
	rockTexture.Unload();
	heightMap.Unload();
	sandTexture.Unload();
	waterTexture.Unload();
	waterShader.UnLoad();
	waterMesh.Unload();
	//...
}

void Game::initializeGame()
{
	updateTimer = new Timer();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	if (!PassThrough.Load("./Assets/Shaders/Terrain.vert", "./Assets/Shaders/Terrain.frag"))
	{
		std::cout << "Shaders failed to initialize. \n" << std::endl;
		system("pause");
		exit(0);
	}

	if (!waterShader.Load("./Assets/Shaders/Water.vert", "./Assets/Shaders/Water.frag"))
	{
		std::cout << "Shaders failed to initialize. \n" << std::endl;
		system("pause");
		exit(0);
	}


	if (!gameMesh.LoadFromFile("./Assets/Models/Plane.obj"))
	{
		std::cout << "Model failed to load" << std::endl;
		system("pause");
		exit(0);
	}

	if (!waterMesh.LoadFromFile("./Assets/Models/Plane.obj"))
	{
		std::cout << "Model failed to load" << std::endl;
		system("pause");
		exit(0);
	}

	if (!grassTexture.Load("./Assets/Textures/grass.jpg"))
	{
		system("pause");
		exit(0);
	}

	if (!heightMap.Load("./Assets/Textures/_heightmap.jpg"))
	{
		system("pause");
		exit(0);
	}

	if (!waterTexture.Load("./Assets/Textures/water.png"))
	{
		system("pause");
		exit(0);
	}

	if (!sandTexture.Load("./Assets/Textures/sand.jpg"))
	{
		system("pause");
		exit(0);
	}

	if (!rockTexture.Load("./Assets/Textures/rock.jpg"))
	{
		system("pause");
		exit(0);
	}

	CameraTransform.RotateX(-45.0f);
	CameraTransform.RotateY(45.0f);
	//CameraTransform.RotateZ(45.0f);
	CameraTransform.Translate(vec3(1.0f,2.0f,1.0f));
	CameraProjection = mat4::PerspectiveProjection(60.0f,(float)WINDOW_WIDTH/(float)WINDOW_HEIGHT,1.0f, 10000.0f);
	waterTransform.Translate(vec3(0.0f, 0.345f, 0.0f));

	//...
}

void Game::update()
{
	// update our clock so we have the delta time since the last update
	updateTimer->tick();

	float deltaTime = updateTimer->getElapsedTimeSeconds();
	TotalGameTime += deltaTime;
	//planeTransform.RotateY(deltaTime*45.0f/2.0f);
	//...
	postProcessing();
}

void Game::draw(Mesh* meshToDraw)
{
	glBindVertexArray(meshToDraw->VAO);
	glDrawArrays(GL_TRIANGLES, 0, meshToDraw->GetNumVertices());
	glBindVertexArray(0);

}

void Game::postProcessing()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	PassThrough.Bind();
	PassThrough.SendUniformMat4("uModel", planeTransform.data, true);
	PassThrough.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	PassThrough.SendUniformMat4("uProj", CameraProjection.data, true);
	PassThrough.SendUniform("u_time", TotalGameTime);

	glActiveTexture(GL_TEXTURE0);
	heightMap.Bind();

	glActiveTexture(GL_TEXTURE1);
	grassTexture.Bind();

	glActiveTexture(GL_TEXTURE2);
	rockTexture.Bind();
	
	glActiveTexture(GL_TEXTURE4);
	sandTexture.Bind();

	draw(&gameMesh);
	heightMap.UnBind();
	grassTexture.UnBind();
	rockTexture.UnBind();
	waterTexture.UnBind();
	sandTexture.UnBind();
	PassThrough.UnBind();


	waterShader.Bind();
	waterShader.SendUniformMat4("uModel", waterTransform.data, true);
	waterShader.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	waterShader.SendUniformMat4("uProj", CameraProjection.data, true);
	waterShader.SendUniform("u_time", TotalGameTime);
	
	glActiveTexture(GL_TEXTURE5);
	waterTexture.Bind();
	
	draw(&waterMesh);
	waterShader.UnBind();
	waterTexture.UnBind();
	//water.unbind();

	glutSwapBuffers();

}

void Game::keyboardDown(unsigned char key, int mouseX, int mouseY)
{
	switch(key)
	{
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;
	}
}

void Game::keyboardUp(unsigned char key, int mouseX, int mouseY)
{
	switch(key)
	{
	case 32: // the space bar
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;
	}
}

void Game::mouseClicked(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN) 
	{
		switch(button)
		{
		case GLUT_LEFT_BUTTON:

			break;
		case GLUT_RIGHT_BUTTON:
		
			break;
		case GLUT_MIDDLE_BUTTON:

			break;
		}
	}
	else
	{

	}
}

/*
 * mouseMoved(x,y)
 * - this occurs only when the mouse is pressed down
 *   and the mouse has moved.  you are given the x,y locations
 *   in window coordinates (from the top left corner) and thus 
 *   must be converted to screen coordinates using the screen to window pixels ratio
 *   and the y must be flipped to make the bottom left corner the origin.
 */
void Game::mouseMoved(int x, int y)
{
}
