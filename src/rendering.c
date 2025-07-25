#include "rendering.h"
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

void drawRect(int x, int y, int r, int g, int b) {
    SDL_Rect rect = { x * 20, y * 20, 20, 20 };
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void renderText(const char* text, int x, int y, SDL_Color color, SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if (!surface) {
        printf("TTF_RenderText_Solid error: %s\n", TTF_GetError());
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        printf("SDL_CreateTextureFromSurface error: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }
    SDL_Rect dstrect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void renderMenu(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Color white = {255, 255, 255, 255};
    renderText("Welcome to SDL2 Snake Game!", 100, 150, white, renderer, font);
    renderText("Use Arrow Keys to Move", 180, 200, white, renderer, font);
    renderText("Press Enter to Start", 200, 250, white, renderer, font);
    renderText("Press ESC to Quit", 220, 300, white, renderer, font);

    SDL_RenderPresent(renderer);
}

void renderGameOver(SDL_Renderer* renderer, TTF_Font* font, int score) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Color red = {255, 50, 50, 255};
    SDL_Color white = {255, 255, 255, 255};

    renderText("GAME OVER!", 250, 150, red, renderer, font);

    char scoreText[50];
    snprintf(scoreText, sizeof(scoreText), "Final Score: %d", score);
    renderText(scoreText, 240, 200, white, renderer, font);

    renderText("Press Enter to Restart", 190, 250, white, renderer, font);
    renderText("Press ESC to Quit", 220, 300, white, renderer, font);

    SDL_RenderPresent(renderer);
}

void renderGame(SDL_Renderer* renderer, TTF_Font* font, const Snake* snake, const Fruit* fruit, int score) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    drawRect(fruit->pos.x, fruit->pos.y, 255, 0, 0);

    for (int i = 0; i < snake->length; i++) {
        drawRect(snake->body[i].x, snake->body[i].y, 0, 255, 0);
    }

    char scoreText[50];
    snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
    renderText(scoreText, 10, 10, (SDL_Color){255, 255, 255, 255}, renderer, font);

    SDL_RenderPresent(renderer);
}
