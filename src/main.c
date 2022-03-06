#include <SDL2/SDL.h>

#include "../include/common.h"
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

	// Setup the graph
	struct Graph graph;
	graph.x_max = 5;
	graph.x_min = -5;
	graph.y_max = 0.5;
	graph.y_min = -0.1;
	graph.x_pos = 100;
	graph.y_pos = 100;
	graph.width = 400;
	graph.height = 400;
	recalc_graph_params(&graph);

	// Make something to graph
	float std_norm_dist_pdf[500];
	float pdf_x[500];
	gen_norm_dist_pdf(0.f, 1.f, -5, 5, 500, &std_norm_dist_pdf[0]);
	float inc = 10.f/500.f;
	for(int i=0; i<500; i++) {
		pdf_x[i] = i*inc-5;
	}

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
			draw_graph(graph, &pdf_x[0], &std_norm_dist_pdf[0], 500);
			display_renderer();
		}
		else SDL_Delay(100);
	}

	shutdown_gfx();
	return 0;
}
