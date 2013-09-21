#ifndef CAMERA_H
#define CAMERA_H
#include <Viewport.h>
#include <Input.h>

namespace EGEMotor
{

class Camera
{
public:
	Camera(EGEMotor::Input& input, EGEMotor::Viewport& viewport);
	~Camera();
	void FollowMouse(const double& dt);
	void MoveTo(EGEMath::Vector MapCoordinate);
private:
	Camera(Camera& camera);
	EGEMotor::Input* m_input;
	EGEMotor::Viewport* m_viewport;
};

}


#endif