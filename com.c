#include "hdoc.h"

#include <stdio.h>

void run_command(struct hdoc_State *st, const char *com)
{
        (void)st, (void)com;
        fprintf(stderr, "run command: %s\n", com);
}

