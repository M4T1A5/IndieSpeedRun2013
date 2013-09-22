#include <Map.h>

using namespace EGEMath;
using namespace EGEMotor;

Map::Map()
{
	_mapElements.resize(MapElementCount);
	riverImage.loadFromFile("assets/joet.png"); // For pixel checking
	size = riverImage.getSize();
	textures["map"] = new Texture("map.png");
	textures["river"] = new Texture("joet.png");
	textures["forest"] = new Texture("forest.png");
	textures["swamp"] = new Texture("swamp.png");
	//textures["character"] = new Texture("arke_sheet.png");
	textures["volcano"] = new Texture("volcano.png");
	CreateMapElements();
	AddElement(MapElements::Background);
	AddElement(MapElements::Volcano,Vector(1800,450));
}


Map::~Map()
{
	textures.empty();
	_mapElements.empty();
	_mapElementList.empty();
}

void Map::Update(const double& dt)
{
	for(size_t i = 0; i < _mapElements.size(); ++i)
	{
		for(size_t j = 0; j < _mapElements[i].size(); ++j)
		{
			_mapElements[i][j]->Update(dt);
		}
	}
}

void Map::Draw(Viewport& viewport)
{
	for(size_t i = 0; i < _mapElements.size(); ++i)
	{
		for(size_t j = 0; j < _mapElements[i].size(); ++j)
		{
			_mapElements[i][j]->Draw(viewport);
		}
	}
}

void Map::AddElement(MapElements mapElement, Vector pos)
{
	Element* element;
	switch(mapElement)
	{
	// Special case
	case MapElements::Background:
		element = new Element(Vector(),_mapElementList[Background]);
		break;
	case MapElements::River:
		element = new Element(Vector(),_mapElementList[River]);
		break;
	case MapElements::Forest:
		element = new Element(pos,_mapElementList[Forest]);
		break;
	case MapElements::Swamp:
		element = new Element(pos,_mapElementList[Swamp]);
		break;
	case MapElements::Volcano:
		element = new Element(pos,_mapElementList[Volcano]);
		break;
	//case MapElements::Character:
	//	element = new Element(pos,_mapElementList[Character]);
	//	break;
	}
	_mapElements[mapElement].push_back(element);
}

sf::Color Map::GetPixel(Vector pos)
{
	return riverImage.getPixel(pos.x, pos.y);
}

void Map::CreateMapElements()
{
	_mapElementList.push_back(new MapElement(MapElements::Background,textures["map"],		
		0, 0, 1.0f));
	_mapElementList.push_back(new MapElement(MapElements::River,textures["river"],		
		0, 0, 1.0f));
	_mapElementList.push_back(new MapElement(MapElements::Forest, textures["forest"],		
		60, 300, 0.6f));
	_mapElementList.push_back(new MapElement(MapElements::Swamp, textures["swamp"],	
		50, 300, 1.0f,2,1,1));
	_mapElementList.push_back(new MapElement(MapElements::Volcano, textures["volcano"],	
		0, 0, 1.0f, 4, 1, 3));

	//_mapElementList.push_back(new MapElement(MapElements::Character, textures["character"],
	//	5, 150, 0.5f, 4, 4, 12));
}
