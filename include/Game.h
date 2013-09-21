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
	Game(EGEMotor::Camera& camera, EGEMotor::Viewport& viewport, EGEMotor::Input &input);
	~Game();

	void Update(const double& dt);
	void Draw(EGEMotor::Viewport& viewport);	
private:
	Map map;
	EGEMotor::Input* input;
	EGEMotor::Camera* camera;
	EGEMotor::Viewport* viewport;
};

#endif