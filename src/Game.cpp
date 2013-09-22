#include <Game.h>

using namespace EGEMath;
using namespace EGEMotor;

Game::Game(Viewport& viewport, Input &input)
	: input(&input),
	  viewport(&viewport),
	  gameState(MENU)
{
	camera = new Camera(input, viewport, map.GetSize());

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
			gameState = WARMUP;
		break;
	case WARMUP:
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
			map.AddElement(Character, input->getMousePositionOnMap());
		}
		break;
	case PLAY:
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