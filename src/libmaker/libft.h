#ifndef _LIBFT_H_
#define _LIBFT_H_

#include <stddef.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#define RD_CONTINUE         1
#define RD_END              0
#define RD_INVALID_FD(fd)   #fd
#define RD_INVALID_BUF      -1

int	mkr_read_line(int fd, char **line);
char **ft_split(char const *str, char c);
char *substr(const char *src, size_t start, size_t end);

#endif // _LIBFT_H_
