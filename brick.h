#include <SDL2/SDL.h>
#include <gameobject.h>

class Ball : GameObject {
private:
    float radius;
    SDL_Color color;
public:
    void draw(SDL_Renderer* renderer) {
        SDL_Point points[4] = {
            {x - radius, y},
            {x, y + radius},
            {x + radius, y},
            {x, y - radius}
        };
        SDL_SetRenderDrawColor(renderer, color.r, color.b, color.g, color.a);
        SDL_RenderDrawLines(renderer, points, 4);
    }

    Ball(float radius) {
        this->radius = radius;
    }

    Ball(float radius, SDL_Color color) {
        this->radius = radius;
        this->color = color;
    }
};
