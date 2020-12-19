#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update();					//We want our own update function for the object rather than having the game itself update everything
	void Render();

private:

	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;		//Source Rectangle asks how big the texture, Destination Rectangle asks where to place the texture on screen. 

};