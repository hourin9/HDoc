#include "hdoc.h"

#include <raylib.h>

struct hdoc_State default_state()
{
        return (struct hdoc_State) {
                .bg = 'd',
                .fg = 'd',
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

