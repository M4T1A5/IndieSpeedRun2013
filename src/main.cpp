#include <SFML\Graphics.hpp>

#include <Game.h>
#include <Viewport.h>
#include <Input.h>
#include <Camera.h>

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280,720), "I dont even");
	EGEMotor::Viewport viewport(&window);
	EGEMotor::Input input(&viewport);
	EGEMotor::Camera camera(input,viewport);
	Game game(camera, viewport, input);

	// Deltatime
	sf::Clock clock;
	double dt = 0; // Initialize just in case

	while (window.isOpen())
    {
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
			case sf::Event::MouseLeft:
				if (input.active)
					input.keepMouseInWindow();
				break;
			}

        }
		game.Update(dt);
		
		std::cout<<"\n"<<input.getMousePosition()<<input.getMousePositionOnMap();


		window.clear();
		game.Draw(viewport);
        window.display();
		dt = clock.restart().asMicroseconds() / 1000000.0;
    }
	
	return 0;
}