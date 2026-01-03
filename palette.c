#include "hdoc.h"

#include <ctype.h>

#include <raylib.h>

static Color fg[] = {
        BLACK,
        RED,
        BLUE,
        GREEN,
        YELLOW,
};

static char name[] = {
        'd',
        'r',
        'b',
        'g',
        'y',
};

Color get_palette_color(char ch)
{
        // TODO: make uppercase use background.
        ch = tolower(ch);

        unsigned int col = 0;
        for (col=0; col<sizeof(name); col++)
                if (ch == name[col])
                        break;

        return fg[col];
}

const char *get_color_names()
{
        return name;
}

