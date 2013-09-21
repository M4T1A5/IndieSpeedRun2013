#ifndef GAME_H
#define GAME_H

#include <Viewport.h>
#include <Map.h>
#include <Input.h>
#include <Camera.h>
#include <Village.h>
#include <Explorer.h>

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
	EGEMotor::Input* input;
	EGEMotor::Camera* camera;
	EGEMotor::Viewport* viewport;
	GameState gameState;

	EGEMotor::Texture _townTexture;
	EGEMotor::Texture _villageTexture;
	EGEMotor::Texture _explorerTexture;
	std::vector<Village*> _villages;
	std::vector<Explorer*> _explorers;
	
	float Difficulty;
	float _clock;

};

#endif