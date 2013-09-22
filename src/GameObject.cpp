#include <GameObject.h>

using namespace EGEMath;
using namespace EGEMotor;

GameObject::GameObject()
	: Sprite()
{
}

GameObject::GameObject(EGEMotor::Texture* texture)
	: Sprite(texture)
{
}

GameObject::~GameObject()
{
	Sprite::~Sprite();
}


// Public
void GameObject::Draw(EGEMotor::Viewport& viewport)
{
	viewport.draw(this);
}

void GameObject::Update(const double& dt)
{
	move(dt);
}

void GameObject::SetTarget(EGEMath::Vector target)
{
	_targetPos = target;
}

void GameObject::ResetTarget()
{
	_targetPos = Vector();
}


void GameObject::SetDirection(EGEMath::Vector direction)
{
	_direction = direction;
}

void GameObject::SetSpeed(float speed)
{
	_speed = speed;
}

float GameObject::GetSpeed()
{
	return _speed;
}


// Protected
void GameObject::move(const double& dt)
{
	if(_targetPos.getLenght() > 0)
	{
		_direction = _targetPos - getPosition();
		_direction.Normalize();
	}
	Vector move = _direction * dt * _speed;

	if ((_targetPos-getPosition()).getLenght()<move.getLenght())
	{
		setPosition(_targetPos);
		SetSpeed(0);
	}
	else
		setPosition(getPosition()+move);
}