#ifndef MAP_H
#define MAP_H

#include <Sprite.h>
#include <string>

class Map
{
public:
	enum MapElements
	{
		Background,
		Forest,
		Swamp
	};

	Map();
	~Map();
	void LoadMap(std::string fileName);
	void Update();
	void Draw();
	void Addelement(MapElements mapElement);	
private:
	std::vector<EGEMath::Sprite*> sprites;
	std::map<std::string, EGEMath::Texture*> textures;
};

#endif