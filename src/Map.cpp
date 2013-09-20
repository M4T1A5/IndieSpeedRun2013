#include <Map.h>

using namespace EGEMath;

Map::Map()
{
	textures["background"] = new Texture("map.png");
	textures["forest"] = new Texture("forest.png");
	textures["swamp"] = new Texture("swamp.png");
	AddElement(MapElements::Background);
}


Map::~Map()
{
	textures.empty();
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
