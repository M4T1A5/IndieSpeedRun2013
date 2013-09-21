#include "ParticleEngine.h"

using namespace EGEMotor;
using namespace EGEMath;

ParticleEngine::ParticleEngine(/*EGEMotor::Font* Font*/)
{
 	m_particleTexture = new Texture("tornado_sheet.png");
	//m_featherTexture = new Texture("featherEffect.png");
	//m_plusPoint = new Texture("plusPoint.png");
	//m_minusPoint = new Texture("minusPoint.png");
	//m_font = Font;
}
ParticleEngine::~ParticleEngine()
{
	for (unsigned int i = 0; i < m_particles.size(); ++i)
	{
		delete m_particles[i];
	}
}

void ParticleEngine::Update(float DeltaTime)
{
 	for (unsigned int i = 0; i < m_particles.size(); ++i)
	{
		if (m_particles[i]->Update(DeltaTime))
		{
			delete m_particles[i];
			m_particles.erase(m_particles.begin() + i);
		}
	}
}

void ParticleEngine::Draw(EGEMotor::Viewport* viewport)
{
	for (unsigned int i = 0; i < m_particles.size(); ++i)
	{
		m_particles[i]->Draw(viewport);
	}
}
void ParticleEngine::Reset()
{
	for (unsigned int i = 0; i < m_particles.size(); ++i)
	{
		delete m_particles[i];
	}
	m_particles.clear();
}

void ParticleEngine::addTest(EGEMath::Vector Position, EGEMath::Vector Direction)
{
	m_particles.push_back(new testParticle(Position,Direction,Vector(1,1),m_particleTexture));
}