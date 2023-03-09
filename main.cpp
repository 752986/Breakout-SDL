#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#define WIDTH 810
#define HEIGHT 540

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, NULL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, NULL);

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        
        SDL_SetRenderDrawColor(renderer, 100, 200, 200, 0);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }    
}
