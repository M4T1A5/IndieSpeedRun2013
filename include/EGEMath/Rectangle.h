#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SFML\Graphics\Rect.hpp>
#include <EGEMath\Vector.h>

namespace EGEMath
{

class Rectangle
{
public:
	public:
	Rectangle();
	Rectangle(float Left, float Top, float Width, float Height);
	Rectangle(Vector Position, float Width, float Height);
	Rectangle(Vector Position, Vector Size);
	Rectangle(sf::FloatRect Rect);

	bool intersects(Rectangle Rectangle);
	bool contains(Vector Position);

	~Rectangle();
	float width, height, left, top;
};


}

#endif