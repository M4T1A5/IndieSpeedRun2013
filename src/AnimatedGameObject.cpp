#include <AnimatedGameObject.h>

using namespace EGEMotor;

AnimatedGameObject::AnimatedGameObject(Texture* spriteSheet, int Frames, int FramesizeX, int FramesizeY,
		float Fps, int FirstFrame, bool Loop)
{
	_sprite = Sprite(spriteSheet);
	animation = new Animation(&_sprite, Frames, FramesizeX, FramesizeY,
		Fps, FirstFrame, Loop);
}

AnimatedGameObject::~AnimatedGameObject()
{
	delete animation;
}


// Public
void AnimatedGameObject::Update(const double& dt)
{
	animation->Update(dt);
}