#include "Map.h"
#include "TextureManager.h"

int Map1[20][25] = {											//This is our Tile Map

	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},		//25 by 20 in space, integers to present space
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},		//This is the Tile Map
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},		
	{0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,0,2,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,2,0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,2,2,2,2,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

};



Map::Map() {

	//Creating the Textures below
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/water.png");

	LoadMap(Map1);

	src.x = src.y = 0;
	src.w = src.h = 32;
	dest.w = dest.h = 32;

	dest.x = dest.y = 0;
}

Map::~Map() {

}

void Map::LoadMap(int arr[20][25]) {

	for (int row = 0; row < 20; row++) {

		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
		}
	}

	
}

void Map::DrawMap() {

	int type = 0;
	for (int row = 0; row < 20; row++) {

		for (int column = 0; column < 25; column++) {
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)										//Different Cases to determine the terrian
			{
			case 0:
				TextureManager::Draw(water, src, dest);			//Water is 0
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);			//Grass is 1
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);			//Dirt is 2
				break;
			default:
				break;
			}
		}
	}

}

