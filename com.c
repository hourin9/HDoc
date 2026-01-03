#include "hdoc.h"

#include <stdio.h>
#include <string.h>

void run_command(struct hdoc_State *st, const char *com)
{
        (void)st, (void)com;

        if (strchr(get_color_names(), com[0]))
                st->fg = com[0];

        if (com[0] == 'h') {
                int a = com[1] - '0';
                if (a > 0 && a < MAX_HLEVEL)
                        st->level = a;
        }

        fprintf(stderr, "run command: %s\n", com);
}

