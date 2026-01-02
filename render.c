#include "hdoc.h"

#include <raylib.h>

#include <stdlib.h>
#include <string.h>

static Vector2 _measure_text(const struct hdoc_State *st, const char *buf)
{
        return MeasureTextEx(st->font, buf, 20.0, 1.0);
}

static void _advance_cursor(struct hdoc_State *st, Vector2 text)
{
        st->cursor.x += text.x;
        if (st->cursor.x > PAGE_WIDTH) {
                st->cursor.y += text.y;
                st->cursor.x = 0.f;
        }
}

void render_line(struct hdoc_State *st, Image *img, const char *buf)
{
        if (img == nullptr
        || buf == nullptr
        || st == nullptr)
                return;

        ImageDrawTextEx(
                img, st->font, buf,
                st->cursor,
                20.0,
                1.0,
                BLACK);

        _advance_cursor(st, _measure_text(st, buf));
}

void render(struct hdoc_State *st, Image *img, const char *buf)
{
        if (img == nullptr
        || buf == nullptr
        || st == nullptr)
                return;

        const char *tmp = buf;
        while (*tmp != '\0') {
                char *line = gorb(tmp);

                tmp += strlen(line);
                if (tmp[0] == '$' && tmp[1] == '$') {
                        tmp += 2;
                        st->_command = true;
                }

                if (!st->_command)
                        render_line(st, img, line);
                else {
                        run_command(st, line);
                        st->_command = false;
                }

                free(line);
        }
}

