#include "hdoc.h"

#include <stdio.h>
#include <string.h>

void run_command(struct hdoc_State *st, const char *com)
{
        (void)st, (void)com;

        if (strchr(get_color_names(), com[0]))
                st->fg = com[0];

        fprintf(stderr, "run command: %s\n", com);
}

