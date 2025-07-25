#ifndef RENDERING_H
#define RENDERING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "snake.h"
#include "fruit.h"

extern SDL_Renderer* renderer;

void drawRect(int x, int y, int r, int g, int b);
void renderText(const char* text, int x, int y, SDL_Color color, SDL_Renderer* renderer, TTF_Font* font);

void renderMenu(SDL_Renderer* renderer, TTF_Font* font);
void renderGameOver(SDL_Renderer* renderer, TTF_Font* font, int score);
void renderGame(SDL_Renderer* renderer, TTF_Font* font, const Snake* snake, const Fruit* fruit, int score);

#endif
