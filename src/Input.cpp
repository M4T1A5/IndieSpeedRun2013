#include <Input.h>

using namespace EGEMath;

Input::Input(EGEMath::Viewport* viewport)
	: active(true),
	  m_viewport(viewport),
	  ML(false),
	  MR(false),
	  MM(false)
{
}

Input::~Input(){}

bool Input::isButtonPressed(Button button)
{
	return isButtonDown(button,true);
}
bool Input::isButtonDown(Button button)
{
	return isButtonDown(button,false);
}
bool Input::isButtonDown(Button button, bool onPressOnly)
{
	if (active)
	{
		switch (button)
		{
		case MouseLeft:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))// if button pressed
			{
				if (!onPressOnly) // down-function
					return true; 
				else if (ML) // pressed-function
				{
					ML = false; // button is not released anymore
					return true; // but it was released
				}
			}
			else
				ML = true; // button is released
			break;
		case MouseRight:
			return sf::Mouse::isButtonPressed(sf::Mouse::Right);
			break;
		case MouseMiddle:
			return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
			break;
		default:
#if _DEBUG
			std::cout<<"button not definied"<<std::endl;
#endif
			break;
		}
	}
	return false;
}

//vector Input::getAbsoluteMousePosition()
//{
//	return sf::Mouse::getPosition();
//}

Vector Input::getMousePositionOnMap()
{
	return (getMousePosition()+m_viewport->getCameraPosition())-m_viewport->getWindowSize()/2.0f;
}
Vector Input::getMousePosition()
{
	if (active)
	{
		Vector retVal(sf::Mouse::getPosition(*m_viewport->m_window));
		//retVal.x /= m_window->getSize().x/(float)WINDOW_WIDTH;
		//retVal.y /= m_window->getSize().y/(float)WINDOW_HEIGHT;
		return retVal;
	}
	return Vector(0,0);
}

//void Input::setAbsoluteMousePosition(const vector& position)
//{
//	sf::Vector2i pos(position.x, position.y);
//	sf::Mouse::setPosition(pos);
//}
//	
//void Input::setMousePosition(const vector& position)
//{
//	sf::Vector2i pos(position.x, position.y);
//	sf::Mouse::setPosition(pos,*window);
//}