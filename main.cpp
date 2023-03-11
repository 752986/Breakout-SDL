#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"

#include "gameobject.h"
#include "ball.h"

#include <vector>
#include <stdio.h>

#define WIDTH 810
#define HEIGHT 540

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    std::vector<GameObject*> game_objects;
    Ball* ball = new Ball(5);
    ball->x = 100;
    ball->y = 100;
    game_objects.push_back(ball);

    Uint64 prev_time = 0;
    double delta = 0;

    bool running = true;
    while (running) {
        // poll events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        
        // clear the screen
        SDL_SetRenderDrawColor(renderer, 50, 70, 100, 255);
        SDL_RenderClear(renderer);

        // update everything
        for (GameObject* object : game_objects) {
            object->update(delta);
        }

        // draw everything
        for (GameObject* object : game_objects) {
            object->draw(renderer);
        }

        SDL_RenderPresent(renderer);

        delta = (SDL_GetTicks64() - prev_time) / 1000.0;
        prev_time = SDL_GetTicks64();

        printf("%lf\n", delta);
    }    
}
