#ifndef PARTICLE_H
#define PARTICLE_H

#include <Viewport.h>
#include <Animation.h>
#include <iostream>
#define PI 3.14159265358979323846264

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


//Splash Particle

class testParticle : public Particle
{
public:
	testParticle(EGEMath::Vector Position, EGEMath::Vector Direction, EGEMath::Vector Scale, EGEMotor::Texture* texture);
	~testParticle(){}
	bool Update(float DeltaTime);

private:
	Animation* m_animation;
	float m_startY;
};



////Feather Particle

//class feather : public particle
//{
//public:
//	feather(al::vector Position, al::vector Direction, al::vector Scale, al::texture* Texture, bool Enemy);
//	~feather(){}
//	bool update(float DeltaTime);
//private:
//	void setColor(int R = 255,int G = 255,int B = 255,int A = 255);
//
//	float m_timer, m_rotate, m_r, m_g, m_b, m_a;
//};




////Score Particle

//class scoreParticle : public particle
//{
//public:
//	scoreParticle(al::vector Position, al::vector Direction, al::texture* Texture, al::font* Font, float Score);
//	~scoreParticle(){}
//	bool update(float DeltaTime);
//	void draw(al::viewport* Viewport);
//private:
//	void stayOnScreen();
//	al::text m_text;
//	float m_r, m_g, m_b, m_a;
//};






#endif