/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/15 18:06:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>

static int  read_file(int fd, char **rf)
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

            return (n);
        }

        buf[n] = '\0';
        nx_rf = malloc(strlen(*rf) + n + 1);
        strcpy(nx_rf, *rf);
        strcat(nx_rf, buf);
        
        free(*rf);
        *rf = nx_rf;
    }
    return (n);
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
            return (NULL);
    return (holder);
}

static int  error_catcher(int fd, char **line, char **rf)
{
    int nread;

    if (fd < 0 || fd > RLIMIT_NOFILE)
        return (-1);
    else if (!line)
        return (-1);
    else if (BUFFER_SIZE <= 0)
        return (-1);
    
    if (*rf == NULL)
        *rf = calloc(1, sizeof (char));

    nread = read_file(fd, rf);
    return (nread);
}

int ft_gnl(int fd, char **line)
{
    static char *rf = NULL;
    int nread = 0;

    nread = error_catcher(fd, line, &rf);
    if (nread < 0)
        return (-1);
    rf = next_line(rf, line, nread);
    if (!nread)
        return (0);
    return (1);
}
