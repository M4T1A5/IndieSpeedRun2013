#include <Camera.h>
#include <iostream>

using namespace EGEMath;
using namespace EGEMotor;

Camera::Camera(Input& input, Viewport& viewport, Vector mapSize)
	: m_input(&input),
	  m_viewport(&viewport),
	  m_mapSize(mapSize)
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

	//std::cout << "X: " << pos.x << "Y: " << pos.y << std::endl;

	if(pos.x < side)
		pos.x = side;
	else if(pos.x > m_mapSize.x - side)
		pos.x = m_mapSize.x - side;
	if(pos.y < updown)
		pos.y = updown;
	else if(pos.y > m_mapSize.y - updown)
		pos.y = m_mapSize.y - updown;

	m_viewport->setCameraPosition(pos);
}