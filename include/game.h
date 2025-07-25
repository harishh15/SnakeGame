#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "fruit.h"

typedef enum { STATE_MENU, STATE_PLAYING, STATE_GAMEOVER } GameState;

void initGame(Snake* snake, Fruit* fruit, GameState* state, int* score);
void handleEvents(GameState* state, Snake* snake, int* gameover);
void updateGame(Snake* snake, Fruit* fruit, GameState* state, int* score);

#endif
