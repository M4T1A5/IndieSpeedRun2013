#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <SFML\Graphics.hpp>
#include <Sprite.h>
#include <Text.h>
#define LAYER_COUNT 300

namespace EGEMotor
{

class Viewport
{
public:
	Viewport(sf::RenderWindow *window);
	~Viewport();

	void draw(EGEMotor::Sprite* sprite);
	void draw(EGEMotor::Text* text);
	void renderSprites();
	void close();
	EGEMath::Vector getWindowSize();
	EGEMath::Vector getCameraPosition();
	void setCameraPosition(const EGEMath::Vector Position);
	sf::View m_mapView;
private:
	sf::RenderWindow* m_window;
	std::vector<sf::Drawable*> m_objects[LAYER_COUNT + 1];
	sf::View m_uiView;
	EGEMath::Vector m_camera;
	friend class Input;
};

}

#endif