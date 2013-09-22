#ifndef ANIMATION_H
#define ANIMATION_H

#include <Sprite.h>


class Animation
{
public:
	Animation(EGEMotor::Sprite *sprite, int Frames, int FramesizeX, int FramesizeY, float Fps= (5.0f), int FirstFrame = 0, bool Loop = true);
	~Animation();
	void Update(float deltaTime);
	void ChangeAnimation(int FirstFrameofLoop, int FramesinLoop);
	void ChangeAnimation(int FirstFrameofLoop, int FramesinLoop, int AnimationStartPoint, float Fps = (5.0f));
	int getCurrentFrame();
	void SetFPS(float FPS);
private:
	void setVisibleFrame();

	EGEMotor::Sprite* m_sprite;

	float m_timer;
	int m_currentFrame;
	float m_fps;
	int m_firstFrame;
	int m_frames;
	int m_framesizeX;
	int m_framesizeY;
	bool m_loop;
	//bool m_flip;
	bool m_transition;
	//int counter;
};

#endif