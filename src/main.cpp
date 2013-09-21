#include <SFML\Graphics.hpp>

#include <Game.h>
#include <Viewport.h>
#include <Input.h>
#include <Camera.h>

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280,720), "I dont even");
	EGEMath::Viewport viewport(&window);
	EGEMath::Input input(&viewport);
	EGEMath::Camera camera(input,viewport);
	Game game(input);

	// Deltatime
	sf::Clock clock;
	double dt = 0; // Initialize just in case

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		game.Update(dt);
		
		std::cout<<"\n"<<input.getMousePosition()<<input.getMousePositionOnMap();

		if (input.isButtonDown(EGEMath::MouseLeft))
		{
			camera.FollowMouse();
		}

        window.clear();
		game.Draw(viewport);
        window.display();
		dt = clock.restart().asMicroseconds() / 1000000.0;
    }
	
	return 0;
}