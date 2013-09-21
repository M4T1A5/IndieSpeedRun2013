#ifndef MAPELEMENTS_H
#define MAPELEMENTS_H

enum MapElements;
class MapElement;


#include <GameObject.h>
#include <AnimatedGameObject.h>
#include <Sprite.h>
//#include <Map.h>
#include <string>


enum MapElements
{
	Background, 
	River,
	Forest,
	Swamp,
	Volcano,
	Character,
	MapElementCount
};

class MapElement
{
public:
	MapElement(MapElements Name, EGEMotor::Texture *texture, float AOERadius, 
		float speed, float scale, int Xframes = 1, int Yframes = 1);
	~MapElement();

	MapElements Name;
	EGEMotor::Texture* Texture;
	float Radius;
	float Speed;
	float Scale;
	int framesizeX;
	int framesizeY;
	int frames;


};

class Element : public AnimatedGameObject
{
public:
	Element(EGEMath::Vector Position, MapElement* mapElement);
	~Element();
private:
	MapElement* _mapElement;
};






class Character : public AnimatedGameObject
{
public:
	Character();
	~Character();

};

#endif