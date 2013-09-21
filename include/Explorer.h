#ifndef EXPLORER_H
#define EXPLORER_H

#include <AnimatedGameObject.h>
#include <Viewport.h>

class Explorer : public AnimatedGameObject
{
public:
	Explorer(EGEMotor::Texture* spriteSheet, int Frames, int FramesizeX, int FramesizeY, float Fps, EGEMath::Vector position);
	~Explorer();

	void Update(float dt, EGEMath::Vector destination);
	void Draw(EGEMotor::Viewport& viewport);

};

#endif