#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>

class Player
{
public:
    Vector2 pos, size, middlePos;
    int speed;

    Player(int speed) : speed(speed)
    {
        pos = {static_cast<float>(GetRandomValue(0, GetScreenWidth() - size.x)), static_cast<float>(GetRandomValue(0, GetScreenHeight() - size.y))};
        size = {32.0f, 32.0f};
    };
    ~Player() {};

    void handleMovement()
    {
        if (IsKeyDown(KEY_W))
        {
            if (pos.y > 0)
                pos.y -= speed;
        }
        if (IsKeyDown(KEY_S))
        {
            if (pos.y < GetScreenHeight() - size.y)
                pos.y += speed;
        }
        if (IsKeyDown(KEY_A))
        {
            if (pos.x > 0)
                pos.x -= speed;
        }
        if (IsKeyDown(KEY_D))
        {
            if (pos.x < GetScreenWidth() - size.x)
                pos.x += speed;
        }
    }

    void update(Texture2D model)
    {
        middlePos = Vector2Add(pos, Vector2Scale(size, 0.5f));
        std::cout << "Drawing Player Model at x = " << pos.x << " and y = " << pos.y << std::endl;
        if (IsTextureValid(model))
            DrawTextureV(model, pos, RAYWHITE);
        // DrawTexturePro(model, Rectangle{500, 500, (float)model.width, (float)model.height}, Rectangle{pos.x, pos.y, (float)model.width, (float)model.height}, middlePos, Vector2Angle(middlePos, GetMousePosition()), RAYWHITE); // Player Model
        else
            std::cout << "Player Model invalid" << std::endl;
        handleMovement();
    }
};

#endif