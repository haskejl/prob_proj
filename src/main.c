#include <SDL2/SDL.h>

#include "../include/common.h"
#include "../include/graphics.h"
#include "../include/math_internal.h"
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
	bool mouse_down = false;
	int mouse_x;
	int mouse_y;
	int mouse_last_x;
	int mouse_last_y;

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
	unsigned int n = 500;
	gen_norm_dist_pdf(0.f, 1.f, -5, 5, 500, &std_norm_dist_pdf[0]);
	gen_evenly_spaced_array(n, -5, 5, &pdf_x[0]);

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
					switch(event.key.keysym.scancode) {
						case SDL_SCANCODE_P:
							pause = !pause;
							break;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					switch(event.button.button) {
						case SDL_BUTTON_LEFT:
							mouse_down = true;
							mouse_last_x = event.button.x;
							mouse_last_y = event.button.y;
							break;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					switch(event.button.button) {
						case SDL_BUTTON_LEFT:
							mouse_down = false;
							break;
					}
					break;
				case SDL_MOUSEMOTION:
					mouse_x = event.motion.x;
					mouse_y = event.motion.y;
					break;
			}
		}

		if(!pause)
		{
			//do calculations
			if(mouse_down) {
				if(mouse_x >= graph.x_pos && mouse_x <= graph.x_pos + graph.width && mouse_y >= graph.y_pos & mouse_y <= graph.y_pos + graph.height) {
					graph.x_pos += mouse_x - mouse_last_x;
					graph.y_pos += mouse_y - mouse_last_y;
					recalc_graph_params(&graph);
					mouse_last_x = mouse_x;
					mouse_last_y = mouse_y;
				}
			}
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
