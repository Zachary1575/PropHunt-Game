#include "Game.h"
#include <iostream>

SDL_Texture* playerTex;
SDL_Rect srcRect, destRect;

Game::Game() {					//Game Constructor
	
}


Game::~Game() {					//Game Deconstructor
		
}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {		// Game Init function

	int flags = 0;																//Needed to fill for any flag values in parameters of SDL functions (from library)

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;											//Basically sets flags to fullscreen so u get... fullscreen
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {									//Checks if SDL is initlized before running game
		std::cout << "SDL systems are intilized!" << std::endl;					//Check message for debugging purposes
		window = SDL_CreateWindow(title, x, y, width, height, flags);

		if (window) {
			std::cout << "Window Created!" << std::endl;						//Check message for debugging purposes
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);				//Sets color to white
			std::cout << "Renderer Intilized!" << std::endl;					//Check message for debugging purposes
		} 
		
		isRunning = true;
	} else {
		isRunning = false;														//Stops everything if the checks are not correct.
	}

	SDL_Surface* tmpSurface = IMG_Load("assets/Sitckman.png");					//Texture needs surface, once surface is made, texture dont need it
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);												//Destroys Surface


}

void Game::handleEvents() {		// Game Event Handler
	SDL_Event e;				// Stored SDL_Event in "e"
	SDL_PollEvent(&e);			// Poll event checks what events are pending in a list, references the event, knows where it exactly the event is

	switch (e.type) {			// Using Switch statement helps us find out what type of event this is...
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}

}

void Game::update() {										// Game update function
	count++;
	destRect.h = 64;
	destRect.w = 64;
	destRect.x = count;
	std::cout << count << std::endl;
}

void Game::render() {										// Game render function ****Note*** Background needs to be rendered first as it needs to be layered on top of things
	SDL_RenderClear(renderer);
	//Add stuff to render...
	SDL_RenderCopy(renderer, playerTex, NULL, &destRect);	//Source Rectangle would use entire image, Destination Rectangle asks where to place the texture on screen. 
	SDL_RenderPresent(renderer);							//Pushes Rendered stuff to window
}

void Game::clean() {	//Game Clean function, termination protocol
	SDL_DestroyWindow;
	SDL_DestroyRenderer;
	SDL_QUIT;
}


