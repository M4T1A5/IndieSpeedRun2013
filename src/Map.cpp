#include <Map.h>

using namespace EGEMath;

Map::Map()
{
	textures["map"] = new Texture("map.png");
	textures["forest"] = new Texture("forest.png");
	textures["swamp"] = new Texture("swamp.png");
	AddElement(MapElements::Background);
}


Map::~Map()
{
	textures.empty();
	sprites.empty();
}

void Map::Update()
{

}

void Map::Draw(Viewport& viewport)
{
	for(size_t i = 0; i < sprites.size(); ++i)
	{
		viewport.draw(sprites[i]);
	}
}

void Map::AddElement(MapElements mapElement)
{
	std::string elementName;
	switch(mapElement)
	{
	// Special case
	case MapElements::Background:
		{
		Sprite* map = new Sprite(textures["map"]);
		size = map->getTextureSize();
		sprites.push_back(map);
		}
		break;
	case MapElements::Forest:
		elementName = "forest";
		break;
	case MapElements::Swamp:
		elementName = "swamp";
		break;
	}
	if(elementName != "")
		sprites.push_back(new Sprite(textures[elementName]));
}
