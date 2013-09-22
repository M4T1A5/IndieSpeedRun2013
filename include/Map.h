#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <EGEMath/Vector.h>
#include <Sprite.h>
#include <Viewport.h>
#include <GameObject.h>
#include <AnimatedGameObject.h>
#include <string>
#include <MapElements.h>

class Map
{
public:

	Map();
	~Map();
	//void LoadMap(std::string fileName);
	void Update(const double& dt);
	void Draw(EGEMotor::Viewport& viewport);

	void AddElement(MapElements mapElement, EGEMath::Vector pos = EGEMath::Vector());

	sf::Color GetPixel(EGEMath::Vector pos);

	EGEMath::Vector GetSize() { return size; }

	void Reset();
private:
	sf::Image riverImage;
	std::vector<std::vector<Element*>> _mapElements;
	std::map<std::string, EGEMotor::Texture*> textures;

	void CreateMapElements();

	EGEMath::Vector size;
	std::vector<MapElement*> _mapElementList;
	friend class Game;
};

#endif