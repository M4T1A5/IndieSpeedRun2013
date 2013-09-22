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
	ParticleEngine(/*EGEMotor::Font* Font*/);
	~ParticleEngine();
	void Update(float DeltaTime);
	void Draw(EGEMotor::Viewport* viewport);
	void Reset();

	void addTornado(EGEMath::Vector Position, EGEMath::Vector Direction);
	void addBug(EGEMath::Vector Position, EGEMath::Vector Direction);
	void addCat(EGEMath::Vector Position, EGEMath::Vector Direction);
	//void addFeather(EGEMath::Vector Position, bool Enemy = false);
	//void addFeather(EGEMath::Vector Position, EGEMath::Vector Direction, float SpreadDegrees, bool Enemy = false);
	//void addScore(EGEMath::Vector Position, float Score);
	std::vector<Tornado*> m_TornadoParticles;
	std::vector<Bug*> m_BugParticles;
	std::vector<Cat*> m_CatParticles;
private:
	EGEMotor::Texture* m_tornadoTexture;
	EGEMotor::Texture* m_catTexture;
	EGEMotor::Texture* m_bugTexture;
	//EGEMotor::Texture* m_minusPoint;
	//EGEMotor::Font* m_font;
	std::vector<Particle*> m_particles;
};

}
#endif