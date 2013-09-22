#include <MapElements.h>


MapElement::MapElement(MapElements name, EGEMotor::Texture *texture,
		float AOERadius, float speed, float scale, int Xframes, int Yframes, float fps)
	: Radius(AOERadius),
	  Name(name),
	  Texture(texture),
	  Speed(speed),
	  Scale(scale),
	  FPS(fps)
{
	framesizeX = texture->getTextureSize().x / Xframes;
	framesizeY = texture->getTextureSize().y / Yframes;
	frames = Xframes*Yframes;
}
MapElement::~MapElement()
{}



Element::Element(EGEMath::Vector Position, MapElement* mapElement)
	: AnimatedGameObject(mapElement->Texture,mapElement->frames, 
	mapElement->framesizeX, mapElement->framesizeY, mapElement->FPS+rand()%2000/1000.0f),
	  _mapElement(mapElement)
{
	SetSpeed(mapElement->Speed);
	setPosition(Position);
	SetTarget(Position);
	setScale(mapElement->Scale);

	if (mapElement->Name != Background && mapElement->Name != River)
	{
		setOriginPoint(5);
	}

}
Element::~Element(){}