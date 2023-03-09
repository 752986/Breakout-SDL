#pragma once

#include <SDL2/SDL.h>

class GameObject {
private:
    
public:
    float x, y;
    float vx, vy;
    bool should_delete;

    void update(float delta) {
        x += vx * delta;
        y += vy * delta;
    }

    void draw(SDL_Renderer* renderer) {}

    GameObject() {}
    
    GameObject(float x, float y) {
        this->x = x;
        this->y = y;
    }
};
