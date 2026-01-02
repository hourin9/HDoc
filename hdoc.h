#pragma once

#include <raylib.h>

struct hdoc_State {
        // Available: d (default).
        char fg, bg;
};

struct hdoc_State default_state();

void render_line(struct hdoc_State*, Image*, const char*);

Image make_abundant_canvas();
Image trim_canvas(Image);

