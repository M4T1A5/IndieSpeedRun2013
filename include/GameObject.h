#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <EGEMath\Vector.h>
#include <Viewport.h>
#include <Sprite.h>

class GameObject : public EGEMotor::Sprite
{
public:
	GameObject();
	GameObject(EGEMotor::Texture* texture);
	virtual ~GameObject();

	virtual void Draw(EGEMotor::Viewport& viewport);
	virtual void Update(const double& dt);


	void SetTarget(EGEMath::Vector target);
	void ResetTarget();

	void SetDirection(EGEMath::Vector direction);
	
	void SetSpeed(float speed);
	float GetSpeed();

protected:
	virtual void move(const double& dt);

	float _speed;

	// Either move by a target or a normalized direction vector
	EGEMath::Vector _targetPos, _direction;
};

#endif