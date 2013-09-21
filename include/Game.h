#ifndef GAME_H
#define GAME_H

#include <vector>
#include <Button.h>
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
		WARMUP,
		PLAY,
		PAUSE
	};
	Game(EGEMotor::Viewport& viewport, EGEMotor::Input &input);
	~Game();

	void Update(const double& dt);
	void Draw(EGEMotor::Viewport& viewport);	
private:
	// Menu crap
	EGEMotor::Texture *menuTexture, *startTexture;
	GameObject menu;
	GUIButton* startButton;

	Map map;
	EGEMotor::Input* input;
	EGEMotor::Camera* camera;
	EGEMotor::Viewport* viewport;
	GameState gameState;

	EGEMotor::Texture *sidebarTexture, *buttonTexture;
	GameObject sidebar;

	std::vector<GUIButton*> buttons;
};

#endif