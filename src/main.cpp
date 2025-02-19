#include <iostream>
#include "yaml-cpp/yaml.h"
#include "raylib.h"

using namespace std;

int main()
{
    YAML::Node config = YAML::LoadFile("styles/config.yaml");

    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib basic window");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(config["message"].as<string>().c_str(), 20, 20, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}