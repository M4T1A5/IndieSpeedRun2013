#ifndef GAME_H
#define GAME_H

#include <Viewport.h>

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
	void Draw(EGEMath::Viewport& viewport);	
private:

};

#endif