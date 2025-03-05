#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include "assets/audio.hpp"

class Projectile
{
public:
    int speed;
    Vector2 size, pos, middlePos, mousePos;
    bool isActive;

    Projectile(Vector2 startingPos, float width, float height, int speed) : speed(speed), isActive(true)
    {
        if (IsSoundValid(Pew))
            PlaySound(Pew);
        size = {width, height};
        pos = startingPos;
    };
    ~Projectile() {};

    void update(Texture2D model)
    {
        middlePos = Vector2Add(pos, Vector2Scale(size, 0.5f));
        if (IsTextureValid(model))
            DrawTextureV(model, pos, RAYWHITE);
        else
            std::cout << "Bullet Model invalid" << std::endl;
        pos = Vector2MoveTowards(pos, mousePos, speed * GetFrameTime()); // Handle projectile movement
    };
};

#endif