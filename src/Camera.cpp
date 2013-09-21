#include <Camera.h>

using namespace EGEMath;

Camera::Camera(EGEMath::Input& input, EGEMath::Viewport& viewport)
	: m_input(&input),
	  m_viewport(&viewport)
{
}
Camera::~Camera()
{}

void Camera::FollowMouse()
{
	EGEMath::Vector TowardsMouse = m_viewport->getCameraPosition() +
		((m_input->getMousePositionOnMap()-m_viewport->getCameraPosition()) * 0.001f);
	MoveTo(TowardsMouse);
}
void Camera::MoveTo(Vector Pos)
{
	m_viewport->setCameraPosition(Pos);
}