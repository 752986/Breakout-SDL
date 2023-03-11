#include <SDL2/SDL.h>
#include "gameobject.h"

class Ball : public GameObject {
private:
    float radius = 10;
    SDL_Color color = {0, 0, 0, 255};
    SDL_FPoint shape[5];
public:
    void draw(SDL_Renderer* renderer) {
        // update vertices
        shape[0] = {x - radius, y};
        shape[1] = {x, y + radius};
        shape[2] = {x + radius, y};
        shape[3] = {x, y - radius};
        shape[4] = {x - radius, y};

        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLinesF(renderer, shape, 5);
    }

    Ball(float radius) {
        this->radius = radius;
    }

    Ball(float radius, SDL_Color color) {
        this->radius = radius;
        this->color = color;
    }
};
