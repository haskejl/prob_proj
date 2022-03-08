#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "common.h"
//Structs
struct Graph {
    float x_min, x_max, y_min, y_max, x_offset, y_offset, x_scale, y_scale;
    int x_pos, y_pos, width, height;
};
//Constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern const SDL_Color white;
extern const SDL_Color black;

static SDL_Window* window = NULL;
static SDL_Surface* surface = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Texture* texture = NULL;
static TTF_Font* font = NULL;

//Start external graphics libraries central to the program, return 0 if all are successfully started
int initialize_gfx();

void clear_screen();
void display_renderer();

//Quit any started graphics libraries
void shutdown_gfx();

//Draw text using the TTF_RenderUTF8_Solid method
void draw_solid_text(const char* str, SDL_Rect* rect, const SDL_Color* col);

//Draw a filled in rectangle
void draw_solid_rect(const SDL_Rect* rect, const int r, const int g, const int b, const int a);

//Draw a point
void draw_point(const int x, const int y, const int size, const int r, const int g, const int b, const int a);

// Graph an object, assumes x_min and y_min are negative
void draw_graph(const struct Graph g, const float* x_vals, const float* y_vals, const int n_vals);
void draw_line_graph(const struct Graph g, const float* x_vals, const float* y_vals, const int n_vals);

void recalc_graph_params(struct Graph* g);

#endif
