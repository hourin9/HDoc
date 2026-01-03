#include "hdoc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hdoc_GorbResult gorb(const char *inp, const char *terminal)
{
        char *buf = calloc(BUFSIZ, sizeof(*buf));
        size_t c = 0;
        bool command = false;

        while (inp[c] != '\0') {
                if (strchr(terminal, inp[c]))
                        break;

                // Command, we break.
                if (inp[c] == '$' && inp[c+1] == '$') {
                        command = true;
                        break;
                }

                buf[c] = inp[c];
                c++;
        }

        return (struct hdoc_GorbResult) {
                .str = buf,
                .count = c,
                .command = command,
        };
}

