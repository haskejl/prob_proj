#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "common.h"

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
void draw_solid_text(char* str, SDL_Rect* rect, const SDL_Color* col);

//Draw a filled in rectangle
void draw_solid_rect(SDL_Rect* rect);

//Draw a point
void draw_point(int x, int y, int size);

// Graph an object, assumes x_min and y_min are negative
void draw_graph(float x_min, float x_max, float y_min, float y_max, int height, int width, int x_pos, int y_pos, float* x_vals, float* y_vals, int n_vals);

#endif
