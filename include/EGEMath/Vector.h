#ifndef VECTOR_H
#define VECTOR_H
#include <SFML\System\Vector2.hpp>
#include <iostream>
#include <ostream>

namespace EGEMath
{

class Vector
{
public:
	Vector(void);
	Vector(float X, float Y);
	Vector(sf::Vector2f sfVector);
	Vector(sf::Vector2i sfVector);
	Vector(sf::Vector2u sfVector);
	~Vector(void);

	float Vector::getLenght();
	float Vector::getAngle();
	void Vector::rotate(float Degrees);

	float x,y;

	//Vector operator -();

	//Vector operator +(const Vector& RightVal);
	//Vector operator -(const Vector& RightVal);

	//Vector &operator +=(const Vector RightVal);
	//Vector &operator -=(const Vector RightVal);

	//Vector operator /(float &RightVal);
	//Vector &operator /=(float RightVal);

	//bool operator ==(const Vector& RightVal);
	//bool operator !=(const Vector& RightVal);

	//friend Vector operator *(const Vector& LeftVal, const float& RightVal);
	//friend Vector operator *(const float LeftVal, const Vector& RightVal);

	//friend const Vector &operator *=(Vector& LeftVal, const float RightVal);

	//friend std::ostream& operator <<(std::ostream& Ostr, const Vector& RightVal);
};

Vector operator -(const Vector& RightVal);

Vector operator +(const Vector& LeftVal,const Vector& RightVal);
Vector operator -(const Vector& LeftVal,const Vector& RightVal);

Vector operator +=(Vector& LeftVal,const Vector& RightVal);
Vector operator -=(Vector& LeftVal,const Vector& RightVal);

Vector operator /(const Vector& LeftVal,const float& RightVal);
Vector operator /=(Vector& LeftVal,const float& RightVal);

bool operator ==(const Vector& LeftVal,const Vector& RightVal);
bool operator !=(const Vector& LeftVal,const Vector& RightVal);

Vector operator *(const Vector& LeftVal, const float& RightVal);
Vector operator *(const float& LeftVal, const Vector& RightVal);

const Vector operator *=(Vector& LeftVal, const float& RightVal);

std::ostream& operator <<(std::ostream& Ostr, const Vector& RightVal);

}

#endif