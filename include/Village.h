#ifndef VILLAGE_H
#define VILLAGE_H

#include <GameObject.h>
#include <Viewport.h>

class Village : public GameObject
{
public:
	Village(EGEMotor::Texture* texture,EGEMath::Vector position);
	~Village();

	void Update(float dt);
	void Draw(EGEMotor::Viewport& viewport);
	float Clock;
	float NextVillager;
};

#endif