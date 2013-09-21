#include <Sprite.h>
#include <iostream>
#define LAYER_COUNT 300

namespace EGEMotor
{
using namespace EGEMath;
Texture::Texture()
	: m_texture(NULL)
{}
Texture::Texture(std::string TextureName)
	: m_texture(NULL)
{
	loadTexture(TextureName);
}
const Vector Texture::getTextureSize()
{
	return m_texture->getSize();
}
Texture::~Texture()
{
	delete m_texture;
}
void Texture::loadTexture(std::string TextureName)
{
	if (m_texture == NULL)
	{
		m_texture = new sf::Texture();
		m_texture->loadFromFile("Assets/" + TextureName);
		m_texture->setSmooth(false);
	}
	else 
	{
#if _DEBUG
		std::cout<<"Texture already loaded";
#endif
	}
}

// Sprite
Sprite::Sprite()
	: m_layer(0),
	  m_originPoint(0)
{
	m_sprite = new sf::Sprite();
}
Sprite::Sprite(EGEMotor::Texture *texture)
	: m_layer(0),
	  m_originPoint(0)
{
	m_sprite = new sf::Sprite();
	setTexture(texture);
}
Sprite::~Sprite()
{
#if _DEBUG
	std::cout<<"deleting sprite... ";
#endif
	delete m_sprite;
#if _DEBUG
	std::cout<<"done"<<std::endl;
#endif
}
void Sprite::setTexture(Texture *texture)
{
	m_sprite->setTexture(*texture->m_texture); 
}
void Sprite::setTextureRectangle(Rectangle rectangle)
{
	int left = int(rectangle.left + 0.5f);
	int top = int(rectangle.top + 0.5f);
	int width = int(rectangle.width + 0.5f);
	int height = int(rectangle.height + 0.5f);
	m_sprite->setTextureRect(sf::IntRect(left,top,width,height));
}
Vector Sprite::getTextureSize()
{
	return Vector((float)m_sprite->getTexture()->getSize().x,
		(float)m_sprite->getTexture()->getSize().y);
}

void Sprite::setColor(unsigned int Red, unsigned int Green, unsigned int Blue, unsigned int Alpha)
{
	m_sprite->setColor(sf::Color((sf::Uint8)Red,(sf::Uint8)Green,(sf::Uint8)Blue,(sf::Uint8)Alpha));
}
void Sprite::setPosition(Vector Position)
{
	sf::Vector2f pos(Position.x,Position.y);
	m_sprite->setPosition(pos);
}
void Sprite::setRotation(float Angle)
{
	m_sprite->setRotation(Angle);
}
void Sprite::setOrigin(EGEMath::Vector Origin)
{
	sf::Vector2f pos(Origin.x,Origin.y);
	m_sprite->setOrigin(pos);
}
void Sprite::setOriginPoint(int Point)
{
	if (0 < Point && Point < 10)
		m_originPoint = Point;
	else 
		m_originPoint = 0;

	updateOrigin();
}
void Sprite::updateOrigin()
{
	switch (m_originPoint)
	{
	case 1:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.0f, m_sprite->getLocalBounds().height * 1.0f);
		break;
	case 2:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 1.0f);
		break;
	case 3:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 1.0f, m_sprite->getLocalBounds().height * 1.0f);
		break;
	case 4:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.0f, m_sprite->getLocalBounds().height * 0.5f);
		break;
	case 5:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 0.5f);
		break;
	case 6:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 1.0f, m_sprite->getLocalBounds().height * 0.5f);
		break;
	case 7:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.0f, m_sprite->getLocalBounds().height * 0.0f);
		break;
	case 8:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 0.0f);
		break;
	case 9:
		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 1.0f, m_sprite->getLocalBounds().height * 0.0f);
		break;
	default:
		m_sprite->setOrigin(0,0);
#if _DEBUG
		std::cout<<"Sprite origin out of range, origin set to top left"<<std::endl;
#endif
		break;
	}
}
void Sprite::setScale(float ScaleX, float ScaleY)
{
	m_sprite->setScale(ScaleX,ScaleY);
}
void Sprite::setScale(float Scale)
{
	setScale(Scale,Scale);
}
void Sprite::setScale(Vector Scale)
{
	setScale(Scale.x,Scale.y);
}
void Sprite::setLayer(int Layer)
{
	if (Layer >= 0 && Layer <= LAYER_COUNT)
		m_layer = Layer;
	else if (Layer < 0)
		m_layer = 0;
	else if (Layer > LAYER_COUNT)
		m_layer = LAYER_COUNT;
}
int Sprite::getLayer()
{
	return m_layer;
}
//Vector Sprite::getColor()
//{
//	return m_sprite->getColor(); fix this if u can
//}
Vector Sprite::getPosition()
{
	return m_sprite->getPosition();
}
Vector Sprite::getOrigin()
{
	return m_sprite->getOrigin();
}
Vector Sprite::getScale()
{
	return m_sprite->getScale();
}
Vector Sprite::getSize()
{
	return Vector(m_sprite->getLocalBounds().width, m_sprite->getLocalBounds().height);
}
Vector Sprite::getTransformedSize()
{
	return Vector(m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height);
}
Rectangle Sprite::getGlobalBounds()
{
	return Rectangle(m_sprite->getGlobalBounds());
}

}