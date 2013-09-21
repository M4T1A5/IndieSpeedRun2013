#include <Game.h>

using namespace EGEMath;

Game::Game(Input &input)
	: input(&input)
{

}


Game::~Game()
{

}


// Public
void Game::Update(const double& dt)
{

}

void Game::Draw(EGEMath::Viewport& viewport)
{
	map.Draw(viewport);
	viewport.renderSprites();
}
