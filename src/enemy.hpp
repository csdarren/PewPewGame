#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <iostream>

class Enemy
{
public:
    Vector2 pos, size, middlePos;
    int speed;

    Enemy(int speed) : speed(speed)
    {
        pos = {static_cast<float>(GetRandomValue(0, GetScreenWidth() - size.x)), static_cast<float>(GetRandomValue(0, GetScreenHeight() - size.y))};
        size = {32.0f, 32.0f};
    };
    ~Enemy() {};
    void update(Vector2 playerPos, Texture2D model)
    {
        middlePos = Vector2Add(pos, Vector2Scale(size, 0.5f));
        std::cout << "Drawing Enemy Model at x = " << pos.x << " and y = " << pos.y << std::endl
                  << std::endl;
        if (IsTextureValid(model))
            DrawTextureV(model, pos, RAYWHITE);
        // DrawTexturePro(model, Rectangle{0, 0, (float)model.width, (float)model.height}, Rectangle{pos.x, pos.y, (float)model.width, (float)model.height}, middlePos, Vector2Angle(middlePos, playerPos), RAYWHITE);
        else
            std::cout << "Enemy Model invalid" << std::endl;
        pos = Vector2MoveTowards(pos, playerPos, speed * GetFrameTime());
    }
};

#endif