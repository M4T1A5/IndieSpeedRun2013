#ifndef TEXT_H
#define TEXT_H

#include <SFML\Graphics.hpp>
#include <EGEMath\Vector.h>
#include <EGEMath\Rectangle.h>

namespace EGEMotor
{

class Font
{
public:
	Font();
	Font(std::string Filename);
	~Font();
	void loadFromFile(std::string Filename);
private:
	Font(Font& font);
	sf::Font* m_font;
	friend class Text;
};

class Text
{
public:
	Text();
	Text(const std::string string, EGEMotor::Font* font, unsigned int CharacterSize = 30);
	~Text();
	void setFont(EGEMotor::Font* font);
	void setString(std::string string);
	void setCharacterSize(unsigned int CharacterSize = 30);

	void setColor(unsigned int Red = 255, unsigned int Green = 255, unsigned int Blue = 255, unsigned int Alpha = 255);
	void setPosition(EGEMath::Vector Position);
	void setOrigin(EGEMath::Vector Origin);
	/*Set Origin Point according to location on numpad*/
	void setOriginPoint(int Point);
	void updateOrigin();
	void setScale(float ScaleX, float ScaleY);
	void setScale(float Scale);
	void setScale(EGEMath::Vector Scale);
	/*Layer 0-5 game items, 10-290 pickups, 295-300 menu items*/
	void setLayer(int Layer);

	EGEMath::Vector getPosition();
	EGEMath::Vector getOrigin();
	EGEMath::Vector getScale();
	EGEMath::Vector getSize();
	EGEMath::Vector getTransformedSize();
	EGEMath::Rectangle getGlobalBounds();

private:
	Text(Text& text);
	sf::Text* m_text;
	int m_originPoint;
	int m_layer;
	friend class Viewport;
};

}

#endif