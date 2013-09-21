#ifndef CAMERA_H
#define CAMERA_H
#include <Viewport.h>
#include <Input.h>

namespace EGEMath
{

class Camera
{
public:
	Camera(EGEMath::Input& input, EGEMath::Viewport& viewport);
	~Camera();
	void FollowMouse(const double& dt);
	void MoveTo(EGEMath::Vector MapCoordinate);
private:
	Camera(Camera& camera);
	EGEMath::Input* m_input;
	EGEMath::Viewport* m_viewport;
};

}


#endif