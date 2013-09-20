#include <Text.h>
#include <iostream>
#define LAYER_COUNT 300

namespace EGEMath
{

// Font
Font::Font()
{
	m_font = new sf::Font();
}
Font::Font(std::string Filename)
{
	m_font = new sf::Font();
	loadFromFile(Filename);
}
Font::~Font()
{
	delete m_font;
}
void Font::loadFromFile(std::string Filename)
{
	m_font->loadFromFile("Assets/" + Filename);
}

// Text
Text::Text()
	: m_layer(0),
	  m_originPoint(0)
{
	m_text = new sf::Text();
}
Text::Text(const std::string string, EGEMath::Font* font, unsigned int CharacterSize)
	: m_layer(0),
	  m_originPoint(0)
{
	m_text = new sf::Text(string, *(font->m_font), CharacterSize);
}
Text::~Text()
{
#if _DEBUG
	std::cout<<"deleting text... ";
#endif
	delete m_text;
#if _DEBUG
	std::cout<<"done"<<std::endl;
#endif
}
void Text::setFont(EGEMath::Font* font)
{
	m_text->setFont(*(font->m_font));
}
void Text::setString(std::string string)
{
	m_text->setString(string);
}
void Text::setCharacterSize(unsigned int CharacterSize)
{
	m_text->setCharacterSize(CharacterSize);
}
void Text::setColor(unsigned int Red, unsigned int Green, unsigned int Blue, unsigned int Alpha)
{
	sf::Color color((sf::Uint8)Red, (sf::Uint8)Green, (sf::Uint8)Blue, (sf::Uint8)Alpha);
	m_text->setColor(color);
}
void Text::setPosition(EGEMath::Vector Position)
{
	sf::Vector2f pos(Position.x,Position.y);
	m_text->setPosition(pos);
}
void Text::setOrigin(EGEMath::Vector Origin)
{
	sf::Vector2f pos(Origin.x,Origin.y);
	m_text->setOrigin(pos);
}
void Text::setOriginPoint(int Point)
{
	if (0 < Point && Point < 10)
		m_originPoint = Point;
	else 
		m_originPoint = 0;

	updateOrigin();
}
void Text::updateOrigin()
{
	float charWidth = m_text->getCharacterSize()/12.0f;
	float charHeight = m_text->getCharacterSize()/3.8f;
	switch (m_originPoint)
	{
	case 1:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 0.0f, charHeight + m_text->getGlobalBounds().height * 1.0f);
		break;
	case 2:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 0.5f, charHeight + m_text->getGlobalBounds().height * 1.0f);
		break;
	case 3:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 1.0f, charHeight + m_text->getGlobalBounds().height * 1.0f);
		break;
	case 4:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 0.0f, charHeight + m_text->getGlobalBounds().height * 0.5f);
		break;
	case 5:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 0.5f, charHeight + m_text->getGlobalBounds().height * 0.5f);
		break;
	case 6:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 1.0f, charHeight + m_text->getGlobalBounds().height * 0.5f);
		break;
	case 7:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 0.0f, charHeight + m_text->getGlobalBounds().height * 0.0f);
		break;
	case 8:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 0.5f, charHeight + m_text->getGlobalBounds().height * 0.0f);
		break;
	case 9:
		m_text->setOrigin(charWidth + m_text->getGlobalBounds().width * 1.0f, charHeight + m_text->getGlobalBounds().height * 0.0f);
		break;
	default:
		m_text->setOrigin(charWidth,charHeight);
#if _DEBUG
		std::cout<<"Sprite origin out of range, origin set to top left"<<std::endl;
#endif
		break;
	}

}
void Text::setScale(float ScaleX, float ScaleY)
{
	m_text->setScale(ScaleX,ScaleY);
}
void Text::setScale(float Scale)
{
	setScale(Scale,Scale);
}
void Text::setScale(Vector Scale)
{
	setScale(Scale.x,Scale.y);
}
void Text::setLayer(int Layer)
{
	if (Layer >= 0 && Layer <= 1000)
		m_layer = Layer;
	else if (Layer < 0)
		m_layer = 0;
	else if (Layer > 1000)
		m_layer = 1000;
}
Vector Text::getPosition()
{
	return m_text->getPosition();
}
Vector Text::getOrigin()
{
	return m_text->getOrigin();
}
Vector Text::getScale()
{
	return m_text->getScale();
}
Vector Text::getSize()
{
	return Vector(m_text->getLocalBounds().width, m_text->getLocalBounds().height);
}
Vector Text::getTransformedSize()
{
	return Vector(m_text->getGlobalBounds().width, m_text->getGlobalBounds().height);
}
Rectangle Text::getGlobalBounds()
{
	return Rectangle(m_text->getGlobalBounds());
}

}