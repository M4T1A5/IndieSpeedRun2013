#ifndef BUTTON_H
#define BUTTON_H

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

private:
	EGEMotor::Input* m_input;
};


#endif