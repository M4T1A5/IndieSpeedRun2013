#include <Explorer.h>

Explorer::Explorer(EGEMotor::Texture* spriteSheet, int Frames, int FramesizeX, int FramesizeY, float Fps, EGEMath::Vector position)
	: AnimatedGameObject(spriteSheet,Frames,FramesizeX,FramesizeY,Fps)
{
	setPosition(position);
	setLayer(250);
}

Explorer::~Explorer()
{}

void Explorer::Update(float dt, EGEMath::Vector destination)
{
	AnimatedGameObject::Update(dt);
}
void Explorer::Draw(EGEMotor::Viewport& viewport)
{
	AnimatedGameObject::Draw(viewport);
}