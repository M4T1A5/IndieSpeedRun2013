#include <Viewport.h>

namespace EGEMath
{

Viewport::Viewport(sf::RenderWindow* window)
	: m_window(window)
{}
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
 	for (int i = 0; i < LAYER_COUNT + 1; ++i)
	{
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

}