#include <GameObject.h>

using namespace EGEMath;
using namespace EGEMotor;

GameObject::GameObject()
{
}

GameObject::GameObject(EGEMotor::Texture* texture)
{
	_sprite = new Sprite(texture);
}

GameObject::~GameObject()
{
}


// Public
void GameObject::Draw(EGEMotor::Viewport& viewport)
{
	viewport.draw(_sprite);
}

void GameObject::Update(const double& dt)
{
	move(dt);
	_sprite->setPosition(_curPos);
}

void GameObject::SetOrigin(EGEMath::Vector origin)
{
	_sprite->setOrigin(origin);
}

void GameObject::SetOriginPoint(int point)
{
	_sprite->setOriginPoint(point);
}

Vector GameObject::GetOrigin()
{
	return _sprite->getOrigin();
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

void GameObject::SetPosition(EGEMath::Vector position)
{
	_curPos = position;
}

Vector GameObject::GetPosition()
{
	return _curPos;
}


void GameObject::SetSpeed(float speed)
{
	_speed = speed;
}

float GameObject::GetSpeed()
{
	return _speed;
}


void GameObject::SetLayer(unsigned int layer)
{
	_sprite->setLayer(layer);
}

unsigned int GetLayer()
{
	return 0;
}


// Private
void GameObject::move(const double& dt)
{
	if(_targetPos.getLenght() > 0)
	{
		_direction = _targetPos - _curPos;
		_direction.Normalize();
	}
	Vector move = _direction * dt * _speed;
	_curPos += move;

	if((_targetPos - _curPos).getLenght() < move.getLenght())
	{
		SetPosition(_targetPos);
		SetSpeed(0);
	}
}