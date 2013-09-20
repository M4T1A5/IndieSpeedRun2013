#include <Map.h>

using namespace EGEMath;

Map::Map()
{
	textures["background"] = new Texture("map.png");
	textures["forest"] = new Texture("forest.png");
	textures["swamp"] = new Texture("swamp.png");
}


Map::~Map()
{
	textures.empty();
}

void Map::LoadMap(std::string fileName)
{
	Addelement(MapElements::Background);
}

void Map::Update()
{

}

void Map::Draw()
{

}

void Map::Addelement(MapElements mapElement)
{
	std::string elementName;
	switch(mapElement)
	{
	case MapElements::Background:
		elementName = "background";
		break;
	case MapElements::Forest:
		elementName = "forest";
		break;
	case MapElements::Swamp:
		elementName = "swamp";
		break;
	}
	sprites.push_back(new Sprite(textures[elementName]));
}
