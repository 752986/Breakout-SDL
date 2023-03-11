#include <SDL2/SDL.h>
#include "gameobject.h"

class Ball : public GameObject {
private:
    float radius;
    SDL_Color color;
public:
    void draw(SDL_Renderer* renderer) {
        SDL_Point points[5] = {
            {x - radius, y},
            {x, y + radius},
            {x + radius, y},
            {x, y - radius},
            {x - radius, y}
        };
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLines(renderer, points, 5);
    }

    Ball(float radius) {
        this->radius = radius;
        this->color = {0, 0, 0, 255};
    }

    Ball(float radius, SDL_Color color) {
        this->radius = radius;
        this->color = color;
    }
};
