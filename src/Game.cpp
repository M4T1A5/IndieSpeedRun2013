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

	// Menu
	menuTexture = new Texture("menu.png");
	menu.setTexture(menuTexture);
	startTexture = new Texture("startbutton.png");
	startButton = new GUIButton(startTexture, viewport.getWindowSize() / 2, 
		Rectangle(Vector(), startTexture->getTextureSize()), &input);
	startButton->setOriginPoint(5);


	// Sidebar
	sidebarTexture = new Texture("sidebar2.png");
	sidebar.setTexture(sidebarTexture);
	Vector sidebarPos = Vector(viewport.getWindowSize().x - sidebarTexture->getTextureSize().x, 0);
	sidebar.setPosition(sidebarPos);
	sidebar.setLayer(295);

	// Buttons
	buttonTexture = new Texture("buttons2.png");
	for(int i = 0; i < 6; ++i)
	{
		Vector buttonPos = sidebarPos + Vector(0, i*120);
		Rectangle crop = Rectangle(Vector(i*75, 0), Vector(150,150));
		auto button = new GUIButton(buttonTexture, buttonPos, crop, &input);
		button->setLayer(296);
		buttons.push_back(button);
	}
	particleEngine = new ParticleEngine();
}


Game::~Game()
{
	delete startTexture;
	delete startButton;
	delete menuTexture;
	delete sidebarTexture;
	delete buttonTexture;

	buttons.empty();
}


// Public
void Game::Update(const double& dt)
{
	Vector windowSize = viewport->getWindowSize();
	Vector mousePos = input->getMousePosition();

	switch (gameState)
	{
	case MENU:
		if (startButton->isPressed())
			gameState = PLAY;
		break;
		break;
	case PLAY:
	case WARMUP:
		_clock += dt;
		
		if((windowSize.x - mousePos.x) < 5 || mousePos.x < 5)

		{
			camera->FollowMouse(dt);
		}
		else if((windowSize.y - mousePos.y) < 5 || mousePos.y < 5)
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

	
	for(size_t i = 0; i < buttons.size(); ++i)
	{
		if(buttons[i]->mouseOver())
			buttons[i]->setColor(255,255,255,255);
		else
			buttons[i]->setColor(255,255,255,150);
	}
	map.Update(dt);
	particleEngine->Update(dt);
}

void Game::Draw(EGEMotor::Viewport& viewport)
{
	switch (gameState)
	{
	case MENU:
		menu.Draw(viewport);
		startButton->draw(viewport);
		viewport.renderSprites();
		break;
	case PAUSE:
	case WARMUP:
	case PLAY:
		map.Draw(viewport);
		for (int i=0;i<_villages.size();++i)
			_villages[i]->Draw(viewport);
		for (int i=0;i<_explorers.size();++i)
			_explorers[i]->Draw(viewport);
		
		for(size_t i = 0; i < buttons.size(); ++i)
		{
			buttons[i]->draw(viewport);
		}
		sidebar.Draw(viewport);
		viewport.renderSprites();
		break;
	}
	particleEngine->Draw(&viewport);
		
	viewport.renderSprites();

}