#ifndef ANITMATEDGAMEOBJECT_H
#define ANITMATEDGAMEOBJECT_H

#include <GameObject.h>
#include <Animation.h>

class AnimatedGameObject : public GameObject
{
public:
	AnimatedGameObject(EGEMotor::Texture* spriteSheet, int Frames, int FramesizeX, int FramesizeY,
		float Fps= (5.0f), int FirstFrame = 0, bool Loop = true);
	~AnimatedGameObject();

	virtual void Update(const double& dt);
protected:
	Animation* animation;
};

#endif