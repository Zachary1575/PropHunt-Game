#ifndef Game_h
#define Game_h
#include<SDL.h>				//This includes the SDL Library.
#include<SDL_image.h>		//This includes the SDL Image Library
#include<stdio.h>

class Game {
public:
	Game();					//Constructor for loading the game
	~Game();				//Deconstructor for termianting program

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);		//initilize some variables
	void handleEvents();	//Self explanatory
	void update();			//Updates the game objects
	void render();			//Renders objects
	void clean();			//Memory managment like clearing cache

	bool running() { return isRunning; }		

private:
	int count;
	bool isRunning;
	SDL_Window * window;
	SDL_Renderer* renderer;

};


#endif //!Game_h

