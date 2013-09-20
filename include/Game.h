#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>

class Game
{
public:
	enum GameState
	{
		MENU,
		PLAY,
		PAUSE
	};

	Game();
	~Game();

	void Update(const double& dt);
	void Draw(sf::RenderWindow& window);	
private:

};

#endif