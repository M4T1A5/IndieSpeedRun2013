#ifndef INPUT_H
#define INPUT_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <Viewport.h>

namespace EGEMotor
{

const enum Button
{
	MouseLeft,
	MouseRight,
	MouseMiddle,
	ButtonCount
};

class Input
{
public:
	Input(EGEMotor::Viewport* viewport);
	~Input();

	
	bool isButtonPressed(Button button);
	bool isButtonDown(Button button);

	//vector getAbsoluteMousePosition();
	
	EGEMath::Vector getMousePositionOnMap();
	EGEMath::Vector getMousePosition();

	//void setAbsoluteMousePosition(const vector& position);

	void setMousePosition(const EGEMath::Vector& position);
	void keepMouseInWindow();

	bool active;
private:
	
	bool isButtonDown(Button button, bool onPressOnly);

	EGEMotor::Viewport* m_viewport;
	bool isReleased[Button::ButtonCount];
	bool ML,MR,MM; // is button released
};

}

#endif