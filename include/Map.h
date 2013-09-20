#ifndef MAP_H
#define MAP_H

#include <Sprite.h>
#include <string>

class Map
{
public:
	Map(std::string fileName);
	~Map();
	void LoadMap(std::string fileName);
	void Update();
	void Draw();
	void Addelement(EGEMath::Sprite* sprite);	
private:
	std::vector<EGEMath::Sprite*> sprites;
};

#endif