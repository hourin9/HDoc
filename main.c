#include "hdoc.h"
#include <raylib.h>

int main(void)
{
        InitWindow(PAGE_WIDTH, PAGE_HEIGHT, "HDocViewer");

        Image canvas = new_page();
        struct hdoc_State state = default_state();
        render_line(&state, &canvas, "test");

        Texture render = LoadTextureFromImage(canvas);
        UnloadImage(canvas);

        while (!WindowShouldClose()) {
                BeginDrawing();
                DrawTexture(render, 0, 0, WHITE);
                EndDrawing();
        }

        UnloadTexture(render);
        CloseWindow();
        return 0;
}

