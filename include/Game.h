#ifndef GAME_H
#define GAME_H

#include <Viewport.h>
#include <Map.h>
#include <Input.h>
#include <Camera.h>

class Game
{
public:
	enum GameState
	{
		MENU,
		PLAY,
		PAUSE
	};
	Game(EGEMath::Camera& camera, EGEMath::Viewport& viewport, EGEMath::Input &input);
	~Game();

	void Update(const double& dt);
	void Draw(EGEMath::Viewport& viewport);	
private:
	Map map;
	EGEMath::Input* input;
	EGEMath::Camera* camera;
	EGEMath::Viewport* viewport;
};

#endif