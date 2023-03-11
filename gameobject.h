#pragma once

#include "SDL2/SDL.h"

class GameObject {
public:
    float x, y;
    float vx, vy;
    bool should_delete = false;

    virtual void update(float delta) {
        x += vx * delta;
        y += vy * delta;
    }

    virtual void draw(SDL_Renderer* renderer) {}

    GameObject() {}
    
    GameObject(float x, float y) {
        this->x = x;
        this->y = y;
    }
};
