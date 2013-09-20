#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <SFML\Graphics.hpp>
#include <Sprite.h>
#include <Text.h>
#define LAYER_COUNT 300

namespace EGEMath
{

class Viewport
{
public:
	Viewport(sf::RenderWindow *window);
	~Viewport();

	void draw(EGEMath::Sprite* sprite);
	void draw(EGEMath::Text* text);
	void renderSprites();
	void close();

private:
	sf::RenderWindow* m_window;
	std::vector<sf::Drawable*> m_objects[LAYER_COUNT + 1];
};

}

#endif