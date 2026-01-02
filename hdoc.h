#pragma once

#include <raylib.h>

#include <stdbool.h>

#define PAGE_WIDTH 480
#define PAGE_HEIGHT 800

#define TODO {}

struct hdoc_State {
        // Available: d (default).
        char fg, bg;

        Vector2 cursor;
        Font font;

        bool _command;
};

struct hdoc_State default_state();
void run_command(struct hdoc_State*, const char*);

char *gorb(const char*);

void render_line(struct hdoc_State*, Image*, const char*);
void render(struct hdoc_State*, Image*, const char*);

Image new_page();

