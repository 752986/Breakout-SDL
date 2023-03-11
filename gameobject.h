#pragma once

#include "SDL2/SDL.h"

class GameObject {
public:
    float x, y = 0.0;
    float vx, vy = 0.0;
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
