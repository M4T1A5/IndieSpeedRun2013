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
	activeButton[FOREST]=false;
	activeButton[SWAMP]=false;
	activeButton[HURRICANE]=false;
	activeButton[BUG]=false;
	activeButton[CAT]=false;
	activeButton[RIVER]=false;

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

	buttons[0]->elementToSpawn = Forest;
	buttons[1]->elementToSpawn = Swamp;
	buttons[2]->hazardToSpawn = tornado;
	buttons[3]->hazardToSpawn = cat;
	buttons[4]->hazardToSpawn = bug;
	buttons[5];

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

		for(int i = 0; i < 2; ++i)
		{
			if(buttons[i]->isPressed())
				spawnElement = buttons[i]->elementToSpawn;
		}

		for(int i = 2; i < 5; ++i)
		{
			if(buttons[i]->isPressed())
				spawnHazard = buttons[i]->hazardToSpawn;
		}

		if(spawnElement > 0 && input->isButtonPressed(Button::MouseLeft))
		{
			map.AddElement(spawnElement, input->getMousePositionOnMap());

		}

		else if(spawnHazard >= 0 && input->isButtonPressed(Button::MouseLeft) )
		{
			switch(spawnHazard)
			{
			case tornado:
				particleEngine->addTornado(input->getMousePositionOnMap(), Vector(1,1));
				break;
			case cat:
				particleEngine->addCat(input->getMousePositionOnMap(), Vector(100,1));
				break;
			case bug:
				particleEngine->addBug(input->getMousePositionOnMap(), Vector(100,1));
				break;
			}

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


			for (int j=0; j<map._mapElements.size();++j)
			{
				for (int k=0; k<map._mapElements.size();++k)
				{
					switch(j)
					{
					case Background:
						break;
					case River:
						if (map.GetPixel(_explorers[i]->getPosition()) != sf::Color::Transparent)
						{
							_explorers[i]->slowed=true;
							if (activeButton[RIVER])
							{
								_explorers[i]->poison=true;
							}
						}
						break;
					case Forest:
						if ((_explorers[i]->getPosition()-map._mapElements[j][k]->getPosition())
							.getLenght()< map._mapElementList[j]->Radius)
							_explorers[i]->slowed=true;
						{
							if (activeButton[FOREST])
							{
								if(rand()%10000 > 9999-10000*dt);
							}
						}
						break;
					case Swamp:
						if ((_explorers[i]->getPosition()-map._mapElements[j][k]->getPosition())
							.getLenght()< map._mapElementList[j]->Radius)
							_explorers[i]->slowed=true;
						if (activeButton[SWAMP])
						{

						}
						break;
					case Volcano:
						break;
					}
				}
			}


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