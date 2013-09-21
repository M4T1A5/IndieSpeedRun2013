#include <GameObject.h>


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}


// Public
void GameObject::Draw(EGEMotor::Viewport& viewport)
{

}

void GameObject::Update(const double& dt)
{
	
}

EGEMath::Vector GameObject::GetPosition()
{
	return _curPos;
}

void GameObject::SetTarget(EGEMath::Vector target)
{
	_targetPos = target;
}

void GameObject::SetDirection(EGEMath::Vector direction)
{
	_direction = direction;
}

void GameObject::SetPosition(EGEMath::Vector position)
{
	_curPos = position;
}

void GameObject::SetLayer(unsigned int layer)
{
	_sprite.setLayer(layer);
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
		//_direction.normalize()
	}
}