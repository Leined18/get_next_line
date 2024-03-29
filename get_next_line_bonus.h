#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# define MAX_FD 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strdup(char const *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *buffer, const char *content);

#endif