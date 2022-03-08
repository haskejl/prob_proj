#include <SDL2/SDL.h>

#include "../include/common.h"
#include "../include/distributions.h"
#include "../include/graphics.h"
#include "../include/math_internal.h"
#include "../include/math_models.h"

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

	// A rectangle & char array for drawing text
	SDL_Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.w = 200;
	rect.h = 25;
	char c[50];

	// Setup the graph
	struct Graph graph;
	graph.x_max = 50;
	graph.x_min = -1;
	graph.y_max = 10;
	graph.y_min = -10;
	graph.x_pos = 100;
	graph.y_pos = 100;
	graph.width = 800;
	graph.height = 500;
	recalc_graph_params(&graph);

	// Make something to graph
	const unsigned int n = 100;
	float random_walk[n];
	float t[n];
	unsigned int cur_pos = 0;
	int wait = 3;
	float C = 1;
	float mu = 0.1;
	gen_evenly_spaced_array(0, 50, n, &t[0]);
	gen_rand_walk(mu, C, n, &t[0], &random_walk[0]);

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
						case SDL_SCANCODE_A:
							mu -= 0.01;
							break;
						case SDL_SCANCODE_P:
							pause = !pause;
							break;
						case SDL_SCANCODE_S:
							C -= 0.01;
							break;
						case SDL_SCANCODE_Q:
							mu += 0.01;
							break;
						case SDL_SCANCODE_W:
							C += 0.01;
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
			if(wait-- <= 0) {
				wait = 3;
				if(cur_pos++ >= n && wait){
					gen_rand_walk(mu, C, n, &t[0], &random_walk[0]);
					cur_pos=0;
				}
			}
			
			clear_screen();
			
			//send stuff to renderer
			draw_line_graph(graph, &t[0], &random_walk[0], cur_pos);
			rect.y = 100;
			sprintf(c, "mu: %f", mu);
			draw_solid_text(c, &rect, &white);
			rect.y += rect.h;
			sprintf(c, "C:  %f", C);
			draw_solid_text(c, &rect, &white);
			display_renderer();
		}
		else SDL_Delay(100);
	}

	shutdown_gfx();
	return 0;
}
