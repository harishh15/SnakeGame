#ifndef FRUIT_H
#define FRUIT_H

#include "snake.h"

typedef struct {
    Point pos;
} Fruit;

void placeFruit(Fruit* fruit, const Snake* snake);

#endif
