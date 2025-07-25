#include <SDL2/SDL.h>
#include <stdlib.h>
#include "game.h"
#include "fruit.h"
#include "snake.h"

#define GRID_WIDTH 32
#define GRID_HEIGHT 24

void initGame(Snake* snake, Fruit* fruit, GameState* state, int* score) {
    initSnake(snake);
    placeFruit(fruit, snake);
    *state = STATE_MENU;
    *score = 0;
}

void handleEvents(GameState* state, Snake* snake, int* gameover) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            *gameover = 1;
        }
        else if (e.type == SDL_KEYDOWN) {
            if (*state == STATE_MENU) {
                if (e.key.keysym.sym == SDLK_RETURN) {
                    *state = STATE_PLAYING;
                }
                else if (e.key.keysym.sym == SDLK_ESCAPE) {
                    *gameover = 1;
                }
            }
            else if (*state == STATE_PLAYING) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT: setDirection(snake, LEFT); break;
                    case SDLK_RIGHT: setDirection(snake, RIGHT); break;
                    case SDLK_UP: setDirection(snake, UP); break;
                    case SDLK_DOWN: setDirection(snake, DOWN); break;
                    case SDLK_ESCAPE: *gameover = 1; break;
                }
            }
            else if (*state == STATE_GAMEOVER) {
                if (e.key.keysym.sym == SDLK_RETURN) {
                    *state = STATE_PLAYING;
                    initSnake(snake);
                }
                else if (e.key.keysym.sym == SDLK_ESCAPE) {
                    *gameover = 1;
                }
            }
        }
    }
}

void updateGame(Snake* snake, Fruit* fruit, GameState* state, int* score) {
    if (*state == STATE_PLAYING) {
        moveSnake(snake);
        if (checkCollision(snake)) {
            *state = STATE_GAMEOVER;
        }
        if (snake->body[0].x == fruit->pos.x && snake->body[0].y == fruit->pos.y) {
            snake->length++;
            if (snake->length > 100) snake->length = 100;
            *score += 10;
            placeFruit(fruit, snake);
        }
    }
}
