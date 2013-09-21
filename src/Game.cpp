#include <Game.h>

using namespace EGEMath;

Game::Game(Camera& camera, Viewport& viewport, Input &input)
	: input(&input),
	  camera(&camera),
	  viewport(&viewport)
{

}


Game::~Game()
{

}


// Public
void Game::Update(const double& dt)
{
	Vector windowSize = viewport->getWindowSize();
	Vector mousePos = input->getMousePosition();

	if((windowSize.x - mousePos.x) < 100 || mousePos.x < 100)
	{
		camera->FollowMouse(dt);
	}
	else if((windowSize.y - mousePos.y) < 100 || mousePos.y < 100)
	{
		camera->FollowMouse(dt);
	}
}

void Game::Draw(EGEMath::Viewport& viewport)
{
	map.Draw(viewport);
	viewport.renderSprites();
}
