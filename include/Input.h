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
	MouseMiddle
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

	//void setMousePosition(const vector& position);

	bool active;
private:
	
	bool isButtonDown(Button button, bool onPressOnly);
	EGEMath::Viewport* m_viewport;
	bool ML,MR,MM; // is button released
};

}

#endif