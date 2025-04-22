#include "libft.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>

static int read_file(int fd, char **rf)
{
    int n = 1;
    char buf[BUFFER_SIZE + 1] = { 0 };
    char *nx_rf;

    while (n && !(strchr(*rf, '\n')))
    {
        if ((n = read(fd, buf, BUFFER_SIZE)) == 0)
            return n;

        if (n < 0 || n > BUFFER_SIZE)
        {
            free(*rf);

            return n;
        }

        buf[n] = '\0';
        nx_rf = malloc(strlen(*rf) + n + 1);
        strcpy(nx_rf, *rf);
        strcat(nx_rf, buf);
        
        free(*rf);
        *rf = nx_rf;
    }

    return n;
}

static char *next_line(char *rf, char **line, int nbytes)
{
    size_t  i;
    char    *holder;

    i = 0;
    holder = NULL;

    while (rf[i] != '\n' && rf[i] != '\0')
        i++;

    if (rf[i] == '\n')
    {
        *line = substr(rf, 0, i);
        holder = strdup(rf + (i + 1));
    }
    else
        *line = strdup(rf);
    
    free(rf);
    
    if (nbytes != 0)
        if (!holder)
            return NULL;
    
    return holder;
}

/**
 * Read file descriptor fd, and place a line (a string from starting at any char
 * that comes right after the begin of the file or line break, to the next line
 * break or EOF) and puts it on *line buffer.
 *
 * Returns codes of operation. TODO: Doxygen documentation 
 */
int mkr_read_line(int fd, char **line)
{
    static char *rf = NULL;
    int nread = 0;

    if (fd < 1 || fd > RLIMIT_NOFILE)
        return fd;
    if (line == NULL)
        return RD_INVALID_BUF;
    
    if (rf == NULL)
        rf = calloc(1, sizeof (char));

    nread = read_file(fd, &rf);
 
    if (nread < 0)
        return -1;

    rf = next_line(rf, line, nread);

    if (!nread)
        return RD_END;

    return RD_CONTINUE;
}
