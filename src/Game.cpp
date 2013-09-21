#include <Game.h>

using namespace EGEMath;
using namespace EGEMotor;

Game::Game(Viewport& viewport, Input &input)
	: input(&input),
	  viewport(&viewport),
	  gameState(MENU)
{
	camera = new Camera(input, viewport, map.GetSize());
	particleEngine = new ParticleEngine();
}


Game::~Game()
{

}


// Public
void Game::Update(const double& dt)
{
	Vector windowSize = viewport->getWindowSize();
	Vector mousePos = input->getMousePosition();

	switch (gameState)
	{
	case MENU:
		if (true)
			gameState = WARMUP;
		break;
	case WARMUP:
		if((windowSize.x - mousePos.x) < 100 || mousePos.x < 100)
		{
			camera->FollowMouse(dt);
		}
		else if((windowSize.y - mousePos.y) < 100 || mousePos.y < 100)
		{
			camera->FollowMouse(dt);
		}

		if(input->isButtonPressed(Button::MouseLeft))
		{
			map.AddElement(Forest, input->getMousePositionOnMap());
			//particleEngine->addTest(Vector(input->getMousePositionOnMap()),Vector(1.0f,0));

		}
		else if(input->isButtonPressed(Button::MouseRight))
		{
			map.AddElement(Character, input->getMousePositionOnMap());
		}
		break;
	case PLAY:
		break;
	case PAUSE:
		break;
	}

	
	map.Update(dt);
	particleEngine->Update(dt);
}

void Game::Draw(EGEMotor::Viewport& viewport)
{
	switch (gameState)
	{
	case MENU:
		break;
	case PAUSE:
	case WARMUP:
	case PLAY:
		map.Draw(viewport);
		break;
	}
	particleEngine->Draw(&viewport);
		
	viewport.renderSprites();

}
