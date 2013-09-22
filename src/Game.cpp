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
	font = new Font("square.ttf");
	resourceText = new Text("", font);
	resourceText->setPosition(Vector(viewport.getWindowSize().x - 75, 0));
	resourceText->setOriginPoint(9);
	resourceText->setLayer(295);
	resources = 6;

	health = 5;
	healthText = new Text("", font);
	healthText->setPosition(Vector(viewport.getWindowSize().x - 75, 30));
	healthText->setOriginPoint(9);
	healthText->setLayer(295);

	activeButton[FOREST]=false;
	activeButton[SWAMP]=false;
	activeButton[HURRICANE]=false;
	activeButton[BUG]=false;
	activeButton[CAT]=false;
	activeButton[RIVER]=false;

	srand(time(NULL));
	camera = new Camera(input, viewport, map.GetSize());
	_townTexture.loadTexture("village.png");
	_villageTexture.loadTexture("settlement.png");
	_explorerTexture.loadTexture("arke_sheet.png");
	_villages.push_back(new Village(&_townTexture,Vector(300,800)));

	// Menu
	menuTexture = new Texture("menu.png");
	menu.setTexture(menuTexture);
	startTexture = new Texture("startbutton.png");
	startButton = new GUIButton(startTexture, viewport.getWindowSize() / 2, 
		Rectangle(Vector(), startTexture->getTextureSize()), &input);
	startButton->setOriginPoint(5);

	tutorialNumber = 0;
	for(int i = 0; i < 5; ++i)
	{
		char merkkijono[20];
		sprintf(merkkijono, "tutorial-%d.png", i+1);
		tutorialTexture.push_back(new Texture(merkkijono));

		tutorial.push_back(new GameObject(tutorialTexture[i]));
		tutorial[i]->setPosition(Vector(-1000,-1000));
		tutorial[i]->setOriginPoint(5);
	}


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

	tutorialTexture.empty();
	tutorial.empty();
	buttons.empty();
}


// Public
void Game::Update(const double& dt)
{
	Vector windowSize = viewport->getWindowSize();
	Vector mousePos = input->getMousePosition();

	if(input->isButtonPressed(MouseRight))
		health = 0;

	switch (gameState)
	{
	case MENU:
		if (tutorialNumber == 0 && startButton->isPressed() )
		{
			tutorial[tutorialNumber]->setPosition(startButton->getPosition());
			tutorialNumber++;
		}
		if(tutorialNumber > 0 && tutorialNumber < tutorial.size())
		{
			if(input->isButtonPressed(MouseLeft))
			{
				tutorial[tutorialNumber]->setPosition(startButton->getPosition());
				tutorialNumber++;
			}
		}
		if(tutorialNumber == tutorial.size())
		{
			if(input->isButtonPressed(MouseLeft))
			{
				for(int i = 0; i < tutorial.size(); ++i)
				tutorial[i]->setPosition(Vector(-1000,-1000));

				gameState = WARMUP;
			}			
		}
		break;
	case WARMUP:
		char merkkijono[20];
		sprintf(merkkijono, "Resources: %d", resources);
		resourceText->setString(merkkijono);
		resourceText->updateOrigin();
		sprintf(merkkijono, "Health: %d", health);
		healthText->setString(merkkijono);
		healthText->updateOrigin();

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

		if(spawnElement > 0 && input->isButtonPressed(Button::MouseLeft) && resources > 0)
		{
			map.AddElement(spawnElement, input->getMousePositionOnMap());
			resources--;

		}	

		if (_clock > 10)
		{
			_clock=0;
			gameState = PLAY;
		}
		break;
	case PLAY:
		sprintf(merkkijono, "Health: %d", health);
		healthText->setString(merkkijono);
		healthText->updateOrigin();
		if((windowSize.x - mousePos.x) < 5 || mousePos.x < 5)
		{
			camera->FollowMouse(dt);
		}
		else if((windowSize.y - mousePos.y) < 5 || mousePos.y < 5)
		{
			camera->FollowMouse(dt);
		}

		for(int i = 2; i < 5; ++i)
		{
			if(buttons[i]->isPressed())
			{
				spawnHazard = buttons[i]->hazardToSpawn;
				spawnElement = Background;
			}
		}

		if(spawnHazard >= 0 && input->isButtonPressed(Button::MouseLeft) )
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

		for (int i=0; i<_villages.size(); ++i)
		{
			_villages[i]->Update(dt);
			if (_villages[i]->Clock > _villages[i]->NextVillager)
			{
				_villages[i]->Clock -= _villages[i]->NextVillager;
				_villages[i]->NextVillager = (rand()%5)/Difficulty;
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
				for (int k=0; k<map._mapElements[j].size();++k)
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
						_explorers[i]->getPosition();
						map._mapElements[j][k]->getPosition();

						if ((_explorers[i]->getPosition()-map._mapElements[j][k]->getPosition())
							.getLenght()< map._mapElementList[j]->Radius)
						{
							_explorers[i]->slowed=true;
							if (activeButton[FOREST])
							{
								if(rand()%10000 > 9999-10000*dt);
							}
						}
						break;
					case Swamp:
						if ((_explorers[i]->getPosition()-map._mapElements[j][k]->getPosition())
							.getLenght()< map._mapElementList[j]->Radius)
						{
							_explorers[i]->slowed=true;
							_explorers[i]->poison=true;

							if (activeButton[SWAMP])
							{
							}
						}
						break;
					case Volcano:
						if(map._mapElements[j][k]->
							getGlobalBounds().contains(_explorers[i]->getPosition()))
						{
							health--;
							_explorers.erase(_explorers.begin() + i);
						}
						break;
					}
				}
			}
			
			for (int j=0; j<particleEngine->m_TornadoParticles.size();++j)
			{
				if ((_explorers[i]->getPosition()-particleEngine->m_TornadoParticles[j]->m_position).getLenght() < particleEngine->m_TornadoParticles[j]->AreaOfEffect)
				{
					_explorers[i]->setPosition(particleEngine->m_TornadoParticles[j]->m_position);
				}
			}
			for (int j=0; j<particleEngine->m_BugParticles.size();++j)
			{
				if ((_explorers[i]->getPosition()-particleEngine->m_TornadoParticles[j]->m_position).getLenght() < particleEngine->m_TornadoParticles[j]->AreaOfEffect)
				{
					_explorers[i]->poison = true;
				}
			}
			for (int j=0; j<particleEngine->m_CatParticles.size();++j)
			{
				if ((_explorers[i]->getPosition()-particleEngine->m_TornadoParticles[j]->m_position).getLenght() < particleEngine->m_TornadoParticles[j]->AreaOfEffect)
				{
					_explorers[i]->dead = true;
				}
			}

			if (_explorers[i]->dead)
				_explorers.erase(_explorers.begin() + i);
		}

		if(health == 0)
			reset();
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

		for(int i = 0; i < tutorial.size(); ++i)
			tutorial[i]->Draw(viewport);

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
		viewport.draw(resourceText);
		viewport.draw(healthText);
		viewport.renderSprites();
		break;
	}
	particleEngine->Draw(&viewport);
		
	viewport.renderSprites();

}

void Game::reset()
{
	health = 5;
	resources = 6;
	gameState = MENU;
	_villages.empty();
	_explorers.empty();
	map.Reset();
}