#include "hdoc.h"

#include <raylib.h>

Image make_abundant_canvas()
{
        Image image = GenImageColor(800, 99999, WHITE);
        return image;
}

Image trim_canvas(Image img)
{
        // TODO: make this actually useful
        return ImageCopy(img);
}

