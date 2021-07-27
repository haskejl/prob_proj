#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "common.h"

//Constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

const SDL_Color white = {255, 255, 255, 255};
const SDL_Color black = {0, 0, 0, 255};

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
void draw_solid_text(std::string* str, SDL_Rect* rect, const SDL_Color* col);

//Draw a filled in rectangle
void draw_solid_rect(SDL_Rect* rect);