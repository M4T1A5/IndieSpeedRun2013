#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <EGEMath\Vector.h>
#include <Viewport.h>
#include <Sprite.h>

class GameObject
{
public:
	GameObject();
	GameObject(EGEMotor::Texture* texture);
	virtual ~GameObject();

	virtual void Draw(EGEMotor::Viewport& viewport);
	virtual void Update(const double& dt);

	void SetOrigin(EGEMath::Vector origin);
	void SetOriginPoint(int point);
	EGEMath::Vector GetOrigin();

	void SetTarget(EGEMath::Vector target);
	void ResetTarget();

	void SetDirection(EGEMath::Vector direction);
	void SetPosition(EGEMath::Vector position);
	EGEMath::Vector GetPosition();
	
	void SetSpeed(float speed);
	float GetSpeed();

	void SetLayer(unsigned int layer);
	unsigned int GetLayer();

protected:
	virtual void move(const double& dt);

	float _speed;

	EGEMotor::Sprite* _sprite;
	// Either move by a target or a normalized direction vector
	EGEMath::Vector _curPos, _targetPos, _direction;
};

#endif