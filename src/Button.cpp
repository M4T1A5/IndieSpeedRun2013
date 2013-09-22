#include <Button.h>

using namespace EGEMath;
using namespace EGEMotor;

GUIButton::GUIButton(Texture* texture, Vector position, Rectangle crop,
		Input* input)
{
	m_input = input;
	setPosition(position);
	SetTexture(texture);
	setTextureRectangle(crop);
}

GUIButton::~GUIButton()
{
}

void GUIButton::SetTexture(Texture* Texture)
{
	//m_texture.loadTexture(TextureName);
	setTexture(Texture);
	//setOriginPoint(5);
	setScale(1,1);
	setColor(255, 255, 255, 150);
	/*m_sprite.setLayer(296);*/
}
void GUIButton::update(float DeltaTime)
{

}

void GUIButton::draw(Viewport& viewport)
{
	viewport.draw(this);
}
bool GUIButton::isPressed()
{
	if(mouseOver())
	{
		//return true;
		if(m_input->isButtonPressed(MouseLeft))
		{
			return true;
		}
	}

	return false;
}

bool GUIButton::mouseOver()
{
	if (Rectangle(getPosition() - getSize()/2, Vector(getSize().x, getSize().y - 25)).contains(m_input->getMousePosition()))
		return true;
	return false;
}