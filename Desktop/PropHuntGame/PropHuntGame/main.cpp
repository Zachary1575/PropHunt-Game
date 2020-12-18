#include "Game.h"

Game *game = nullptr;						//Creates a instance of game, also initilizes pointer



int main(int argc, char** argv) {

	const int FPS = 60;								//The Frame we want to cap at
	const int FrameDelay = 1000 / FPS;

	Uint32 framestart;								//This is a massive integer
	int frameTime;

	game = new Game();

	game-> init("YorkEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1440, 900, false);

	while (game->running()) {						//This is our game loop.

		framestart = SDL_GetTicks();				//This is the time in milliseconds from when SDL intilized

		game->handleEvents();
		game->update();
		game->render();
												
		frameTime = SDL_GetTicks() - framestart;
			
		if (FrameDelay > frameTime) {				//If the Game is above 60 FPS, we need to delay the game so the frames can go back down
			SDL_Delay(FrameDelay - frameTime);
		}

	}
	
	game->clean();							//Termiantion protocol

	return 0;
};