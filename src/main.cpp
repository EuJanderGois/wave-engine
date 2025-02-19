#include <iostream>
#include "raylib.h"
#include "schemas/editor_config/editor_config.h"

using namespace std;

int main()
{

    EditorConfig editorConfig("./engine.config.yaml");

    cout << editorConfig.getName() << endl;

    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib basic window");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(editorConfig.getName().c_str(), 20, 20, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}