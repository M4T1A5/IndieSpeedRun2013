#include <EGEMath\Vector.h>
#include <cmath>
#include <SFML\Graphics\Transform.hpp>
#define PI 3.14159265358979323846264

namespace EGEMath
{

Vector::Vector()
	: x(0), y(0)
{}
Vector::Vector(sf::Vector2f sfVector)
{
	x = sfVector.x;
	y = sfVector.y;
}
Vector::Vector(sf::Vector2i sfVector)
{
	x = (float)sfVector.x;
	y = (float)sfVector.y;
}
Vector::Vector(sf::Vector2u sfVector)
{
	x = (float)sfVector.x;
	y = (float)sfVector.y;
}
Vector::Vector(float X, float Y)
	: x(X), y(Y)
{}
Vector::~Vector(){}
float Vector::getLenght()
{
	return sqrt(pow(x,2) + pow(y,2));
}
float Vector::getAngle()
{
	if (x == 0)
	{
		if (y > 0)
			return 90;
		return 270;
	}
	else
	{
		float angle = float(atan(y/x)*(180.0f/PI));
		if (x < 0)
			angle += 180;
		else if (angle < 0)
			angle += 360;
		return angle;
	}
}
void Vector::rotate(float Degrees)
{
	Degrees = fmod(Degrees,360);
	sf::Transform transform;
	transform.rotate(Degrees);
	Vector rotated = transform.transformPoint(x,y);
	x = rotated.x;
	y = rotated.y;
}
#pragma region operators

Vector Vector::operator-()
{
	return Vector(-this->x, -this->y);
}

Vector Vector::operator +(const Vector& RightVal)
{
	return Vector(this->x+RightVal.x,this->y+RightVal.y);
}
Vector Vector::operator -(const Vector& RightVal)
{
	return Vector(this->x-RightVal.x,this->y-RightVal.y);
}

Vector &Vector::operator +=(const Vector& RightVal)
{
	this->x += RightVal.x;
	this->y += RightVal.y;
	return *this;
}
Vector &Vector::operator -=(const Vector& RightVal)
{
	this->x -= RightVal.x;
	this->y -= RightVal.y;
	return *this;
}

Vector Vector::operator /(float RightVal)
{
	return Vector(this->x / (float)RightVal,this->y / (float)RightVal);
}
Vector &Vector::operator /=(float RightVal)
{
	this->x /= (float)RightVal;
	this->y /= (float)RightVal;
	return *this;
}

bool Vector::operator ==(const Vector& RightVal)
{
	if (this->x == RightVal.x && this->y == RightVal.y)
		return true;
	return false;
}
bool Vector::operator !=(const Vector& RightVal)
{
	if (this->x == RightVal.x && this->y == RightVal.y)
		return false;
	return true;
}

namespace al
{

Vector operator *(const Vector& LeftVal, const float RightVal)
{
	return Vector(LeftVal.x * RightVal,LeftVal.y * RightVal);
}
Vector operator *(const float LeftVal, const Vector& RightVal)
{
	return Vector(LeftVal * RightVal.x,LeftVal * RightVal.y);
}

const Vector &operator *=(Vector& LeftVal, float RightVal)
{
	LeftVal.x *= RightVal;
	LeftVal.y *= RightVal;
	return LeftVal;
}

//void operator <<(std::ostream& Ostr, const Vector RightVal)
//{
//    Ostr << "x:" << RightVal.x << ", y:" << RightVal.y << "";
//}

}

}