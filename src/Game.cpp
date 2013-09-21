#include <Game.h>

using namespace EGEMath;
using namespace EGEMotor;

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

	if(input->isButtonPressed(Button::MouseLeft))
	{
		map.AddElement(map.Forest, input->getMousePositionOnMap());
	}
	else if(input->isButtonPressed(Button::MouseRight))
	{
		map.AddElement(map.Character, input->getMousePositionOnMap());
	}

	map.Update(dt);
}

void Game::Draw(EGEMotor::Viewport& viewport)
{
	map.Draw(viewport);
	viewport.renderSprites();
}
