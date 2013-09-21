#include "ParticleEngine.h"

using namespace EGEMotor;
using namespace EGEMath;

ParticleEngine::ParticleEngine(EGEMotor::Font* Font)
{
	m_splashTexture = new Texture("splashAnimation.png");
	m_featherTexture = new Texture("featherEffect.png");
	m_plusPoint = new Texture("plusPoint.png");
	m_minusPoint = new Texture("minusPoint.png");
	m_font = Font;
}
ParticleEngine::~ParticleEngine()
{
	delete m_splashTexture;
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