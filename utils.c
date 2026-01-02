#include "hdoc.h"

#include <raylib.h>

struct hdoc_State default_state()
{
        return (struct hdoc_State) {
                .bg = 'd',
                .fg = 'd',
                .font = GetFontDefault(),
                .cursor = (Vector2){0.f, 0.f},
        };
}

Image new_page()
{
        Image image = GenImageColor(
                PAGE_WIDTH,
                PAGE_HEIGHT,
                WHITE);
        return image;
}

