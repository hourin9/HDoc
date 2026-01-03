#include "hdoc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gorb(const char *inp, const char *terminal)
{
        char *buf = calloc(BUFSIZ, sizeof(*buf));
        size_t c = 0;

        while (inp[c] != '\0') {
                if (inp[c] == '\n')
                        TODO;

                if (strchr(terminal, inp[c]))
                        break;

                // Command, we break.
                if (inp[c] == '$' && inp[c+1] == '$')
                        break;

                buf[c] = inp[c];
                c++;
        }

        return buf;
}

