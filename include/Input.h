#ifndef INPUT_H
#define INPUT_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <Viewport.h>

namespace EGEMath
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
	Input(EGEMath::Viewport* viewport);
	~Input();

	
	bool isButtonPressed(Button button);
	bool isButtonDown(Button button);

	//vector getAbsoluteMousePosition();
	
	Vector getMousePositionOnMap();
	Vector getMousePosition();

	//void setAbsoluteMousePosition(const vector& position);

	void setMousePosition(const Vector& position);

	bool active;
private:
	
	bool isButtonDown(Button button, bool onPressOnly);

	EGEMath::Viewport* m_viewport;
	bool isReleased[Button::ButtonCount];
	bool ML,MR,MM; // is button released
};

}

#endif