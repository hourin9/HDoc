#pragma once

#include <raylib.h>

#define PAGE_WIDTH 480
#define PAGE_HEIGHT 800

struct hdoc_State {
        // Available: d (default).
        char fg, bg;

        Vector2 cursor;
        Font font;
};

struct hdoc_State default_state();

void render_line(struct hdoc_State*, Image*, const char*);

Image new_page();

