#include <stdlib.h>
#include "fruit.h"

#define GRID_WIDTH 32
#define GRID_HEIGHT 24

void placeFruit(Fruit* fruit, const Snake* snake) {
    int valid = 0;
    while (!valid) {
        fruit->pos.x = rand() % GRID_WIDTH;
        fruit->pos.y = rand() % GRID_HEIGHT;
        valid = 1;
        for (int i = 0; i < snake->length; i++) {
            if (fruit->pos.x == snake->body[i].x && fruit->pos.y == snake->body[i].y) {
                valid = 0;
                break;
            }
        }
    }
}
