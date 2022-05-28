/*
 * main.cpp
 */

#include "Window.h"

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Window w {1280, 920};

	w.main_loop();

	return 0;
}


