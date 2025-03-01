#ifndef _LIBFT_H_
#define _LIBFT_H_

#define BUFFER_SIZE 42

#include <stddef.h>

int	ft_gnl(int fd, char **line);
char	**ft_split(char const *str, char c);
char *substr(const char *src, size_t start, size_t end);

#endif // _LIBFT_H_
