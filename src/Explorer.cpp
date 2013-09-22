#include <Explorer.h>

using namespace EGEMath;
using namespace EGEMotor;

Explorer::Explorer(EGEMotor::Texture* spriteSheet, int Frames, int FramesizeX, int FramesizeY, float Fps, EGEMath::Vector position)
	: AnimatedGameObject(spriteSheet,Frames,FramesizeX,FramesizeY,Fps),
	  clock(0),
	  nextTurn(rand()%40/10.0f),
	  slowed(false),
	  poison(false),
	  diseased(0),
	  dead(false)
{
	setPosition(position);
	setOriginPoint(2);
	setLayer(250);
	_targetPos = Vector(3000,450);
	_speed = 20;
	_direction = Vector(rand()%100+2, 0);
	_direction.rotate(rand()%100);
}

Explorer::~Explorer()
{
	AnimatedGameObject::~AnimatedGameObject();
}

void Explorer::Update(float dt, Vector destination)
{
	clock += dt;
	AnimatedGameObject::Update(dt);
	slowed = false;
	setLayer(CountLayer(getPosition().y)-6);

	if (poison)
		diseased += dt*10.0f;
	if (diseased > 0)
	{
		diseased += dt*1.0f;
		if (diseased > 100)
			dead = true;
		setColor(255
				,255 *(1-diseased/100.0f)
				,255 *(1-diseased/100.0f)
				,255);
	}

}
void Explorer::Draw(EGEMotor::Viewport& viewport)
{
	AnimatedGameObject::Draw(viewport);
}

void Explorer::move(const double& dt)
{
	if (clock >nextTurn)
	{
		clock-= nextTurn;
		nextTurn = rand()%40/10.0f+5;
		_direction = Vector(rand()%100+2, 0);
		_direction.rotate(rand()%10000);
	}
	Vector volcano = _direction;
	if(_targetPos.getLenght() > 0)
	{
		volcano += _targetPos - getPosition();
		volcano.Normalize();
	}
	_direction += volcano*dt*150;
	Vector move = _direction;
	move.Normalize();
	if (slowed)
		animation->SetFPS(5);
	else
		animation->SetFPS(12);
	move *= dt * _speed * (1-slowed*0.7f);

	setPosition(getPosition()+move);
}