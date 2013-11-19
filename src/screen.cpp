#include <string>
#include <iostream>
#include <signal.h>
#include "SDL.h"

#include "screen.hpp"

namespace rt {

	int screen::initialized = 0;
	SDL_Surface* screen::buffer = NULL;

	static void sigint_handler(int)
	{
		exit(0);
	}

	screen::screen(int width, int height)
	{
		if(initialized == 0) {
			if(SDL_Init( SDL_INIT_VIDEO ) == -1)
			{
				std::cerr << "Cannot initialize SDL : "
					<< SDL_GetError() << std::endl;
				exit(-1);
			}
			signal(SIGINT,sigint_handler);
			data = SDL_SetVideoMode(width, height, 24,
					(SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ANYFORMAT));
			buffer = data;
		} else {
			data = buffer;
		}
		initialized += 1;
	}

	screen::~screen()
	{
		initialized -= 1;
		if(initialized == 0) {
			data = NULL;
			buffer = NULL;
			SDL_Quit();
		}
	}

	bool screen::update()
	{
		if(data != NULL)
			SDL_Flip(data);

		SDL_Event event;
		/* Check for events */
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					return false;
					break;
			}
		}
		return true;
	}

}
