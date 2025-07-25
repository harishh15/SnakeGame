#include"snake.h"

void initSnake(Snake* snake){
    snake->length = 3;
    snake->dir = RIGHT;
    snake->body[0].x = 20;
    snake->body[0].y = 12;
    snake->body[1].x = snake->body[0].x - 1;
    snake->body[1].y = snake->body[0].y;
    snake->body[2].x = snake->body[1].x - 1;
    snake->body[2].y = snake->body[1].y;
}

void moveSnake(Snake* snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    switch (snake->dir) {
        case LEFT:  snake->body[0].x--; break;
        case RIGHT: snake->body[0].x++; break;
        case UP:    snake->body[0].y--; break;
        case DOWN:  snake->body[0].y++; break;
    }
}

int checkCollision(const Snake* snake) {
    Point head = snake->body[0];
    if (head.x < 0 || head.x >= 32 || head.y < 0 || head.y >= 24) // grid hardcoded here
        return 1;

    for (int i = 1; i < snake->length; i++) {
        if (head.x == snake->body[i].x && head.y == snake->body[i].y)
            return 1;
    }
    return 0;
}

void setDirection(Snake* snake, Direction dir) {
    if ((dir == LEFT && snake->dir != RIGHT) ||
        (dir == RIGHT && snake->dir != LEFT) ||
        (dir == UP && snake->dir != DOWN) ||
        (dir == DOWN && snake->dir != UP)) {
        snake->dir = dir;
    }
}
