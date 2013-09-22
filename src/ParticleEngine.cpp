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
 	for (unsigned int i = 0; i < m_TornadoParticles.size(); ++i)
	{
		if (m_TornadoParticles[i]->Update(DeltaTime))
		{
			delete m_TornadoParticles[i];
			m_TornadoParticles.erase(m_TornadoParticles.begin() + i);
		}
	}
 	for (unsigned int i = 0; i < m_BugParticles.size(); ++i)
	{
		if (m_BugParticles[i]->Update(DeltaTime))
		{
			delete m_BugParticles[i];
			m_BugParticles.erase(m_BugParticles.begin() + i);
		}
	}
 	for (unsigned int i = 0; i < m_CatParticles.size(); ++i)
	{
		if (m_CatParticles[i]->Update(DeltaTime))
		{
			delete m_CatParticles[i];
			m_CatParticles.erase(m_CatParticles.begin() + i);
		}
	}
}

void ParticleEngine::Draw(EGEMotor::Viewport* viewport)
{
	for (unsigned int i = 0; i < m_TornadoParticles.size(); ++i)
	{
		m_TornadoParticles[i]->Draw(viewport);
	}
 	for (unsigned int i = 0; i < m_BugParticles.size(); ++i)
	{
		m_BugParticles[i]->Draw(viewport);
	}
 	for (unsigned int i = 0; i < m_CatParticles.size(); ++i)
	{
		m_CatParticles[i]->Draw(viewport);
	}
}
void ParticleEngine::Reset()
{
	for (unsigned int i = 0; i < m_TornadoParticles.size(); ++i)
	{
		delete m_TornadoParticles[i];
	}
	m_TornadoParticles.clear();
	for (unsigned int i = 0; i < m_BugParticles.size(); ++i)
	{
		delete m_BugParticles[i];
	}
	m_BugParticles.clear();
	for (unsigned int i = 0; i < m_CatParticles.size(); ++i)
	{
		delete m_CatParticles[i];
	}
	m_CatParticles.clear();
}

void ParticleEngine::addTornado(EGEMath::Vector Position, EGEMath::Vector Direction)
{
	auto *particle = new Tornado(Position,Direction,Vector(0.6,0.6),m_tornadoTexture);
	//m_particles.push_back(particle);
	m_TornadoParticles.push_back(particle);
}

void ParticleEngine::addBug(EGEMath::Vector Position, EGEMath::Vector Direction)
{
	auto *particle = new Bug(Position,Direction,Vector(1,1),m_bugTexture);
	//m_particles.push_back(particle);
	m_BugParticles.push_back(particle);
}

void ParticleEngine::addCat(EGEMath::Vector Position, EGEMath::Vector Direction)
{
	auto *particle = new Cat(Position,Direction,Vector(-0.6,0.6),m_catTexture);
	//m_particles.push_back(particle);
	m_CatParticles.push_back(particle);
}