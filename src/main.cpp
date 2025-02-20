#include <iostream>
#include "raylib.h"
#include "resource_dir.h"
#include "editor_config.h"
#include "components/button.h"
#include "globals.h"

using namespace std;

Font jetBrainsMono;

void btnOnClick();

int main()
{

    EditorConfig editorConfig("./engine.config.yaml");

    string title = editorConfig.getName() + " - v" + editorConfig.getVersion();

    if (editorConfig.isVsync())
    {
        if (editorConfig.isHighDPI())
        {
            SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
        }
        else
        {
            SetConfigFlags(FLAG_VSYNC_HINT);
        }
    }

    InitWindow(editorConfig.getWidth(), editorConfig.getHeight(), title.c_str());
    SearchAndSetResourceDir("resources");

    Image editorIcon = LoadImage(editorConfig.getIcon().c_str());
    SetWindowIcon(editorIcon);

    jetBrainsMono = LoadFont("JetBrainsMono-SemiBold.ttf");
    if (jetBrainsMono.texture.id == 0)
    {
        std::cerr << "Erro ao carregar a fonte!" << std::endl;
        return -1;
    }

    SetTargetFPS(editorConfig.getTargetFPS());

    Button btn;
    btn.setOnClick(btnOnClick);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        btn.draw();

        DrawTextEx(jetBrainsMono, editorConfig.getName().c_str(), {20, 20}, 20, 1, BLACK);
        EndDrawing();
    }

    UnloadFont(jetBrainsMono);
    UnloadImage(editorIcon);
    CloseWindow();

    return 0;
}

void btnOnClick()
{
    std::cout << "Botão clicado!" << std::endl; // Ação a ser executada ao clicar
}