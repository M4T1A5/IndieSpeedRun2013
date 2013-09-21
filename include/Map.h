#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <EGEMath/Vector.h>
#include <Sprite.h>
#include <Viewport.h>
#include <GameObject.h>
#include <AnimatedGameObject.h>
#include <string>

class Map
{
public:
	enum MapElements
	{
		Background, // Actual Map
		Forest,
		Swamp,
		Character
	};

	Map();
	~Map();
	//void LoadMap(std::string fileName);
	void Update(const double& dt);
	void Draw(EGEMotor::Viewport& viewport);
	void AddElement(MapElements mapElement, EGEMath::Vector pos = EGEMath::Vector());
	sf::Color GetPixel(EGEMath::Vector pos);
private:
	sf::Image riverImage;
	std::vector<GameObject*> gameObjects;
	std::map<std::string, EGEMotor::Texture*> textures;

	EGEMath::Vector size;
};

#endif