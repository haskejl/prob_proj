#include "../include/graphics.h"

//assign constants values
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

const SDL_Color white = {255, 255, 255, 255};
const SDL_Color black = {0, 0, 0, 255};

//Start external graphics libraries central to the program, return 0 if all are successfully started
int initialize_gfx()
{
    printf("Initializing video...\n");
	int ret_val = SDL_Init(SDL_INIT_VIDEO);
	if(ret_val < 0)
	{
		printf("SDL failed to initialize! %s\n", SDL_GetError());
		return ret_val;
	}
	
    printf("Initializing TTF...\n");
	if(TTF_Init() < 0)
	{
		printf("TTF failed to initialize!: %s\n", TTF_GetError());
		return -1;
	}
	
	window = SDL_CreateWindow("Probability App", 0,0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		printf("SDL failed to create window! %s\n", SDL_GetError());
		return -1;
	}

	surface = SDL_GetWindowSurface(window);
	if(surface == NULL)
    {
        printf("Surface failed to create: %s\n", SDL_GetError());
        return -1;
    }

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL)
    {
        printf("Renderer failed to create: %s\n", SDL_GetError());
        return -1;
    }

	font = TTF_OpenFont("./fonts/PlayfairDisplayRegular.ttf", 24);
	if(font == NULL)
    {
        printf("ERROR: Could not load font!");
        return -1;
    }
	
	return 0;
}

void clear_screen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
			
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void display_renderer()
{
    SDL_RenderPresent(renderer);
}

//Quit any started graphics libraries
void shutdown_gfx()
{
	TTF_Quit();
	SDL_Quit();
}

//Draw text using the TTF_RenderUTF8_Solid method
void draw_solid_text(char* str, SDL_Rect* rect, const SDL_Color* col)
{
	surface = TTF_RenderUTF8_Solid(font, str, *col);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &rect->w, &rect->h);
	SDL_RenderCopy(renderer, texture, NULL, rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

//Draw a filled in rectangle
void draw_solid_rect(SDL_Rect* rect)
{
	SDL_RenderDrawRect(renderer, rect);
	SDL_RenderFillRect(renderer, rect);
}

// Draw a point
// void draw_point(int x, int y);
void draw_point(int x, int y, int size) {
	SDL_Rect pt;
	pt.x = x;
	pt.y = y;
	pt.w = size;
	pt.h = size;

	SDL_RenderDrawRect(renderer, &pt);
	SDL_RenderFillRect(renderer, &pt);
}

// Graph an object, assumes x_min and y_min are negative
void draw_graph(struct Graph g, float* x_vals, float* y_vals, int n_vals) {
	
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	// X-axis
	SDL_RenderDrawLine(renderer, g.x_pos, g.y_offset, g.x_pos+g.width, g.y_offset);
	// Y-axis
	SDL_RenderDrawLine(renderer, g.x_offset, g.y_pos, g.x_offset, g.y_pos+g.height);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	for(int i=0; i<n_vals; i++) {
		int x = (int)(g.x_offset+x_vals[i]/g.x_scale);
		int y = (int)(g.y_offset-y_vals[i]/g.y_scale);
		draw_point(x, y, 1);
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void recalc_graph_params(struct Graph* g) {
	g->x_offset = g->x_pos+(int)(g->x_min/(g->x_min-g->x_max)*g->width);
	g->y_offset = g->y_pos+g->height-(int)(g->y_min/(g->y_min-g->y_max)*g->height);
	g->x_scale = (float)(g->x_max-g->x_min)/g->width;
	g->y_scale = (float)(g->y_max-g->y_min)/g->height;
}