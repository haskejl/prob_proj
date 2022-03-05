#include <SDL2/SDL.h>

#include "../include/common.h"
#include "../include/finite_difference_methods.h"
#include "../include/graphics.h"
#include "../include/distributions.h"

int main(int argc, char* args[])
{
	printf("Started...\n");
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

	//double std_norm_dist_pdf[1000];
	//gen_norm_dist_pdf(0.f, 1.f, &std_norm_dist_pdf[0]);
	int loc = 0;
	/*for(int i=0; i<100; i++)
	{
		for(int j=0; j<10; j++)
		{
			printf("%f  ", std_norm_dist_pdf[loc++]);
		}
		printf("\n");
	}*/

	explicit_finite_diff_method(1);

	while(!quit)
	{
		while(SDL_PollEvent(&event))
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
			//printf("%f\n", gen_norm_dist_rn(0.f,1.f));
			clear_screen();
			
			//send stuff to renderer
			draw_point(10, 10);
			
			display_renderer();
		}
		else SDL_Delay(100);
	}

	shutdown_gfx();
	return 0;
}
