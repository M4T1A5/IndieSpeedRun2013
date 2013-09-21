#ifndef SPRITE_H
#define SPRITE_H

#include <SFML\Graphics.hpp>
#include <EGEMath\Vector.h>
#include <EGEMath\Rectangle.h>

namespace EGEMotor
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
	Sprite(EGEMotor::Texture* texture);
	~Sprite();
	void setTexture(EGEMotor::Texture* texture);
	void setTextureRectangle(EGEMath::Rectangle rectangle);
	EGEMath::Vector getTextureSize();

	void setColor(unsigned int Red, unsigned int Green, unsigned int Blue, unsigned int alpha);
	void setPosition(EGEMath::Vector Position);
	void setRotation(float Angle);
	void setOrigin(EGEMath::Vector Origin);
	/*Set Origin Point according to location on numpad*/
	void setOriginPoint(int Point);
	void updateOrigin();
	void setScale(float ScaleX, float ScaleY);
	void setScale(float Scale);
	void setScale(EGEMath::Vector Scale);
	/*Layer 0-5 game items, 10-290 pickups, 295-300 menu items*/
	void setLayer(int Layer);
	//Vector getColor(); lets make this later...
	EGEMath::Vector getPosition();
	EGEMath::Vector getOrigin();
	EGEMath::Vector getScale();
	//Returns size after cropping, before scaling
	EGEMath::Vector getSize();
	//Returns size after cropping and scaling
	EGEMath::Vector getTransformedSize();
	EGEMath::Rectangle getGlobalBounds();

private:
	Sprite(Sprite& sprite);
	sf::Sprite* m_sprite;
	int m_originPoint;
	int m_layer;
	friend class Viewport;
};

}

#endif