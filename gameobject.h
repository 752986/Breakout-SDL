#pragma once

#include "SDL2/SDL.h"

class GameObject {
public:
    float x = 0.0, y = 0.0;
    float vx = 0.0, vy = 0.0;
    bool should_delete = false;

    virtual void update(double delta) {
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
