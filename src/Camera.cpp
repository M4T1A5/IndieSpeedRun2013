#include <Camera.h>

using namespace EGEMath;

Camera::Camera(EGEMath::Input& input, EGEMath::Viewport& viewport)
	: m_input(&input),
	  m_viewport(&viewport)
{
}
Camera::~Camera()
{}

void Camera::FollowMouse(const double& dt)
{
	EGEMath::Vector TowardsMouse = m_viewport->getCameraPosition() +
		((m_input->getMousePositionOnMap()-m_viewport->getCameraPosition()) * dt);
	MoveTo(TowardsMouse);
}
void Camera::MoveTo(Vector pos)
{
	int side	= m_viewport->getWindowSize().x/2;
	int updown	= m_viewport->getWindowSize().y/2;

	if(pos.x < side)
		pos.x = side;
	if(pos.y < updown)
		pos.y = updown;

	/*if(pos.x < right)
		pos.x = right;
	if(pos.y < bottom)
		pos.y = bottom;*/

	m_viewport->setCameraPosition(pos);
}