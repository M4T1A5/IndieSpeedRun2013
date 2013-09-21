#include <Viewport.h>
#include <iostream>

namespace EGEMath
{

Viewport::Viewport(sf::RenderWindow* window)
	: m_window(window),
	  m_mapView(sf::Vector2f(window->getSize())/2.0f,sf::Vector2f(window->getSize())),
	  m_uiView(sf::Vector2f(window->getSize())/2.0f,sf::Vector2f(window->getSize()))
{
}
Viewport::~Viewport()
{}
void Viewport::draw(EGEMath::Sprite* sprite)
{
	m_objects[sprite->m_layer].push_back(sprite->m_sprite);
}
void Viewport::draw(EGEMath::Text* text)
{
	m_objects[text->m_layer].push_back(text->m_text);
}
void Viewport::renderSprites()
{
	m_window->setView(m_mapView);
 	for (int i = 0; i < LAYER_COUNT + 1; ++i)
	{
		if (i == 290)
			m_window->setView(m_uiView);
		for(unsigned int j = 0; j < m_objects[i].size(); ++j)
		{
			m_window->draw(*m_objects[i][j]);
		}
		m_objects[i].clear();
	}
}
void Viewport::close()
{
	m_window->close();
}
Vector Viewport::getWindowSize()
{
	return Vector(m_window->getSize());
}
Vector Viewport::getCameraPosition()
{
	return m_mapView.getCenter();
}
void Viewport::setCameraPosition(Vector Position)
{
	m_mapView.setCenter(Position.x,Position.y);
}

}