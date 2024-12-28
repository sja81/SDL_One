#include <string>
#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Window* gw = NULL;
	SDL_Surface* gs = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
		return -1;
	} 

	gw = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (gw == NULL) {
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
		return -1;
	}

	gs = SDL_GetWindowSurface(gw);
	
	SDL_Event ev;

	bool quit{ false };
	while (quit == false) {
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	return 0;
}