#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include "hdoc.h"

int main(int argc, char **argv)
{
        InitWindow(PAGE_WIDTH, PAGE_HEIGHT, "HDocViewer");

        Image canvas = new_page();
        struct hdoc_State state = default_state();

        char help[BUFSIZ];
        sprintf(help, "HDocViewer. Use $$r %s $$b <file>\
                        $$d to render file.", argv[0]);

        if (argc > 1) {
                char *buf = chomp_file(argv[1]);
                render(&state, &canvas, buf);
                free(buf);
        } else
                render(&state, &canvas, help);

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

