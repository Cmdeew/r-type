#include "Map.h"
#include <iostream>

Map::Map()
{
	//InitMap();
}

Map::~Map()
{

}

void	Map::UpdateMap(unsigned char lastX, unsigned char lastY, unsigned char x, unsigned char y, unsigned char id)
{ 
	_map[lastX][lastY] = 0;
	if (_map[x][y] == 0)
		_map[x][y] = id;
	else
		std::cout << "COLISION" << std::endl;
}

void	Map::DisplayCase(unsigned char x, unsigned char y)
{
	std::cout << "Element sur la case : " <<(int)_map[x][y] << std::endl;
}
