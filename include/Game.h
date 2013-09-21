#ifndef GAME_H
#define GAME_H

#include <Viewport.h>
#include <Map.h>
#include <Input.h>
#include <Camera.h>
#include <ParticleEngine.h>

class Game
{
public:
	enum GameState
	{
		MENU,
		WARMUP,
		PLAY,
		PAUSE
	};
	Game(EGEMotor::Viewport& viewport, EGEMotor::Input &input);
	~Game();

	void Update(const double& dt);
	void Draw(EGEMotor::Viewport& viewport);	
private:
	Map map;
	EGEMotor::ParticleEngine* particleEngine;
	EGEMotor::Input* input;
	EGEMotor::Camera* camera;
	EGEMotor::Viewport* viewport;
	GameState gameState;
};

#endif