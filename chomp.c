#include "hdoc.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static size_t _fsize(FILE *f)
{
        size_t current = ftell(f);

        fseek(f, 0, SEEK_SET);
        fseek(f, 0, SEEK_END);
        size_t size = ftell(f);

        fseek(f, current, SEEK_SET);
        return size;
}

char *chomp_file(const char *path)
{
        FILE *file = fopen(path, "r");
        size_t size = _fsize(file);
        char *buf = calloc(size, sizeof(*buf));
        fread(buf, size, sizeof(*buf), file);
        fclose(file);
        return buf;
}

