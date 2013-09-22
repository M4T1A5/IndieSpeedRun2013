#include "ParticleEngine.h"

using namespace EGEMotor;
using namespace EGEMath;

ParticleEngine::ParticleEngine(/*EGEMotor::Font* Font*/)
{
 	m_tornadoTexture = new Texture("tornado_sheet.png");
	m_catTexture = new Texture("tiger.png");
	m_bugTexture = new Texture("mosqitoes.png");
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

void ParticleEngine::addTornado(EGEMath::Vector Position, EGEMath::Vector Direction)
{
	auto *particle = new Tornado(Position,Direction,Vector(0.6,0.6),m_tornadoTexture);
	m_particles.push_back(particle);
	m_TornadoParticles.push_back(particle);
}

void ParticleEngine::addBug(EGEMath::Vector Position, EGEMath::Vector Direction)
{
	auto *particle = new Bug(Position,Direction,Vector(1,1),m_bugTexture);
	m_particles.push_back(particle);
	m_BugParticles.push_back(particle);
}

void ParticleEngine::addCat(EGEMath::Vector Position, EGEMath::Vector Direction)
{
	auto *particle = new Cat(Position,Direction,Vector(0.6,0.6),m_catTexture);
	m_particles.push_back(particle);
	m_CatParticles.push_back(particle);
}