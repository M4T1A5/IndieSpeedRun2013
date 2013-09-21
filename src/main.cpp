#include <SFML\Graphics.hpp>

#include <Game.h>
#include <Viewport.h>
#include <Input.h>
#include <Camera.h>
#include <Windows.h>

#include <iostream>

int main()
{

	sf::RenderWindow window(sf::VideoMode(1280,720), "I dont even");

	//window.setMouseCursorVisible(false);

	//HWND hwnd = GetConsoleWindow();
	//ShowWindow(hwnd, SW_HIDE);

	//sf::Image icon;
	//if (icon.loadFromFile("Assets/icon.png"))
	//	window.setIcon(64,64,icon.getPixelsPtr());

	EGEMotor::Viewport viewport(&window);
	EGEMotor::Input input(&viewport);
	EGEMotor::Camera camera(input,viewport);
	Game game(camera, viewport, input);

	// Deltatime
	sf::Clock clock;
	double dt = 0; // Initialize just in case

	while (window.isOpen())
    {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) &&
				sf::Keyboard::isKeyPressed(sf::Keyboard::F4)))
			exit(0);

		input.keepMouseInWindow();
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch (event.type)
			{
			case sf::Event::Closed:
                window.close();
				break;
			case sf::Event::LostFocus:
				input.active = false;
				break;
			case sf::Event::GainedFocus:
				input.active = true;
				break;
			}

        }

		game.Update(dt);

		window.clear();
		game.Draw(viewport);
		input.keepMouseInWindow();
		window.display();

		dt = clock.restart().asMicroseconds() / 1000000.0;
    }
	
	return 0;
}