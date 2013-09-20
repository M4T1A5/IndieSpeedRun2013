#ifndef SPRITE_H
#define SPRITE_H

#include <SFML\Graphics.hpp>
#include <EGEMath\Vector.h>
#include <EGEMath\Rectangle.h>

namespace EGEMath
{

class Texture
{
public:
	Texture();
	Texture(std::string TextureName);
	~Texture();

	void loadTexture(std::string TextureName);

private:
	Texture(Texture& texture);
	sf::Texture* m_texture;
	friend class Sprite;
};

class Sprite
{
public:
	Sprite();
	Sprite(EGEMath::Texture* texture);
	~Sprite();
	void setTexture(EGEMath::Texture* texture);
	void setTextureRectangle(Rectangle rectangle);
	Vector getTextureSize();

	void setColor(unsigned int Red, unsigned int Green, unsigned int Blue, unsigned int alpha);
	void setPosition(EGEMath::Vector Position);
	void setRotation(float Angle);
	void setOrigin(EGEMath::Vector Origin);
	/*Set Origin Point according to location on numpad*/
	void setOriginPoint(int Point);
	void updateOrigin();
	void setScale(float ScaleX, float ScaleY);
	void setScale(float Scale);
	void setScale(Vector Scale);
	/*Layer 0-5 game items, 10-290 pickups, 295-300 menu items*/
	void setLayer(int Layer);
	//Vector getColor(); lets make this later...
	Vector getPosition();
	Vector getOrigin();
	Vector getScale();
	Vector getSize();
	Vector getTransformedSize();
	Rectangle getGlobalBounds();

private:
	Sprite(Sprite& sprite);
	sf::Sprite* m_sprite;
	int m_originPoint;
	int m_layer;
	friend class Viewport;
};

}

#endif