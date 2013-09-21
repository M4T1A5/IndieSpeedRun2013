#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <EGEMath/Vector.h>
#include <Sprite.h>
#include <Viewport.h>
#include <string>

class Map
{
public:
	enum MapElements
	{
		Background, // Actual Map
		Forest,
		Swamp
	};

	Map();
	~Map();
	//void LoadMap(std::string fileName);
	void Update();
	void Draw(EGEMath::Viewport& viewport);
	void AddElement(MapElements mapElement);
	sf::Color GetPixel(EGEMath::Vector pos);
private:
	sf::Image mapImage;
	std::vector<EGEMath::Sprite*> sprites;
	std::map<std::string, EGEMath::Texture*> textures;

	EGEMath::Vector size;
};

#endif