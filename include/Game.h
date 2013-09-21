#ifndef GAME_H
#define GAME_H

#include <Viewport.h>
#include <Map.h>
#include <Input.h>

class Game
{
public:
	enum GameState
	{
		MENU,
		PLAY,
		PAUSE
	};
	Game(EGEMath::Input &input);
	~Game();

	void Update(const double& dt);
	void Draw(EGEMath::Viewport& viewport);	
private:
	Map map;
	EGEMath::Input* input;
};

#endif