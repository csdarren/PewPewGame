#include "Master.h"

int main()
{
    const Vector2 screenSize{1280, 720};

    InitWindow(screenSize.x, screenSize.y, "PewPewGame");

    Texture2D randomModel = LoadTexture("C:/Users/break/Pictures/zombiehand1.png");
    Texture2D BulletModel = LoadTexture("C:/dev/CPP/PewPewGame/src/assets/textures/projectile.png");
    Texture2D PlayerModel = LoadTexture("C:/dev/CPP/PewPewGame/src/assets/textures/player.png");
    Texture2D EnemyModel = LoadTexture("C:/dev/CPP/PewPewGame/src/assets/textures/zombie.png");
    Texture2D CursorClickModel = LoadTexture("C:/dev/CPP/PewPewGame/src/assets/textures/skele_cursor_click.png");
    Texture2D CursorHoverModel = LoadTexture("C:/dev/CPP/PewPewGame/src/assets/textures/skele_cursor_hover.png");

    InitAudioDevice();
    if (!IsAudioDeviceReady())
        std::cout << "Audio device is not ready/n";

    SetTargetFPS(60);
    HideCursor();

    Player player(5);
    Enemy enemy(200);

    std::vector<Projectile> projectiles;

    while (!WindowShouldClose())
    {
        Vector2 immediateMousePos = GetMousePosition(); // Gather the mouse position each frame
        BeginDrawing();
        player.update(PlayerModel);           // Handle player updates
        enemy.update(player.pos, EnemyModel); // Handle enemy updates
        if (IsCursorOnScreen())
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                DrawTextureV(CursorClickModel, immediateMousePos, RAYWHITE);
            else
                DrawTextureV(CursorHoverModel, immediateMousePos, RAYWHITE);
        }

        if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) // When Mouse Button Pressed
        {
            Projectile projectile(player.middlePos, 10, 10, 800); // Creates Projectile
            projectiles.push_back(projectile);
        }

        for (int i = 0; i < projectiles.size(); i++)
            if (projectiles[i].isActive)
            {
                {
                    projectiles[i].update(BulletModel);
                    if (projectiles[i].pos == projectiles[i].mousePos)
                    {
                        projectiles[i].isActive = false;
                    }
                }
            }
        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    CloseWindow();
}