#ifndef BUTTON_H
#define BUTTON_H

#include <Particle.h>
#include <MapElements.h>
#include <Sprite.h>
#include <Animation.h>
#include <Input.h>
#include <EGEMath/Vector.h>

class GUIButton : public EGEMotor::Sprite
{
public:
	GUIButton(EGEMotor::Texture* texture, EGEMath::Vector position, EGEMath::Rectangle crop,
		EGEMotor::Input* input);
	~GUIButton();

	void SetTexture(EGEMotor::Texture* texture);
   	void update(float dt);
	void draw(EGEMotor::Viewport& viewport);
	bool isPressed();
	bool mouseOver();

	MapElements elementToSpawn;
	Hazard hazardToSpawn;

private:
	EGEMotor::Input* m_input;
};


#endif