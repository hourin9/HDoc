#include "hdoc.h"

#include <raylib.h>

struct hdoc_State default_state()
{
        return (struct hdoc_State) {
                .bg = 'd',
                .fg = 'd',
        };
}

Image make_abundant_canvas()
{
        Image image = GenImageColor(800, 1920, WHITE);
        return image;
}

Image trim_canvas(Image img)
{
        // TODO: make this actually useful
        return ImageCopy(img);
}

