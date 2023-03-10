#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <gameobject.h>
#include <ball.h>

#include <vector>

#define WIDTH 810
#define HEIGHT 540

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, NULL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, NULL);

    std::vector<GameObject*> game_objects;
    Ball* ball = new Ball(10);
    ball->x = 100;
    ball->y = 100;
    game_objects.push_back(ball);

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
        SDL_SetRenderDrawColor(renderer, 100, 200, 200, 0);
        SDL_RenderClear(renderer);

        // update everything
        for (int i = 0; i < game_objects.size(); i++) {
            game_objects[i]->update(0.01);
        }

        // draw everything
        for (int i = 0; i < game_objects.size(); i++) {
            game_objects[i]->draw(renderer);
        }

        SDL_RenderPresent(renderer);
    }    
}
