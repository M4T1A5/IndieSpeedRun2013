#ifndef GAME_H
#define GAME_H

#include <vector>
#include <Button.h>
#include <Viewport.h>
#include <Map.h>
#include <Input.h>
#include <Camera.h>
#include <Village.h>
#include <ParticleEngine.h>
#include <SFML\Audio.hpp>
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
	sf::SoundBuffer buffer;
	sf::Sound sound;
	void Update(const double& dt);
	void Draw(EGEMotor::Viewport& viewport);	
private:
	// Menu crap
	EGEMotor::Texture *menuTexture, *startTexture;
	GameObject menu;
	GUIButton* startButton;

	Map map;
	EGEMotor::ParticleEngine* particleEngine;
	EGEMotor::Input* input;
	EGEMotor::Camera* camera;
	EGEMotor::Viewport* viewport;
	GameState gameState;

	EGEMotor::Texture _townTexture;
	EGEMotor::Texture _villageTexture;
	EGEMotor::Texture _explorerTexture;
	std::vector<Village*> _villages;
	std::vector<Explorer*> _explorers;
	
	EGEMotor::Texture *sidebarTexture, *buttonTexture;
	GameObject sidebar;

	std::vector<GUIButton*> buttons;

	MapElements spawnElement;
	Hazard spawnHazard;

	
	float Difficulty;
	float _clock;

};

#endif