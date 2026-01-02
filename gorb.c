#include "hdoc.h"

#include <stdio.h>
#include <stdlib.h>

char *gorb(const char *inp)
{
        char *buf = calloc(BUFSIZ, sizeof(*buf));
        size_t c = 0;

        while (inp[c] != '\0') {
                if (inp[c] == '\n')
                        TODO

                // Command, we break.
                if (inp[c] == '$' && inp[c+1] == '$')
                        break;

                buf[c] = inp[c];
                c++;
        }

        return buf;
}

