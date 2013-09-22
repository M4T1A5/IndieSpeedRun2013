#include <Village.h>

using namespace EGEMath;
using namespace EGEMotor;

Village::Village(Texture* texture, Vector position)
	: GameObject(texture),
	  Clock(0),
	  NextVillager(0)
{
	setPosition(position);
	setScale(2.0f);
	setOriginPoint(2);
	setLayer(CountLayer(position.y - 70)); // layer offset -20
}
Village::~Village()
{}


void Village::Update(float dt)
{
	GameObject::Update(dt);
	Clock += dt;
}
void Village::Draw(EGEMotor::Viewport& viewport)
{
	GameObject::Draw(viewport);
}

