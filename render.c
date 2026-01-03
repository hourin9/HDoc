#include "hdoc.h"

#include <raylib.h>

#include <stdlib.h>
#include <string.h>

static const float _FONT_SIZE[MAX_HLEVEL] = {
        18.f,
        30.f,
        26.f,
        24.f,
        22.f,
        20.f,
};

static Vector2 _measure_text(const struct hdoc_State *st, const char *buf)
{
        return MeasureTextEx(st->font, buf, _FONT_SIZE[st->level], 0.0);
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
                _FONT_SIZE[st->level],
                0.0,
                get_palette_color(st->fg));

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
                struct hdoc_GorbResult line = gorb(tmp, "\n\0");

                tmp += line.count;

                if (line.command) {
                        tmp += 2;
                        goto render;
continue_command:
                        line = gorb(tmp, " ");
                        // Consoom the whitespace.
                        tmp += line.count + 1;
                        run_command(st, line.str);
                        free(line.str);
                        goto loop_end;
                }

render:
                render_line(st, img, line.str);
                free(line.str);

                if (line.command)
                        goto continue_command;
loop_end:

                if (*tmp == '\n') {
                        tmp += 1;
                        st->level = 0;
                }

        }
}

