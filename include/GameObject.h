#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <EGEMath\Vector.h>
#include <Viewport.h>
#include <Sprite.h>

class GameObject
{
public:
	GameObject();
	GameObject(EGEMath::Vector spawnPos);
	virtual ~GameObject();

	virtual void Draw(EGEMotor::Viewport& viewport);
	virtual void Update(const double& dt);

	EGEMath::Vector GetPosition();
	void SetTarget(EGEMath::Vector target);
	void SetDirection(EGEMath::Vector direction);
	void SetPosition(EGEMath::Vector position);
	void SetLayer(unsigned int layer);
	unsigned int GetLayer();

private:
	virtual void move(const double& dt);

	EGEMotor::Sprite _sprite;
	// Either move by a target or a normalized direction vector
	EGEMath::Vector _curPos, _targetPos, _direction;
};

#endif