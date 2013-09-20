#include <EGEMath\Rectangle.h>

namespace EGEMath
{

Rectangle::Rectangle()
{
	left = 0;
	top = 0;
	width = 0;
	height = 0;
}
Rectangle::Rectangle(float Left, float Top, float Width, float Height)
{
	left = Left;
	top = Top;
	width = Width;
	height = Height;
}
Rectangle::Rectangle(Vector Position, float Width, float Height)
{
	left = Position.x;
	top = Position.y;
	width = Width;
	height = Height;
}
Rectangle::Rectangle(Vector Position, Vector Size)
{
	left = Position.x;
	top = Position.y;
	width = Size.x;
	height = Size.y;
}
Rectangle::Rectangle(sf::FloatRect Rect)
{
	left = Rect.left;
	top = Rect.top;
	width = Rect.width;
	height = Rect.height;
}
Rectangle::~Rectangle()
{}
bool Rectangle::intersects(Rectangle Rectangle)
{
	return sf::Rect<float>(left, top, width, height).intersects(sf::Rect<float>(Rectangle.left, Rectangle.top, Rectangle.width, Rectangle.height));
}
bool Rectangle::contains(Vector Position)
{
	return sf::Rect<float>(left, top, width, height).contains(sf::Vector2f(Position.x, Position.y));
}

}