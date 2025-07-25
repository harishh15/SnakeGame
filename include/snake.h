#ifndef SNAKE_H
#define SNAKE_H

typedef enum{
    LEFT,
    RIGHT,
    UP,
    DOWN
}Direction;

typedef struct{
    int x, y;
}Point;

typedef struct{
    Point body[100];
    int length;
    Direction dir;
}Snake;

void initSnake(Snake* snake);
void moveSnake(Snake* snake);
int checkCollision(const Snake* snake);
void setDirection(Snake* snale, Direction dir);

#endif
