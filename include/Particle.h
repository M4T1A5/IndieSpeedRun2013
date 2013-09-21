#ifndef PARTICLE_H
#define PARTICLE_H

#include <Viewport.h>
#include <Animation.h>
#include <iostream>

class Particle
{
public:
	Particle(EGEMath::Vector Position, EGEMath::Vector Direction, EGEMath::Vector Scale, EGEMotor::Texture* texture, float Life);
	virtual ~Particle();
	virtual bool Update(float DeltaTime);
	virtual void Draw(EGEMotor::Viewport* Viewport);

protected:
	EGEMath::Vector m_position;
	EGEMath::Vector m_direction;
	EGEMath::Vector m_scale;
	EGEMotor::Sprite m_sprite;
	float m_startLife;
	float m_life;
	bool m_dead;
};

#endif