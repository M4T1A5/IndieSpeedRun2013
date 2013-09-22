#include <AnimatedGameObject.h>

using namespace EGEMotor;

AnimatedGameObject::AnimatedGameObject(Texture* spriteSheet, int Frames, int FramesizeX, int FramesizeY,
		float Fps, int FirstFrame, bool Loop)
		: GameObject(spriteSheet)
{
	//_sprite = new Sprite(spriteSheet);
	animation = new Animation(this, Frames, FramesizeX, FramesizeY,
		Fps, FirstFrame, Loop);
}

AnimatedGameObject::~AnimatedGameObject()
{
	GameObject::~GameObject();
	delete animation;
}


// Public
void AnimatedGameObject::Update(const double& dt)
{
	GameObject::Update(dt);
	animation->Update(dt);
}