#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texturesheet, int x, int y) {

	objTexture = TextureManager::LoadTexture(texturesheet);						//We create the object
	
	xpos = x;																			//Starting positions of x and y coords
	ypos = y;
}

GameObject::~GameObject() {

}

void GameObject::Update() {

	xpos++;
	ypos++;

	srcRect.h = 64;						//Source Rectangle asks how big the texture, Destination Rectangle asks where to place the texture on screen. 
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);

}
