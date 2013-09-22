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

	bool slowed;
	bool dead;
	bool poison;
	float diseased; //100 = dead   diseace += dt


protected:
	void move(const double& dt);
	float clock, nextTurn;
	
	
	


};

#endif