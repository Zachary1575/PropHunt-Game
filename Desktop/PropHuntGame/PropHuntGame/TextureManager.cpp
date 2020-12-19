#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);									//Creates Surface as textures need surface to load
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);				//Implements texture
	SDL_FreeSurface(tempSurface);													//Destroys surface once the texture has been deployed

	return tex;

}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {

	SDL_RenderCopy(Game::renderer, tex, &src, &dest);

}
