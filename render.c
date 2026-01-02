#include "hdoc.h"

#include <raylib.h>

void render_line(struct hdoc_State *st, Image *img, const char *buf)
{
        if (img == nullptr
        || buf == nullptr
        || st == nullptr)
                return;

        ImageDrawText(img, buf, 0, 0, 20, BLACK);
}

