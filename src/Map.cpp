#include <Map.h>

using namespace EGEMath;
using namespace EGEMotor;

Map::Map()
{
	riverImage.loadFromFile("assets/joet.png"); // For pixel checking
	size = riverImage.getSize();
	textures["map"] = new Texture("map.png");
	textures["forest"] = new Texture("forest.png");
	textures["swamp"] = new Texture("swamp.png");
	textures["character"] = new Texture("arke_sheet.png");
	textures["volcano"] = new Texture("volcano.png");
	AddElement(MapElements::Background);
	AddElement(MapElements::Volcano,Vector(1250,450));
}


Map::~Map()
{
	textures.empty();
	gameObjects.empty();
}

void Map::Update(const double& dt)
{
	for(size_t i = 0; i < gameObjects.size(); ++i)
	{
		gameObjects[i]->Update(dt);
	}
}

void Map::Draw(Viewport& viewport)
{
	for(size_t i = 0; i < gameObjects.size(); ++i)
	{
		gameObjects[i]->Draw(viewport);
	}
}

void Map::AddElement(MapElements mapElement, Vector pos)
{
	switch(mapElement)
	{
	// Special case
	case MapElements::Background:
		{
		auto gameObject = new GameObject(textures["map"]);
		gameObjects.push_back(gameObject);
		}
		break;
	case MapElements::Forest:
		{
		auto gameObject = new GameObject(textures["forest"]);
		gameObject->SetSpeed(300);
		gameObject->setPosition(Vector(pos.x, pos.y - 200));
		gameObject->SetTarget(pos);
		gameObject->setOriginPoint(5);
		gameObject->setScale(0.7f);
		gameObjects.push_back(gameObject);
		}
		break;
	case MapElements::Swamp:
		{
		auto gameObject = new GameObject(textures["swamp"]);
		gameObject->SetSpeed(300);
		gameObject->setPosition(Vector(pos.x, pos.y - 200));
		gameObject->SetTarget(pos);
		gameObject->setOriginPoint(5);
		gameObject->setScale(1.0f);
		gameObjects.push_back(gameObject);
		}
		break;
	case MapElements::Character:
		{
		auto gameObject = 
			new AnimatedGameObject(textures["character"], 16, 250, 450);
		gameObject->SetSpeed(300);
		gameObject->setPosition(Vector(pos.x, pos.y - 200));
		gameObject->SetTarget(pos);
		gameObject->setOriginPoint(5);
		gameObject->setScale(0.1f);
		gameObjects.push_back(gameObject);
		}
		break;
	case MapElements::Volcano:
		{
		auto gameObject = new GameObject(textures["volcano"]);
		gameObject->setPosition(Vector(pos.x, pos.y - 200));
		gameObject->setOriginPoint(5);
		gameObject->setScale(0.6f);
		gameObjects.push_back(gameObject);
		}
		break;
	}
}

sf::Color Map::GetPixel(Vector pos)
{
	return riverImage.getPixel(pos.x, pos.y);
}
