#ifndef PARTICLEENGINE_H
#define PARTICLEENGINE_H

#include <iostream>
#include <Particle.h>
#include <Viewport.h>

namespace EGEMotor
{

class ParticleEngine
{
public:
	ParticleEngine(EGEMotor::Font* Font);
	~ParticleEngine();
	void Update(float DeltaTime);
	void Draw(EGEMotor::Viewport* viewport);
	void Reset();

	void addSplash(EGEMath::Vector Position, EGEMath::Vector Direction);
	void addFeather(EGEMath::Vector Position, bool Enemy = false);
	void addFeather(EGEMath::Vector Position, EGEMath::Vector Direction, float SpreadDegrees, bool Enemy = false);
	void addScore(EGEMath::Vector Position, float Score);
private:
	EGEMotor::Texture* m_splashTexture;
	EGEMotor::Texture* m_featherTexture;
	EGEMotor::Texture* m_plusPoint;
	EGEMotor::Texture* m_minusPoint;
	EGEMotor::Font* m_font;
	std::vector<Particle*> m_particles;
};

}
#endif