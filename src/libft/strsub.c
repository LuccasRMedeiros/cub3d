#include "libft.h"

#include <string.h>
#include <stdlib.h>

char *substr(const char *src, size_t start, size_t end)
{
    char *ret = calloc(end - start + 2, sizeof (char));
    if (!ret)
        return NULL;

    strncpy(ret, src + start, end - start);

    return ret;
}

