#include <SDL2/SDL.h>

#include "../include/common.h"
#include "../include/graphics.h"

int main(int argc, char* args[])
{
	std::cout << "Started...\n";
	if(initialize_gfx() < 0)
	{
		printf("Application Failed to Initalize!");
		return -1;
	}

	//Just handle events within the main loop, it makes more sense
	SDL_Event event;

	bool quit = false;
	bool pause = false;
	//init_falling_sq_sim();
	std::string line;

	while(!quit)
	{
		while(SDL_PollEvent(&event) != NULL)
		{
			switch(event.type)
			{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					if(event.key.keysym.scancode == SDL_SCANCODE_P)
						pause = !pause;
			}
		}

		if(!pause)
		{
			//do calculations
			clear_screen();
			
			//send stuff to renderer
			
			display_renderer();
		}
		else SDL_Delay(100);
	}

	shutdown_gfx();
	return 0;
}
