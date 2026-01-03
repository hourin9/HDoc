#pragma once

#include <stdbool.h>
#include <stddef.h>

#include <raylib.h>

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

struct hdoc_GorbResult {
        size_t count;
        bool command;
        char *str;
};

struct hdoc_GorbResult gorb(const char*, const char *terminal);

void render_line(struct hdoc_State*, Image*, const char*);
void render(struct hdoc_State*, Image*, const char*);

Image new_page();

Color get_palette_color(char);

