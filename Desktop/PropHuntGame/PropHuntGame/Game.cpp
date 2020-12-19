#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

//Maps
Map* map;

//Game Objects
GameObject* player;
GameObject* enemy;

SDL_Renderer* Game::renderer = nullptr;		//nullptr because SDL has not been intilized yet, it will be reassigned later


Game::Game() {								//Game Constructor
	
}


Game::~Game() {								//Game Deconstructor
		
}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {		// Game Init function

	int flags = 0;																//Needed to fill for any flag values in parameters of SDL functions (from library)

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;											//Basically sets flags to fullscreen so u get... fullscreen
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {									//Checks if SDL is initlized before running game
		std::cout << "SDL systems are Intilized!" << std::endl;					//Check message for debugging purposes
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

	//Place Map Assets below
	map = new Map();

	//Place Game assets below
	player = new GameObject("assets/Sitckman.png", 0, 0);
	enemy = new GameObject("assets/Sitckman.png", 100, 100);

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
	player->Update();
	enemy->Update();
}

void Game::render() {										// Game render function ****Note*** Background needs to be rendered first as it needs to be layered on top of things
	SDL_RenderClear(renderer);
	//Add stuff to render...
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);							//Pushes Rendered stuff to window
}

void Game::clean() {										//Game Clean function, termination protocol
	SDL_DestroyWindow;
	SDL_DestroyRenderer;
	SDL_QUIT;
}


