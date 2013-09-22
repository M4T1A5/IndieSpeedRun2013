#include <Game.h>
#include <time.h>

using namespace EGEMath;
using namespace EGEMotor;

Game::Game(Viewport& viewport, Input &input)
	: input(&input),
	  viewport(&viewport),
	  gameState(MENU),
	  _clock(0),
	  Difficulty(1)
{
	srand(time(NULL));
	camera = new Camera(input, viewport, map.GetSize());
	_townTexture.loadTexture("village.png");
	//_villageTexture.loadTexture("");
	_explorerTexture.loadTexture("arke_sheet.png");
	_villages.push_back(new Village(&_townTexture,Vector(300,800)));
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
			gameState = PLAY;
		break;
		break;
	case PLAY:
	case WARMUP:
		_clock += dt;

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
		}
		else if(input->isButtonPressed(Button::MouseRight))
		{
			map.AddElement(Swamp, input->getMousePositionOnMap());
		}

		if (_clock > 30)
		{
			_clock=0;
			gameState = PLAY;
		}

		for (int i=0; i<_villages.size(); ++i)
		{
			_villages[i]->Update(dt);
			if (_villages[i]->Clock > _villages[i]->NextVillager)
			{
				_villages[i]->Clock -= _villages[i]->NextVillager;
				_villages[i]->NextVillager = (rand()%10)/Difficulty;
				_explorers.push_back(new Explorer(&_explorerTexture,16,
					_explorerTexture.getTextureSize().x/4.0f,
					_explorerTexture.getTextureSize().y/4.0f,
					12,_villages[i]->getPosition()));
			}
		}
		
		for (int i=0; i<_explorers.size(); ++i)
		{
			_explorers[i]->Update(dt, map._mapElements[Volcano][0]->getPosition());
		}


		break;
	case PAUSE:
		break;
	}

	map.Update(dt);
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
		for (int i=0;i<_villages.size();++i)
			_villages[i]->Draw(viewport);
		for (int i=0;i<_explorers.size();++i)
			_explorers[i]->Draw(viewport);
		viewport.renderSprites();
		break;
	}


}
