#include <Map.h>

using namespace EGEMath;
using namespace EGEMotor;

Map::Map()
{
	mapImage.loadFromFile("assets/map.png"); // For pixel checking
	size = mapImage.getSize();
	textures["map"] = new Texture("map.png");
	textures["forest"] = new Texture("forest.png");
	textures["swamp"] = new Texture("swamp.png");
	AddElement(MapElements::Background);
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
	std::string elementName;
	switch(mapElement)
	{
	// Special case
	case MapElements::Background:
		elementName = "map";
		break;
	case MapElements::Forest:
		elementName = "forest";
		break;
	case MapElements::Swamp:
		elementName = "swamp";
		break;
	}

	auto gameObject = new GameObject(textures[elementName]);
	if(elementName != "map")
	{
		// Add a new gameobject with correct texture		
		gameObject->SetSpeed(300);
		gameObject->SetPosition(Vector(pos.x, pos.y - 200));
		gameObject->SetTarget(pos);
		gameObject->SetOriginPoint(5);
	}
	gameObjects.push_back(gameObject);
}

sf::Color Map::GetPixel(Vector pos)
{
	return mapImage.getPixel(pos.x, pos.y);
}
